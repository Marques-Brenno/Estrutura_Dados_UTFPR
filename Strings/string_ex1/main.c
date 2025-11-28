#include <stdio.h>
#include <stdlib.h>

void name(){
    char nome[80];
    printf("Digite seu nome: ");
    fgets(nome, 80, stdin);

    printf("\n ola %s", nome);
}

int main()
{
    name();
    return 0;
}
