#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct dominio
{
    int ip;
    char nome[50];
    struct dominio *prox;
}dominio;


void buscar(dominio *cabeca, int ip);
void inserir(dominio **cabeca, int ip, char nome[]);

int main()
{
    dominio *cabeca = NULL;
    int op = 0, ip;
    char nome[50];

    do
    {
        printf("\n1 - Inserir dominio");
        printf("\n2 - Buscar dominio");
        printf("\n0 - Sair");
        printf("\n\nDigite a opcao desejada: ");
        scanf("%d", &op);
        switch (op)
        {
            case 1:
                printf("\nDigite o IP: ");
                scanf("%d", &ip);
                printf("Digite o nome do dominio: ");
                scanf("%s", nome);
                inserir(&cabeca, ip, nome);
                break;
            case 2:
                printf("\nDigite o IP a ser buscado: ");
                scanf("%d", &ip);
                buscar(cabeca, ip);
                break;
        }
    } while (op != 0);
    
    

    return 0;
}

void inserir(dominio **cabeca, int ip, char nome[]){
    dominio *novo = (dominio *) malloc (sizeof(dominio));
    novo->ip = ip;
    strcpy(novo->nome, nome);
    novo->prox = *cabeca;
    *cabeca = novo;
}

void buscar(dominio *cabeca, int ip){
    dominio *atual = cabeca;
    while(atual != NULL){
        if(atual->ip == ip){
            printf("\nDominio encontrado: %s\n", atual->nome);
            return;
        }
        atual = atual->prox;
    }
    printf("\nDominio nao encontrado.\n");
}

