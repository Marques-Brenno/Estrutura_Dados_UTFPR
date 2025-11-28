#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int tam(char *n){
    for(int i = 0; i < strlen(n); i++){
        n[i] = toupper(*(n+i));
    }
    return strlen(n);
}

int main()
{
    char n[] = "ana clara fernandes";





    printf("o tamanho de %s e %i", n, tam(n));
    return 0;
}
