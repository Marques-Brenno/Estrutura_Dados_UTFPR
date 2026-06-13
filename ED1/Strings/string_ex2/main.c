#include <stdio.h>
#include <stdlib.h>

int main()
{
    char pala[80];

    printf("Digite uma palavra: ");
    fgets(pala, 80, stdin);

    printf("%s \n", pala);
    int i = 0;
    while(pala[i] != '\0'){
        i++;
    }

    printf("\nA palavra tem %i letras", i - 1);

    if(pala[0] == 'a' || pala[0] == 'A'){
        printf("\n%s Comeca com A", pala);
    }

    return 0;
}
