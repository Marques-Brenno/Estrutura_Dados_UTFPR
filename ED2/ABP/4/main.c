#include <stdio.h>
#include <stdlib.h>

typedef struct TNoABP{
    int chave;
    struct TNoABP *esq, *dir;

}TNoABP;

int veriFolha(TNoABP *p){
    if(!p)
        return 0;
    if((p->esq == NULL) &&(p->dir == NULL))
        return 1;
    return 0;
}

TNoABP* alocaNO(int k){
    TNoABP *novo = malloc(sizeof(TNoABP));
    novo->chave = k;
    novo->esq = novo->dir = NULL;
    return novo;
}

TNoABP* insere(TNoABP **raiz, int k){
    if(!*raiz){
        *raiz = alocaNO(k);
        return *raiz;
    }
    if(k < (*raiz)->chave)
        return insere(&((*raiz)->esq), k);
    else
        return insere(&((*raiz)->dir), k);
}

TNoABP* busca(TNoABP *raiz, int k){
    if(!raiz)
        return NULL;
    if(raiz->chave == k)
        return raiz;
    if(k < raiz->chave)
        return busca(raiz->esq, k);
    else
        return busca(raiz->dir, k);
}


void emOrdem(TNoABP *raiz){
    if(!raiz)
        return;

    emOrdem(raiz->esq);
    printf("%d \n", raiz->chave);
    emOrdem(raiz->dir);
}

int main()
{
    TNoABP *raiz = NULL;

    printf("A inserir elementos na arvore...\n");
    insere(&raiz, 90);
    insere(&raiz, 10);
    insere(&raiz, 70);
    insere(&raiz, 14);
    insere(&raiz, 200);
    insere(&raiz, 12);
    insere(&raiz, 75);
    insere(&raiz, 44);
    insere(&raiz, 96);

    printf("Elementos da ABP em ordem: ");
    emOrdem(raiz);
    printf("\n\n");

    int chaveBusca1 = 70;
    TNoABP *noAchado1 = busca(raiz, chaveBusca1);

    if (noAchado1) {
        printf("No %d encontrado! ", chaveBusca1);
        if (veriFolha(noAchado1)) {
            printf("E e um no FOLHA.\n");
        } else {
            printf("Mas NAO e um no folha (ele tem filhos).\n");
        }
    }

    int chaveBusca2 = 12;
    TNoABP *noAchado2 = busca(raiz, chaveBusca2);

    if (noAchado2) {
        printf("No %d encontrado! ", chaveBusca2);
        if (veriFolha(noAchado2)) {
            printf("E e um no FOLHA.\n");
        } else {
            printf("Mas NAO e um no folha.\n");
        }
    }

    int chaveBusca3 = 999;
    if (!busca(raiz, chaveBusca3)) {
        printf("No %d nao encontrado!\n", chaveBusca3);
    }
    return 0;
}
