#include <stdio.h>
#include <stdlib.h>

typedef struct NumComplexo{
 float real; // parte real
 float imag; // parte imaginária
}NumComplexo;



int main()
{
    NumComplexo num[2];

    printf("Digte a parte real do primeiro numero: ");
    printf("%f", num[0].real);

    printf("Digte a parte imaginaria do primeiro numero: ");
    printf("%f", num[0].imag);

    printf("Digte a parte real do segundo numero: ");
    printf("%f", num[1].real);

    printf("Digte a parte imaginaria do segundo numero: ");
    printf("%f", num[1].imag);

    return 0;
}
