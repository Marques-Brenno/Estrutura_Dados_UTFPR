#include <stdio.h>
#include <stdlib.h>

typedef struct doc{
    char nome[30];
    char extensao[5];
    int tamanho;
    int colorido;
}doc;

typedef struct no{
    doc documentos;
    struct no *prox;
}no;


typedef struct c{
    no *pri;
    no *ult;
    int tamanho;
}c;

void inserir(c **p);
void imprimir(c **p);
void listar(no *p);
void buscar(no *p, int k);

int main()
{
    c *cabeca = (c *)malloc(sizeof(c));
    cabeca->pri = NULL;
    cabeca->ult = NULL;
    cabeca->tamanho = 0;

    int op;

    do
    {
        printf("Menu de opcoes:\n");
        printf("1 - Inserir documento\n");
        printf("2 - imprimir documento\n");
        printf("3 - Listar documentos\n");
        printf("4 - Buscar documento\n");
        printf("5 - cancelar imprecao");
        printf("0 - Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &op);

        switch(op)
        {
            case 1:
                // Chamar funcao para inserir documento
                break;
            case 2:
                // Chamar funcao para imprimir documento
                break;
            case 3:
                // Chamar funcao para listar documentos
                break;
            case 0:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida. Tente novamente.\n");
        }
    } while (op != 0);
    
    return 0;
}

void inserir(c **p){

    no *novo = (no *)malloc(sizeof(no));
    if (novo){
        novo->prox = NULL;
        printf("\nDigite o nome: ");
        scanf("%s", novo->documentos.nome);
        printf("\nDigite o extensao: ");
        scanf("%s", novo->documentos.extensao);
        printf("\nDigite o tamanho: ");
        scanf("%d", &novo->documentos.tamanho);
        printf("\nDigite se quer imprimir colorido (1- sim, 0- nao): ");
        scanf("%d", &novo->documentos.colorido);


        if ((*p)->pri){
            ((*p)->ult)->prox = novo;
            (*p)->ult = novo;
        
        }
        else{
            (*p)->pri = novo;
            (*p)->ult = novo;
        }

        (*p)->tamanho++;

    }
    else{
        printf("\nErro ao alocar memoria");
        return;
    }
    
    
}


void imprimir(c **p){
    if(!(*p)->pri){
        printf("\nLista vazia");
        return;
    }
    else{
        if((*p)->pri == (*p)->ult){
            free((*p)->pri);
            (*p)->pri = NULL;
            (*p)->ult = NULL;
        }
        else{
            no *aux = (*p)->pri;
            (*p)->pri = aux->prox;
            free(aux);
        }
        
        
    }
}

void listar(no *p){
    if(!p){
        printf("\nLista vazia");
        return;
    }
    while (!p){
        printf("\n-----------------------------------------------------------------------------------");
        printf("\n:Documentos %s", p->documentos.nome);
        printf("\n:extensao %S", p->documentos.extensao);
        printf("\n:Tamanho %d", p->documentos.tamanho);
        printf("\n:Colorido %d", p->documentos.colorido);
    }

    printf("\n-----------------------------------------------------------------------------------");
}