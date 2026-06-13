#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Data{
    int dia;
    int mes;
}Data;

typedef struct Contato{
    char nome[50];
    char telefone[15];
    Data aniversario;
    struct Contato *prox;
}Contato;

typedef struct Agenda{
    int qtd_contatos;
    Contato *contatos;
}Agenda;

Contato *criarcontato(char nome[], char telefone[], int dia, int mes);
void addcontato(Agenda *cabeca);

void exibir(Agenda *cabeca);


void limpar_buffer();

void pesquisar(Agenda *cabeca);

void remover(Agenda *cabeca);

int main()
{
    Agenda *cabeca = (Agenda *) malloc (sizeof(Agenda));
    cabeca->qtd_contatos = 0;
    cabeca->contatos = NULL;
    int op = 0;

    do{
       printf("\n1 - Adcionar contato");
        printf("\n2 - exibir contatos");
        printf("\n3 - Pesquisar contato");
        printf("\n4 - Remover contato");
        printf("\n5 - remover todos os contatos");
        printf("\n0 - Sair");
        printf("\n\nDigite a opcao desejada: ");
        scanf("%d", &op);

        limpar_buffer();

        switch (op)
        {
        case 1:
            addcontato(cabeca);
            break;
        case 2:
            exibir(cabeca);
            break;

        case 3:
            pesquisar(cabeca);
            break;
        
        case 4:
            remover(cabeca);  
            break;

        case 5:
            while (cabeca->contatos != NULL)
            {
                remover(cabeca);
            }
            
 
            break;

        default:
            break;
        }
    } while (op != 0);

    while (cabeca->contatos != NULL)
    {
        remover(cabeca);
    }

    free(cabeca);


    return 0;
}

void limpar_buffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}


Contato *criarcontato(char nome[], char telefone[], int dia, int mes){
    Contato *novo = (Contato *)malloc (sizeof(Contato));
    strcpy(novo->nome, nome);
    strcpy(novo->telefone, telefone);
    novo->aniversario.dia = dia;
    novo->aniversario.mes = mes;
    novo->prox = NULL;
    return novo;
}

void addcontato(Agenda *cabeca){
    char nome[50], telefone[50];
    int dia, mes;

    printf("\nDigite o nome do contato: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = 0;
    
    printf("\nDigite o telefone do contato: ");
    fgets(telefone, 15, stdin);
    telefone[strcspn(telefone, "\n")] = 0;

    printf("\nDigite o dia do aniversario: ");
    scanf("%d", &dia);
    
    printf("\nDigite o mes do aniversario: ");
    scanf("%d", &mes);

    limpar_buffer();

    Contato *novo = criarcontato(nome, telefone, dia, mes);

    novo->prox = cabeca->contatos;
    cabeca->contatos = novo;
    
    cabeca->qtd_contatos++;
}

void exibir(Agenda *cabeca){
    Contato *aux = cabeca->contatos;
    printf("\n---------------------------------------------");
    if (cabeca->qtd_contatos == 0)
    {
        printf("\nVoce nao tem contatos");
        printf("\n---------------------------------------------");
        return;
    }
    
    for (int i = 0; i < cabeca->qtd_contatos; i++)
    {
        printf("\nNome: %s", aux->nome);
        printf("\nTelefone: %s", aux->telefone);

        printf("\n---------------------------------------------");

        aux = aux->prox;
    }
    
}

void pesquisar(Agenda *cabeca){
    Contato *aux = cabeca->contatos;
    char nome[50];
    int ct = 0;
    printf("\n---------------------------------------------");

    printf("\nDigite o nome q deseja buscar: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = 0;

    for (int i = 0; i < cabeca->qtd_contatos; i++){
        if (strcmp(aux->nome, nome) == 0){
            printf("\nNome: %s", aux->nome);
            printf("\nTelefone: %s", aux->telefone);

            printf("\n---------------------------------------------");
            ct++;
            
        }

        aux = aux->prox;
        
    }

    if(ct == 0){
        printf("\nVoce nao tem nenhum contato com o nome %s", nome);
        printf("\n---------------------------------------------");
    }
    else
    {
        printf("\nVoce tem %d contatos com o nome %s", ct, nome);
        printf("\n---------------------------------------------");
    }
}

void remover(Agenda *cabeca){
    if (cabeca->qtd_contatos > 0)
    {
        Contato *aux = cabeca->contatos;

        free(cabeca->contatos);

        cabeca->contatos = aux->prox;

        aux = NULL;

        cabeca->qtd_contatos--;

        if (cabeca->qtd_contatos == 0){
            cabeca->contatos = NULL;
        }
    }
    else
    {
        printf("\nVoce nao tem contatos");
    }
    
    
    
    
}