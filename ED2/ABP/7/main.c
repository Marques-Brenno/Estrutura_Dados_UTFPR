#include <stdio.h>
#include <stdlib.h>

typedef struct TNo {
    int chave;
    struct TNo *esq, *dir;
} TNo;

TNo* alocaNO(int k) {
    TNo *novo = (TNo*)malloc(sizeof(TNo));
    if (novo) {
        novo->chave = k;
        novo->esq = novo->dir = NULL;
    }
    return novo;
}

TNo* busca(TNo *raiz, int k){
    if(!raiz)
        return NULL;
    if(raiz->chave == k)
        return raiz;

    TNo *achou = busca(raiz->esq, k);
    if(achou != NULL)
        return achou;

    return busca(raiz->dir, k);

}




int main() {
    // Montando uma Árvore Binária QUALQUER (Não é de pesquisa)
    //        10
    //       /  \
    //     50    5
    //    /  \    \
    //  99   12   42

    TNo *raiz = alocaNO(10);
    raiz->esq = alocaNO(50);
    raiz->dir = alocaNO(5);

    raiz->esq->esq = alocaNO(99);
    raiz->esq->dir = alocaNO(12);

    raiz->dir->dir = alocaNO(42);

    TNo *achou = busca(raiz, 12);

    printf("busca de elemento existente\n");

    if(!achou){
        printf("Elmento nao encontrado\n");
    }
    else{
        printf("Elemento %d encontrado, no endereco %p\n", achou->chave, achou);
    }



    printf("busca de elemento nao existente\n");
    achou = busca(raiz, 2);

    if(!achou){
        printf("Elmento nao encontrado\n");
    }
    else{
        printf("Elemento %d encontrado, no endereco %p\n", achou->chave, achou);
    }



    return 0;
}
