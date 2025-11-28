#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    char nome[80], novo[80], velho[80];
    int idade, inovo, ivelho;

    printf("Digite o nome: ");
    fgets(nome, 80, stdin);

    nome[strcspn(nome, "\n")] = 0;

    printf("Digite a idade: ");
    scanf("%i", &idade);

    limpar_buffer();

    strcpy(novo, nome);
    strcpy(velho, nome);

    inovo = idade;
    ivelho = idade;

    printf("\nDigite -1 na idade para sair\n");

    do{

        printf("Digite o nome: ");
        fgets(nome, 80, stdin);

        nome[strcspn(nome, "\n")] = 0;

        printf("Digite a idade: ");
        scanf("%i", &idade);

        limpar_buffer();

        if(idade > -1){
            if(idade < inovo){
                strcpy(novo, nome);
                inovo = idade;
            }
            if(idade > ivelho){
                strcpy(velho, nome);
                ivelho = idade;
            }
        }

    }while(idade > -1);

    printf("O mais velho e %s e tem %i anos\n", velho, ivelho);
    printf("O mais novo e %s e tem %i anos\n", novo, inovo);

    return 0;
}
