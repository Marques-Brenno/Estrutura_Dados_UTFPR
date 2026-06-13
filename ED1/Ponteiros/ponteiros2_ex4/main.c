#include <stdio.h>
#include <stdlib.h>

void cont(int *a, int *b){
    *a *= *a;
    int tam = *b;
    *b = 1;

    for(int i = 2; i <= tam; i++){
        *b *= i;
    }
}

int main()
{
    int a = 5, b = 4;

    cont(&a, &b);

    printf("O fatorial e %i, o quadrado e %i", b, a);

    return 0;
}
