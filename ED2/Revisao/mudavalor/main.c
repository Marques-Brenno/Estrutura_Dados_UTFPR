#include <stdio.h>
#include <stdlib.h>

void mudaValor(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {

    int *a = (int *)malloc(sizeof(int));
    int *b = (int *)malloc(sizeof(int));

    printf("Digite o valor de a: ");
    scanf("%d", a);
    printf("Digite o valor de b: ");
    scanf("%d", b);
    printf("Antes da troca: a = %d, b = %d\n", *a, *b);
    mudaValor(a, b);
    printf("Depois da troca: a = %d, b = %d\n", *a, *b);

    return 0;
}