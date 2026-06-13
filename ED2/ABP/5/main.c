#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct TNoABP {
    int chave;
    struct TNoABP *esq, *dir;
} TNoABP;

TNoABP* alocaNO(int k) {
    TNoABP *novo = (TNoABP*)malloc(sizeof(TNoABP));
    if (novo) {
        novo->chave = k;
        novo->esq = novo->dir = NULL;
    }
    return novo;
}

int insere(TNoABP **raiz, int k, int nivel_atual, int *max_h) {
    if (*raiz == NULL) {
        *raiz = alocaNO(k);
        if (nivel_atual > *max_h) {
            *max_h = nivel_atual;
        }
        return 1;
    }

    if (k < (*raiz)->chave) {
        return insere(&((*raiz)->esq), k, nivel_atual + 1, max_h);
    }
    else if (k > (*raiz)->chave) {
        return insere(&((*raiz)->dir), k, nivel_atual + 1, max_h);
    }

    return 0;
}

int main() {
    TNoABP *raiz = NULL;
    int altura_maxima = -1;
    int total_nos = 0;
    const int TOTAL_INSERCOES = 1000000;

    FILE *arq = fopen("dados_arvore.txt", "w");
    if (!arq) {
        printf("Erro ao criar o ficheiro!\n");
        return 1;
    }

    srand(time(NULL));

    printf("A gerar %d de chaves unicas e a gravar no ficheiro...\n", TOTAL_INSERCOES);

    while (total_nos < TOTAL_INSERCOES) {
        int chave = (rand() << 15) | rand();

        if (insere(&raiz, chave, 0, &altura_maxima)) {
            total_nos++;

            fprintf(arq, "%d %d %d\n", total_nos, altura_maxima, chave);

            if (total_nos % 100000 == 0) {
                printf("%d nos unicos inseridos...\n", total_nos);
            }
        }
    }

    fclose(arq);
    printf("Concluido! O ficheiro 'dados_arvore.txt' foi gerado com sucesso.\n");

    return 0;
}
