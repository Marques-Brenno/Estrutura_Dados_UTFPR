#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data{
     int dia;
     int mes;
     int ano;
}data;


typedef struct livro{
    char titulo[50];
    char autor[50];
    data lancamento;

}livro;

void addLivro(livro *p, int t);
void listar(livro *p, int t);
void busca(livro *p, int t);

int main()
{
    livro *p = (livro *)malloc(sizeof(livro) * 20);
    int op = 0, t = 0;

    do{
        printf("\n---------------------------------------------------------------------------");
        printf("\nEscolha uma opcao: \n");
        printf("\n1 - Cadastrar Livro");
        printf("\n2 - Listar livros");
        printf("\n3 - Buscar livros");
        printf("\n0 - Sair\n");

        scanf("%d", &op);

        getchar();

        if(op == 1){
            addLivro(p, t);
            t++;
        }
        else if(op == 2){
            listar(p, t);
        }
         else if(op == 3){
            busca(p, t);
        }
        else if(op > 3 || op < 0){
            printf("\nEscolha um numero entre 0 e 3");
        }


    }while(op != 0);


    free(p);

    return 0;
}

void addLivro(livro *p, int t){
    printf("\nDigite o titulo do livro: ");
    fgets((p+t)->titulo, 50, stdin);

    (p + t)->titulo[strcspn((p + t)->titulo, "\n")] = 0;

    printf("\nDigite o Autor do livro; ");
    fgets((p+t)->autor, 50, stdin);

    (p + t)->autor[strcspn((p + t)->autor, "\n")] = 0;

    printf("\nDigite o Dia de lancamento: ");
    scanf("%d", &(p+t)->lancamento.dia);

    printf("\nDigite o mes de lancamento: ");
    scanf("%d", &(p+t)->lancamento.mes);

    printf("\nDigite o ano de lancamento: ");
    scanf("%d", &(p+t)->lancamento.ano);

}

void listar(livro *p, int t){
    printf("\n---------------------------------------------------------------------------");
    if(t == 0){
        printf("\nNenhum livro foi cadastrado");
        return;
    }
    printf("\nOs livros cadastrados sao: \n");
    for(int i = 0; i < t; i++){
        printf("\n%d - %s",i+1, (p+i)->titulo);
    }
}

void busca(livro *p, int t){
    char c[50];
    printf("\nDigite o titulo do livro: ");
    fgets(c, 50, stdin);

    c[strcspn(c, "\n")] = 0;

    for(int i = 0; i < t; i++){
        if(strcmp((p+i)->titulo, c) == 0){
            printf("\n---------------------------------------------------------------------------");
            printf("\nTitulo - %s", (p+i)->titulo);
            printf("\nAutor - %s", (p+i)->autor);
            printf("\nDia lancamento - %d", (p+i)->lancamento.dia);
            printf("\nMes lancamento - %d", (p+i)->lancamento.mes);
            printf("\nAno lancamento - %d", (p+i)->lancamento.ano);
        }
        else{
            printf("\n---------------------------------------------------------------------------");
            printf("\nO livro nao foi encontrado");
        }
    }


}
