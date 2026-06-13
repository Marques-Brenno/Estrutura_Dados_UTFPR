#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palavra[80], contra[80];

    printf("Digite uma palavra: ");
    fgets(palavra, 80, stdin);

    palavra[strcspn(palavra, "\n")] = 0;

    int i = 0, ct = 0;
    while(palavra[i] != '\0'){
        i++;
    }

    i--;

    while(i != -1){
        contra[ct] = palavra[i];

        i--;
        ct++;
    }

    contra[ct] = '\0';

    printf("\nA palavra %s fica assim de tras para frente %s", palavra, contra);
    return 0;
}
