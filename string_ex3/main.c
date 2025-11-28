#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str1[80], str2[80];

    printf("Digite uma palavra: ");
    fgets(str1, 80, stdin);

    printf("\nDigite outra palavra: ");
    fgets(str2, 80, stdin);

    str1[strcspn(str1, "\n")] = 0;
    str2[strcspn(str2, "\n")] = 0;

    int i = 0;
    while((str1[i] == str2[i]) && (str1[i] != '\0')){
        i++;
    }

    if (str1[i] < str2[i]) {
        printf("\nA primeira string (\"%s\") vem ANTES da segunda (\"%s\").\n", str1, str2);
    }
    else if (str1[i] > str2[i]) {
        printf("\nA primeira string (\"%s\") vem ANTES da segunda (\"%s\").\n", str2, str1);
    }
    else {
        printf("\nAs duas strings são IGUAIS.\n");
    }


    return 0;
}
