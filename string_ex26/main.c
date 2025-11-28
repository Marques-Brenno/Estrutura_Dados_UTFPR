#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char frase[80], fraseCri[80], letra;

    printf("Digite uma frase: ");
    fgets(frase, 80, stdin);

    frase[strcspn(frase, "\n")] = 0;

    int tam = strlen(frase), i = 0;

    while(i <= tam){
        if(frase[i] != ' '){
            letra = toupper(frase[i]) + 3;
        }
        else{
           letra = ' ';
        }

        printf(" %c ", letra);

        if(letra > 'Z'){
            letra -= 26;
        }

        fraseCri[i] = letra;
        i++;
    }

    fraseCri[i] = '\0';



    printf("\n A frase ' %s ' fica assim crip ' %s '", frase, fraseCri);

    return 0;
}
