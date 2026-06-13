#include <stdio.h>
#include <stdlib.h>

typedef struct  no{
    int chave;
    struct no *prox;
}no;

void criarNO(no **cabeca, int k);
no *alocarNO(int k);

void exibir(no *cabeca);

void remover(no **cabeca);

void buscar(no *cabeca, int k);

void rotacionarESQ(no **cabeca);

void rotacionarDRT(no **cabeca);

int main()
{
    no *cabeca = NULL;
    criarNO(&cabeca, 1);
    criarNO(&cabeca, 2);
    criarNO(&cabeca, 3);
    criarNO(&cabeca, 4);

    exibir(cabeca);
    
    printf("\n---------------------------------------------");
    printf("\nremover");

    remover(&cabeca);
    remover(&cabeca);

    exibir(cabeca);

    printf("\n---------------------------------------------");
    printf("\nBusca");

    buscar(cabeca, 1);
    buscar(cabeca, 4);

    
    printf("\n---------------------------------------------");
    printf("\nesquerda");

    criarNO(&cabeca, 3);
    criarNO(&cabeca, 4);

    rotacionarESQ(&cabeca);

    exibir(cabeca);

    printf("\n---------------------------------------------");
    printf("\nDireita");
    
    rotacionarDRT(&cabeca);

    exibir(cabeca);

    while (cabeca != NULL)
    {
        remover(&cabeca);
    }

    printf("\n%p", cabeca);
    
    return 0;
}

no *alocarNO(int k){
    no *novo = (no *)malloc(sizeof(no));
    if (novo)
    {
        novo->chave = k;
        novo->prox = NULL;
        return novo;
    }
    
    return NULL;
}

void criarNO(no **cabeca, int k){
    no *novo = alocarNO(k);

    if(*cabeca == NULL){
        novo->prox = novo;
        *cabeca = novo;
    }
    else{
        novo->prox = (*cabeca)->prox;
        (*cabeca)->prox = novo;
    }
}


void exibir(no *cabeca){

    if(cabeca){
            no *aux = cabeca->prox;

        do{
            
            printf("\n%d", aux->chave);

            aux = aux->prox;
        } while (aux != cabeca->prox);
    }
    else
    {
        printf("\nLista vazia");
    }
}

void remover(no **cabeca){
    no *aux = (*cabeca)->prox;

    (*cabeca)->prox = aux->prox;

    if ((*cabeca)->prox == *cabeca){
        *cabeca = NULL;
    }

    free(aux);

    
    
}

void buscar(no *cabeca, int k){
    if(cabeca){
            no *aux = cabeca->prox;
            int ct = 0;

        do{
            if (aux->chave == k)
            {
                printf("\n%d", aux->chave);
                printf("\n%p", aux);
                ct++;
            }
            
            aux = aux->prox;
        } while (aux != cabeca->prox);

        if (ct == 0)
        {
            printf("\nConteudo nao encontrado");
        }
        
    }
    else
    {
        printf("\nLista vazia");
    }
}

void rotacionarESQ(no **cabeca){
    no *aux = *cabeca;
    *cabeca = aux->prox; 
}

void rotacionarDRT(no **cabeca){
    no *aux = *cabeca;

    while (aux->prox != *cabeca)
    {
        aux = aux->prox;
    }

    *cabeca = aux;
    
}