#include <stdio.h>
#include <stdlib.h>

int main()
{
    char nome[80];
    printf("Digite seu nome: ");
    fgets(nome, 80, stdin);

    for(int i = 0; i < 4; i++){
        printf("%c", nome[i]);
    }
    return 0;
}
