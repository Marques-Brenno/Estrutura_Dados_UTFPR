#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int chave;
    struct node *esq, *dir;
}node;

node* criaNo(int k){
    node *novo = (node *)malloc(sizeof(node));
    novo->chave = k;
    novo->dir = novo->esq = NULL;
    return novo;
}

void addNo(node **p, int k){
    if((*p) == NULL){
        *p = criaNo(k);
    }
    else if(k < (*p)->chave){
        addNo(&(*p)->esq, k);
    }
    else{
        addNo(&(*p)->dir, k);
    }
}
//1b
node* busca(node *r, int k){
    if(r == NULL || (r->chave) == k)
        return r;
    if(k < (r->chave))
        return busca(r->esq, k);
    else
        return busca(r->dir, k);
}

int main()
{
    node *raiz = NULL;
    node **r = &raiz;
    node *resul = NULL;
    addNo(&raiz, 7);
    addNo(&raiz, 5);
    addNo(&raiz, 2);
    addNo(&raiz, 6);
    addNo(&raiz, 9);
    addNo(&raiz, 8);

    //1b
    printf("Endereco do no raiz 7 usando a variavel raiz\n");
    printf("Endereco de memoria do no de chave 7: %p\n", raiz);
    printf("Endereco de memoria da variavel raiz: %p\n", &raiz);
    printf("\n--------------------------------------------------------------------------------------\n\n");


    //1c
    printf("Endereco do no raiz 7 usando a variavel r\n");
    printf("Endereco de memoria do no de chave 7: %p\n", *r);
    printf("Endereco de memoria da variavel raiz: %p\n", r);
    printf("\n--------------------------------------------------------------------------------------\n\n");


    //1d
    printf("Valor-chave no raiz 7 duas vezes usando r e raiz\n");
    printf("valor-chave do no raiz 7 usando o r: %i\n", (*r)->chave);
    printf("valor-chave do no raiz 7 usando o raiz: %i\n", raiz->chave);
    printf("\n--------------------------------------------------------------------------------------\n\n");


    //1e
    printf("valor campo esq e endereco do campo dir do no raiz 7 usando raiz\n");
    printf("valor campo esq do no raiz 7: %p\n", raiz->esq);
    printf("Endereco de memoria do campo dir do no raiz 7: %p\n", &(raiz->dir));
    printf("\n--------------------------------------------------------------------------------------\n\n");


    //1f
    printf("valor campo esq e endereco do campo dir do no raiz 7 usando r\n");
    printf("valor campo esq do no raiz 7: %p\n", (*r)->esq);
    printf("Endereco de memoria do campo dir do no raiz 7: %p\n", &((*r)->dir));
    printf("\n--------------------------------------------------------------------------------------\n\n");


    //1g
    printf("remocao do no de chave 8 usando a varialvel raiz\n");
    free((raiz->dir)->esq);
    (raiz->dir)->esq = NULL;
    printf("\n--------------------------------------------------------------------------------------\n\n");

    addNo(&raiz, 8);

    //1h
    printf("remocao do no de chave 8 usando a varialvel r\n");
    free(((*r)->dir)->esq);
    ((*r)->dir)->esq = NULL;
    printf("\n--------------------------------------------------------------------------------------\n\n");


    return 0;
}
