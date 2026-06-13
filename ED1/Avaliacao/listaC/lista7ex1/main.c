#include <stdio.h>
#include <stdlib.h>

typedef struct no{
    int chave;
    struct no *ant;
    struct no *prox;
}no;

no *alocaNO(int k);
void criarNO(no **cabeca, int k);
void remover(no **cabeca);
void inserirESQ(no **cabeca);
void inserirDRT(no *cabeca);
void exibir(no *cabeca);

int main()
{
    no *cabeca = NULL;
    
    criarNO(&cabeca, 1);
    criarNO(&cabeca, 2);
    criarNO(&cabeca, 3);
    criarNO(&cabeca, 4);

    exibir(cabeca);

    printf("\n--------------------------------------------------");
    printf("\nRemover");

    remover(&cabeca);

    exibir(cabeca);

    printf("\n--------------------------------------------------");
    printf("\nEsquerda");

    inserirESQ(&cabeca);

    exibir(cabeca);


    printf("\n--------------------------------------------------");
    printf("\nDireita");

    inserirDRT(cabeca);

    exibir(cabeca);

    

    while (cabeca != NULL)
    {
        remover(&cabeca);
    }
    cabeca = NULL;
    return 0;
}

no *alocaNO(int k){
    no *novo = (no *)malloc(sizeof(no));
    if (novo)
    {
        novo->chave = k;
        novo->ant = NULL;
        novo->prox = NULL;
        return novo;
    }
    return NULL; 
}

void criarNO(no **cabeca, int k){
    no *novo = alocaNO(k);
    if(!novo) return;

    if(*cabeca == NULL){
        *cabeca = novo;
    }
    else{
        novo->prox = *cabeca;
        (*cabeca)->ant = novo;
        *cabeca = novo;
    }
}


void remover(no **cabeca){
    no *aux = *cabeca;

    *cabeca = aux->prox;

    (*cabeca)->ant = NULL;

    free(aux);
    aux = NULL;
}

void inserirESQ(no **cabeca){
    int k, chave;
    no *aux = *cabeca;
    printf("\nDigite a a chave do item: ");
    scanf("%d", &k);

    printf("\nDigite em qual local deseja adicionar: ");
    scanf("%d", &chave);

    while (aux != NULL)
    {
        if(aux->chave == chave){
            no *novo = alocaNO(k);
            novo->prox = aux;
            novo->ant = aux->ant;
            if(novo->ant){
                (novo->ant)->prox = novo;
            }
            else
            {
                *cabeca = novo;
            }
            
            aux->ant = novo;
            return;
        }

        aux = aux->prox;
    }
    printf("\nChave nao encontrada\n");
}

void inserirDRT(no *cabeca){
    int k, chave;
    no *aux = cabeca;
    printf("\nDigite a a chave do item: ");
    scanf("%d", &k);

    printf("\nDigite em qual local deseja adicionar: ");
    scanf("%d", &chave);

    while (aux != NULL)
    {
        if(aux->chave == chave){
            no *novo = alocaNO(k);
            novo->ant = aux;
            novo->prox = aux->prox;
            if(novo->prox){
                (novo->prox)->ant = novo;
            }
            aux->prox = novo;
            return;
        }

        aux = aux->prox;
    }
}


void exibir(no *cabeca){
    no *aux = cabeca;

    while (aux != NULL)
    {
        printf("\n%d", aux->chave);

        aux = aux->prox;
    }
    
}