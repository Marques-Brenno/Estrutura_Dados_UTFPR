#include <stdio.h>
#include <stdlib.h>

typedef struct avl{
    int chave, bal;
    struct avl *dir, *esq;
}avl;

avl* aloca(int k){
    avl *novo = malloc(sizeof(avl));
    novo->chave = k;
    novo->bal = 0;
    novo->esq = novo->dir = NULL;
    return novo;
}



int insere(avl **p,int k){
    int cresceu = 0
    if(*p == NULL){
        *p = aloca(k);
        cresceu = 1;
    }
    else if(k < (*p)->esq){
        cresceu = insere(&((*p)->esq), k);

        if(cresceu){
            if((*p)->bal == 1){
                cresceu = 0;

            }
            else if((*p)->bal = 0){
                cresceu = -1;
            }
            else if((*p)->bal = -1){

            }
        }

    }
    else if(k > (*p)->dir){
        cresceu = insere(&((*p)->dir), k);
    }


}


int main()
{
    printf("Hello world!\n");
    return 0;
}
