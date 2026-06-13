#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <time.h>
#include <ctype.h>

// Estrutura de dados que será passada para cada thread
typedef struct {
    int thread_id;
    int inicio_linha;
    int fim_linha;
    int largura;
    int altura;
    int **matriz_in;
    int **matriz_out;
} DadosThread;

// Função auxiliar para ignorar comentários no arquivo PGM
void ignorar_comentarios(FILE *f) {
    int ch;
    while ((ch = fgetc(f)) != EOF) {
        if (ch == '#') {
            // Se achar um comentário, lê até o fim da linha
            while ((ch = fgetc(f)) != '\n' && ch != EOF);
        } else if (!isspace(ch)) {
            // Se não for espaço em branco nem comentário, devolve o caractere e para
            ungetc(ch, f);
            break;
        }
    }
}

// Alocação dinâmica de matriz de forma contígua (melhora o uso da memória cache)
int** alocar_matriz(int linhas, int colunas) {
    int **matriz = (int **)malloc(linhas * sizeof(int *));
    int *dados = (int *)malloc(linhas * colunas * sizeof(int));
    for (int i = 0; i < linhas; i++) {
        matriz[i] = &dados[i * colunas];
    }
    return matriz;
}

// Liberação da matriz contígua
void liberar_matriz(int **matriz) {
    free(matriz[0]);
    free(matriz);
}

// Função que cada Thread irá executar
void* filtrar_faixa(void* arg) {
    DadosThread* dados = (DadosThread*) arg;
    int raio = 7; // Raio para uma máscara 15x15 (7 para cada lado + o centro)

    // Cada thread processa apenas da sua 'inicio_linha' até 'fim_linha'
    for (int i = dados->inicio_linha; i < dados->fim_linha; i++) {
        for (int j = 0; j < dados->largura; j++) {

            // Tratamento de Borda: Se estiver nas primeiras ou últimas 7 linhas/colunas
            if (i < raio || i >= dados->altura - raio || j < raio || j >= dados->largura - raio) {
                dados->matriz_out[i][j] = 0; // Ignora atribuindo valor zero
                continue;
            }

            int soma = 0;

            // Aplicação da Máscara Laplaciana 15x15
            for (int mi = -raio; mi <= raio; mi++) {
                for (int mj = -raio; mj <= raio; mj++) {
                    int peso = -1;
                    if (mi == 0 && mj == 0) {
                        peso = 224; // Centro da máscara (15*15 - 1 = 224)
                    }
                    soma += dados->matriz_in[i + mi][j + mj] * peso;
                }
            }

            // Saturação (Clipping)
            if (soma < 0)   soma = 0;
            if (soma > 255) soma = 255;

            // Grava o resultado na matriz de saída (Não-destrutivo)
            dados->matriz_out[i][j] = soma;
        }
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    // Verifica se os parâmetros de linha de comando foram passados corretamente
    if (argc != 4) {
        printf("Uso correto: %s <imagem_entrada.pgm> <imagem_saida.pgm> <num_threads>\n", argv[0]);
        return 1;
    }

    char *arq_entrada = argv[1];
    char *arq_saida = argv[2];
    int num_threads = atoi(argv[3]);

    if (num_threads < 1) {
        printf("O número de threads deve ser pelo menos 1.\n");
        return 1;
    }

    // --- LEITURA DA IMAGEM PGM ---
    FILE *f_in = fopen(arq_entrada, "r");
    if (!f_in) {
        printf("Erro ao abrir o arquivo de entrada: %s\n", arq_entrada);
        return 1;
    }

    char tipo[3];
    if (fscanf(f_in, "%2s", tipo) != 1 || tipo[0] != 'P' || tipo[1] != '2') {
        printf("Erro: A imagem precisa ser do tipo PGM P2 (Escala de cinza em texto).\n");
        fclose(f_in);
        return 1;
    }

    int largura, altura, max_val;
    ignorar_comentarios(f_in);
    fscanf(f_in, "%d", &largura);
    ignorar_comentarios(f_in);
    fscanf(f_in, "%d", &altura);
    ignorar_comentarios(f_in);
    fscanf(f_in, "%d", &max_val);

    // Alocação das duas matrizes exigidas (Entrada e Saída separadas)
    int **matriz_input = alocar_matriz(altura, largura);
    int **matriz_output = alocar_matriz(altura, largura);

    // Lendo os pixels do arquivo texto para a matriz de entrada
    for (int i = 0; i < altura; i++) {
        for (int j = 0; j < largura; j++) {
            fscanf(f_in, "%d", &matriz_input[i][j]);
        }
    }
    fclose(f_in);

    // --- PREPARAÇÃO DO PARALELISMO (DECOMPOSIÇÃO POR FAIXAS) ---
    pthread_t *threads = (pthread_t *)malloc(num_threads * sizeof(pthread_t));
    DadosThread *dados = (DadosThread *)malloc(num_threads * sizeof(DadosThread));

    int linhas_por_thread = altura / num_threads;

    for (int i = 0; i < num_threads; i++) {
        dados[i].thread_id = i;
        dados[i].largura = largura;
        dados[i].altura = altura;
        dados[i].matriz_in = matriz_input;
        dados[i].matriz_out = matriz_output;

        // Define a faixa de linhas que esta thread vai cuidar
        dados[i].inicio_linha = i * linhas_por_thread;
        if (i == num_threads - 1) {
            dados[i].fim_linha = altura; // A última thread absorve qualquer resto de divisão
        } else {
            dados[i].fim_linha = (i + 1) * linhas_por_thread;
        }
    }

    // --- MEDIÇÃO DE TEMPO CRÍTICO E CRIAÇÃO DAS THREADS ---
    struct timespec inicio, fim;

    // Inicia o cronômetro EXATAMENTE antes de disparar o cálculo paralelo
    clock_gettime(CLOCK_MONOTONIC, &inicio);

    // Despacha as threads
    for (int i = 0; i < num_threads; i++) {
        pthread_create(&threads[i], NULL, filtrar_faixa, &dados[i]);
    }

    // Aguarda todas as threads concluírem
    for (int i = 0; i < num_threads; i++) {
        pthread_join(threads[i], NULL);
    }

    // Para o cronômetro imediatamente após a última thread terminar
    clock_gettime(CLOCK_MONOTONIC, &fim);

    // Calcula o tempo decorrido
    double tempo_gasto = (fim.tv_sec - inicio.tv_sec) + (fim.tv_nsec - inicio.tv_nsec) / 1e9;
    printf("Tempo estrito de filtragem (%d threads): %f segundos\n", num_threads, tempo_gasto);

    // --- ESCRITA DA IMAGEM GERADA ---
    FILE *f_out = fopen(arq_saida, "w");
    if (!f_out) {
        printf("Erro ao criar o arquivo de saída.\n");
    } else {
        fprintf(f_out, "P2\n");
        fprintf(f_out, "# Filtrado com Filtro Laplaciano 15x15 Concorrente\n");
        fprintf(f_out, "%d %d\n", largura, altura);
        fprintf(f_out, "%d\n", max_val);

        for (int i = 0; i < altura; i++) {
            for (int j = 0; j < largura; j++) {
                fprintf(f_out, "%d ", matriz_output[i][j]);
            }
            fprintf(f_out, "\n");
        }
        fclose(f_out);
    }

    // --- LIBERAÇÃO DE MEMÓRIA ---
    liberar_matriz(matriz_input);
    liberar_matriz(matriz_output);
    free(threads);
    free(dados);

    return 0;
}
