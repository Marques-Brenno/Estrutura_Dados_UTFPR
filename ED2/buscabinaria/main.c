#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int chave;
    struct node *esq, *dir;
}node;

node* busca(node *r, int k){
    if(r == NULL || (r->chave) == k)
        return r;
    if(k < (r->chave))
        return busca(r->esq, k);
    else
        return busca(r->dir, k);
}

node* criaNo(int k){
    node *novo = (node *)malloc(sizeof(node));
    if(!novo)
        return NULL;
    novo->chave = k;
    novo->esq = novo->dir = NULL;
    return novo;
}

void addNum(node **r, int k){
    if(!(*r)){
        *r = criaNo(k);
        if(!(*r))
        return;
    }
    else if(k < (*r)->chave)
        addNum(&(*r)->esq, k);
    else
        addNum(&(*r)->dir, k);
}

node* buscaPP(node **r, int k){
    if(!(*r))
        return NULL;
    if((*r)->chave == k)
        return r;
    if(k < (*r)->chave)
        buscaPP(&(*r)->esq, k);
    else{
        buscaPP(&(*r)->dir, k);
    }
}

void remover(node **r, int k){
    if(!r)
        return;
    if(!(*r))
        return;

    node **aux = buscaPP(r, k);
    if(!(*aux))
        return;

    if((*aux)->dir == NULL && (*aux)->dir == NULL){
        free(*aux);
        *aux = NULL;
    }

    if( ( (*aux)->dir == NULL) != ( (*aux)->esq == NULL)){
        node *aux2 = ((*aux)->esq == NULL) ? (*aux)->dir : (*aux)->esq;
        free(*aux);
        *aux = aux2;
        return;

    }

}

int main()
{

    node *raiz = NULL;
    addNum(&raiz, 50);
    addNum(&raiz, 75);
    addNum(&raiz, 15);
    addNum(&raiz, 12);
    addNum(&raiz, 18);
    addNum(&raiz, 89);
    addNum(&raiz, 40);
    node *resultado = busca(raiz, 40);
    if (resultado != NULL) {
        printf("Elemento encontrado: %d\n", resultado->chave);
        printf("Endereco do elemento: %p\n", resultado);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    remover(&raiz, 40);
    resultado = busca(raiz, 40);
    if (resultado != NULL) {
        printf("Elemento encontrado: %d\n", resultado->chave);
        printf("Endereco do elemento: %p\n", resultado);
    } else {
        printf("Elemento nao encontrado.\n");
    }

    return 0;
}
