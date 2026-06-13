#include <stdio.h>
#include <stdlib.h>

typedef struct TNoABP{
    int chave;
    struct TNoABP *esq, *dir;

}TNoABP;

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

TNoABP* menorChave(TNoABP *raiz){
    if(!raiz)
        return NULL;

    if(raiz->esq == NULL)
        return raiz;

    return menorChave(raiz->esq);
}

TNoABP *removerMenor(TNoABP **raiz){
    if(!(*raiz)){
        printf("A arvore esta vazia");
        return NULL;
    }
    if(!(*raiz)->esq){
        TNoABP *aux = *raiz;

        *raiz = (*raiz)->dir;

        free(aux);
        aux = NULL;
    }
    else{
        removerMenor(&((*raiz)->esq));
    }

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

    printf("Elementos da ABP em ordem: \n");
    emOrdem(raiz);
    TNoABP *menor = menorChave(raiz);
    printf("\n\n");


    printf("menor = %d \n", menor->chave);

    removerMenor(&raiz);

    printf("menor removido \n");
    emOrdem(raiz);

    return 0;
}
