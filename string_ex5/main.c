#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char nome[80];
    int tam;
    printf("Digite seu nome: ");
    fgets(nome, 80, stdin);

    nome[strcspn(nome, "\n")] = 0;

    tam = strlen(nome);

    printf("\nO seu nome tem %i letras", tam);

    return 0;
}
