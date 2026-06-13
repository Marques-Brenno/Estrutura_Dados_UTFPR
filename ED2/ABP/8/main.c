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


void PreencherEmOrdem(TNoABP *raiz, int *vetor, int *i){
    if(!raiz)
        return;

    PreencherEmOrdem(raiz->esq, vetor, i);
    vetor[*i] = raiz->chave;
    (*i)++;



    PreencherEmOrdem(raiz->dir, vetor, i);
}

void EmOrdem(TNoABP *raiz){
    if(!raiz)
        return;

    EmOrdem(raiz->esq);
    printf("%d\n", raiz->chave);
    EmOrdem(raiz->dir);
}

TNoABP *libera(TNoABP **raiz){
    if(*raiz != NULL){
        libera(&((*raiz)->esq));
        libera(&((*raiz)->dir));
        free(*raiz);
        *raiz = NULL;
    }
}

int main()
{
    int v[] = {5,7,2,3,1,9};
    int t = 6;
    int i = 0;

    TNoABP *raiz = NULL;

    printf("vetor original\n");
    for(int j = 0; j < t; j++){
        printf("%d\n", v[j]);
        insere(&raiz, v[j]);
    }

    PreencherEmOrdem(raiz, v, &i);



    printf("vetor ordenado\n");
    for(int j = 0; j < t; j++){
        printf("%d\n", v[j]);
    }

    libera(&raiz);
    EmOrdem(raiz);
    printf("raiz - %d\n", raiz);
    return 0;
}
