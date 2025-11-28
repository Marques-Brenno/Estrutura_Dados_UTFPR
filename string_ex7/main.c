#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char num[80];
    int ct = 0, i = 0;

    printf("Digite um numero: ");
    fgets(num, 80, stdin);

    num[strcspn(num, "\n")] = 0;

    while(num[i] != '\0'){
        if(num[i] == '0'){
            num[i] = '1';
        }
        i++;
    }

    printf("\n No numero %s", num);
    return 0;
}
