#include <stdio.h>
#include <stdlib.h>

typedef struct ABP{
    int chave;
    struct ABP *dir, *esq;
}ABP;

ABP* alocaNO(int k){
    ABP *novo = malloc(sizeof(ABP));
    novo->chave = k;
    novo->dir = novo->esq = NULL;
    return novo;
}

ABP* adiciona(ABP **p, int k){

    if(*p == NULL){
        (*p) = alocaNO(k);
        return  *p;
    }
    else if(k < (*p)->chave){
        return adiciona(&((*p)->esq),k);
    }
    else{
        return adiciona(&((*p)->dir), k);
    }

    return NULL;
}

ABP** busca(ABP **p, int k){
    if(*p == NULL){
        return NULL;
    }

    else if((*p)->chave == k){
        return p;
    }
    else if(k < (*p)->chave){
        return busca(&((*p))->esq, k);
    }
    else{
        return busca(&((*p))->dir, k);
    }
}

ABP** buscaMenor(ABP **p){
    if(*p == NULL){
        return NULL;
    }
    else if((*p)->esq == NULL){
        return p;
    }
    else{
        return buscaMenor(&((*p)->esq));
    }
}

void remover(ABP **p, int k){
    if(*p == NULL){
        return;
    }
    else{
        ABP **alvo = busca(p, k);

        if(*alvo == NULL){
            return;
        }
        else if(((*alvo)->dir == NULL) && ((*alvo)->esq == NULL)){
            free(*alvo);
            *alvo = NULL;
        }

        else if(((*alvo)->esq == NULL) && ((*alvo)->dir != NULL)){
            ABP *filho = (*alvo)->dir;
            free(*alvo);
            *alvo = filho;

        }
        else if(((*alvo)->esq != NULL) && ((*alvo)->dir == NULL)){
            ABP *filho = (*alvo)->esq;
            free(*alvo);
            *alvo = filho;

        }
        else{
            ABP **substituto = buscaMenor(&((*alvo)->dir));
            (*alvo)->chave = (*substituto)->chave;
            remover(substituto, (*substituto)->chave);

        }
    }
}

void emOrdem(ABP *p){
    if(p != NULL){
        emOrdem(p->esq);
        printf("\n %d ", p->chave);
        emOrdem(p->dir);
    }

}

int main()
{
    //criando ABP vazia
    ABP *raiz = NULL;

    // insercoes
    adiciona(&raiz, 500);
    adiciona(&raiz, 250);
    adiciona(&raiz, 750);
    adiciona(&raiz, 350);
    adiciona(&raiz, 100);

    emOrdem(raiz);

    remover(&raiz, 350);


    printf("\n depois das remocoes");
    emOrdem(raiz);

    return 0;
}
