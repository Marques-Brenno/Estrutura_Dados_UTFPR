#include <stdio.h>
#include <stdlib.h>

typedef struct NO{
    int chave;
    struct NO *prox;
}NO;

NO *alocaNO(int k);
void insereLista(NO **p, int k);
void insereRecur(NO **p, int k);
void insereListaF(NO **p, int k);
void remover(NO **p);
void imprimir(NO *p);
NO *busca(NO *p, int k);
NO *buscaRec(NO *p, int k);
void max(NO *p);
void min(NO *p);
void soma(NO *p);
void tam(NO *p);
void rep(NO *p, int k);
void removerEle(NO **p, int k);
NO *copia(NO *p);
NO *inverte(NO *p);
int comparar(NO *p1, NO *p2);
void juntar(NO *p1, NO **p2);
NO *divide(NO *p, int k);
int somarRec(NO *p);
int tlista(NO *p);
void removerRec(NO **p, NO **aux, int k);
void desalocaRec(NO **p);

int main()
{
    NO *lista = NULL, *achou = NULL, *lista2 = NULL, *lista3 = NULL;
    int comp;
    printf("\n---------------------------------------------------------------------------");
    insereLista(&lista, 1);
    insereLista(&lista, 2);
    insereLista(&lista, 3);
    insereListaF(&lista, 4);
    insereListaF(&lista, 2);
    insereListaF(&lista, 5);
    imprimir(lista);
    printf("\n---------------------------------------------------------------------------");
    achou = busca(lista, 2);
    if(achou){
        printf("\nO numero %d pertence a %p", achou->chave, achou);
    }
    else{
        printf("\nO item nao foi encontrado");
    }
    printf("\n---------------------------------------------------------------------------");
    max(lista);

    printf("\n---------------------------------------------------------------------------");
    min(lista);

    printf("\n---------------------------------------------------------------------------");
    soma(lista);

    printf("\n---------------------------------------------------------------------------");
    tam(lista);

    printf("\n---------------------------------------------------------------------------");
    rep(lista, 2);

    printf("\n---------------------------------------------------------------------------");
    removerEle(&lista, 3);
    imprimir(lista);

    printf("\n---------------------------------------------------------------------------");
    printf("\n imprime a lista 2");
    lista2 = copia(lista);
    imprimir(lista2);

    printf("\n---------------------------------------------------------------------------");
    printf("\nImprime a lista 3");
    lista3 = inverte(lista);
    imprimir(lista3);

    printf("\n---------------------------------------------------------------------------");
    printf("\nCompara listas");
    comp = comparar(lista, lista3);
    if(comp == 1){
        printf("\nAs listas sao iguais");
    }
    else{
        printf("\nAs listas sao diferentes");
    }

    printf("\n---------------------------------------------------------------------------");
    printf("\nJuntar listas");
    juntar(lista, &lista2);
    printf("\nLista1");
    imprimir(lista);
    printf("\nLista2");
    imprimir(lista2);

    printf("\n---------------------------------------------------------------------------");
    printf("\nSoma recursiva");
    int total = somarRec(lista);   
    printf("\n o valor total e %d", total);

    printf("\n---------------------------------------------------------------------------");
    printf("\nBusca recursiva");
    achou = buscaRec(lista, 2); 
    if(achou){
        printf("\nO numero %d pertence a %p", achou->chave, achou);
    }
    else{
        printf("\nO item nao foi encontrado");
    }

    printf("\n---------------------------------------------------------------------------");
    printf("\nInsere recursiva");
    insereRecur(&lista, 6);
    imprimir(lista);

    printf("\n---------------------------------------------------------------------------");
    printf("\nTamanho da lista recursiva");
    int tamanho = tlista(lista);    
    printf("\n o tamanho da lista e %d", tamanho);


    printf("\n---------------------------------------------------------------------------");
    printf("\nseparar listas");
    lista2 = divide(lista, 4);
    printf("\nLista1");
    imprimir(lista);
    printf("\nLista2");
    imprimir(lista2);


    printf("\n---------------------------------------------------------------------------");


    while(lista!=NULL){
        remover(&lista);
    }
    imprimir(lista);

    while(lista2!=NULL){
        remover(&lista2);
    }
    imprimir(lista2);

    while(lista3!=NULL){
        remover(&lista3);
    }
    imprimir(lista3);
    return 0;
}

NO *alocaNO(int k){
    NO *novo = NULL;
    novo = (NO *)malloc(sizeof(NO));
    if(novo == NULL) return NULL;
    novo->chave = k;
    novo->prox = NULL;
    return novo;
}

void insereLista(NO **p, int k){
    NO *novo = alocaNO(k);

    if(novo == NULL){
        printf("\n SO nao disponibilizou memoria");
        return;
    }

    novo->prox = *p;
    *p = novo;
}

void insereListaF(NO **p, int k){
    NO *novo = alocaNO(k);
    if(*p == NULL){

        if(novo == NULL){
            printf("\n SO nao disponibilizou memoria");
            return;
        }

        novo->prox = *p;
        *p = novo;
    }
    else{
        NO *aux = *p;

        while(aux->prox != NULL){
            aux = aux->prox;
        }
        aux->prox = novo;
    }
}

void remover(NO **p){
    if(*p){
        NO *aux = *p;

        *p = aux->prox;

        free(aux);
        aux = NULL;
    }
    else{
        printf("\nLista vazia");
    }

}

void imprimir(NO *p){
    if(p == NULL){
        printf("\nLista vazia");
        return;
    }
    while(p != NULL){
        printf("\n%d", p->chave);
        p = p->prox;
    }
}

NO *busca(NO *p, int k){
    if(p){
        while(p != NULL){
            if(p->chave == k){
                return p;
            }

            p = p->prox;
        }
    }
    return NULL;
}

void max(NO *p){
    int maior = p->chave;
    p = p->prox;
    while(p != NULL){
        if(p->chave > maior){
            maior = p->chave;
        }
        p = p->prox;
    }

    printf("\n o maior valor e %d", maior);

}

void min(NO *p){
    int menor = p->chave;
    p = p->prox;
    while(p != NULL){
        if(p->chave < menor){
            menor = p->chave;
        }
        p = p->prox;
    }

    printf("\n o menor valor e %d", menor);

}

void soma(NO *p){
    int total = 0;
    while(p != NULL){
       total += p->chave;
        p = p->prox;
    }

    printf("\n o valor total e %d", total);

}

void tam(NO *p){
    int t = 0;
    while(p != NULL){
       t++;
        p = p->prox;
    }

    printf("\n o tamanho da lista e %d", t);

}

void rep(NO *p, int k){
    int t = 0;
    while(p != NULL){
        if(p->chave == k){
           t++;
        }

        p = p->prox;
    }

    if(t == 0){
        printf("\no valor %d nao aparece nenhuma vez na lista", k);
    }
    else{
        printf("\no valor %d aparece %d vezes na lista", k, t);
    }

}

void removerEle(NO **p, int k){
    if(*p){
        NO *aux = *p;
        if(aux == *p){
            *p = aux->prox;
            free(aux);
            aux = NULL;
            return;
        }
        while((aux->prox)->chave != k && aux->prox != NULL){
            aux = aux->prox;
        }

        if(aux->prox == NULL && aux->chave != k){
            printf("\nElemento nao foi encontrado");
        }
        else if(aux->prox == NULL){
            free(aux->prox);
            aux->prox = NULL;
        }
        else{
            NO *aux2 = aux->prox;
            aux->prox = aux2->prox;

            free(aux2);
            aux2 = NULL;
        }

    }
    else{
        printf("\nLista vazia");
    }

}

NO *copia(NO *p){
    NO *lista2 = alocaNO(p->chave);
    NO *aux = lista2;
    NO *aux2 = NULL;

    p = p->prox;

    while(p != NULL){
        aux2 = alocaNO(p->chave);
        aux->prox = aux2;

        aux = aux2;
        p = p->prox;
    }

    return lista2;
}


NO *inverte(NO *p){
    NO *lista = NULL;

    while(p != NULL){
        insereLista(&lista, p->chave);


        p = p->prox;
    }

    return lista;
}

int comparar(NO *p1, NO *p2){
    int comp = 1;
    while(p1 != NULL && p2 != NULL){
        if(p1->chave != p2->chave){
            comp = 0;
            return comp;
        }
        p1 = p1->prox;
        p2 = p2->prox;
    }

    return comp;
}

void juntar(NO *p1, NO **p2){
    while(p1->prox != NULL){
        p1 = p1->prox;
    }

    p1->prox = *p2;

    *p2 = NULL;
}

NO *divide(NO *p, int k){
    NO *lista2 = NULL;
    if(p->chave == k){
        lista2 = p->prox;
        p->prox = NULL;

        return lista2;
    }

    while((p->prox)->chave != k && p != NULL){
        p = p->prox;
    }

    if(p == NULL){
        printf("\nO elemento nao foi encontrado");
        return NULL;
    }
    else{
        lista2 = p->prox;
        p->prox = NULL;

        return lista2;
    }

}


void insereRecur(NO **p, int k){
    if(!(*p)->prox){
        NO *novo = alocaNO(k);
        (*p)->prox = novo;
    }
    else if(!*p){
        NO *novo = alocaNO(k);
        *p = novo; 
    }
    else{
        insereRecur(&(*p)->prox, k);
    }
    
    

}


NO *buscaRec(NO *p, int k){
    if(!p){
        printf("\nelemento nao encontrado");
        return NULL;
    }
    else if(p->chave == k){
        return p;
    }
    else{
        buscaRec(p->prox, k);
    }
    
    return NULL;
}

int somarRec(NO *p){
    if(!p){
        return 0;
    }
    else{
        return p->chave + somarRec(p->prox);
    }
}

int tlista(NO *p){
    if(!p){
        return 0;
    }
    else{
        return 1 + tlista(p->prox);
    }
}

void removerRec(NO **p, NO **aux, int k){
    if(!*p){
        printf("\nelemento nao encontrado");
        return;
    }
    else if((*p)->chave == k){
        *aux = *p;
        *p = (*p)->prox;
        free(*aux);
        *aux = NULL;
    }
    else{
        removerRec(&(*p)->prox, aux, k);
    }
}

void desalocaRec(NO **p){
    NO *aux = NULL;
    if(!*p){
        return;
    }
    else{
        aux = *p;
        *p = (*p)->prox;
        free(aux);
        aux = NULL;
        desalocaRec(p);
    }
}