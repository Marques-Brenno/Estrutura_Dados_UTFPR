#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função para limpar o buffer de entrada (essencial após scanf)
void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Função para criar uma cópia dinâmica de uma string
char *strcopy(char *str){
    // CORREÇÃO: strlen espera o ponteiro (str), não o valor (*str)
    int tam = strlen(str);

    // CORREÇÃO: A variável se chama 'tam', não 'tamanho'
    char *copia = (char *) malloc((tam + 1) * sizeof(char));

    // É bom verificar se a alocação funcionou
    if (copia == NULL) {
        return NULL;
    }

    // CORREÇÃO: strcpy espera ponteiros (copia e str)
    strcpy(copia, str);

    return copia;
}

// Função para desalocar a memória e anular o ponteiro
void desalca(char **p){
    free(*p);

    // CORREÇÃO: Usa '=' para atribuição, não '==' para comparação
    *p = NULL;
}

int main()
{
    int tam;

    printf("Digite o tamanho maximo da string: ");
    scanf("%i", &tam);
    limpar_buffer(); // Limpa o '\n' deixado pelo scanf

    char string[tam];
    char *copia = NULL;

    printf("Digite a string: ");
    // CORREÇÃO: fgets espera o ponteiro (string)
    fgets(string, tam, stdin);

    // Remove o '\n' que o fgets captura, se houver
    string[strcspn(string, "\n")] = 0;

    // Chama a função para criar a cópia
    copia = strcopy(string);

    if (copia != NULL) {
        printf("\nString copiada: %s\n", copia); // CORREÇÃO: printf %s espera o ponteiro (copia)

        // Libera a memória alocada para a cópia
        desalca(&copia);

        printf("Memoria liberada. Ponteiro copia agora e: %p\n", copia);
    }

    return 0;
}
