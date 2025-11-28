#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float dist(float *x, float *y){
    float resposta;

    resposta = sqrt((*(x+1) - *x) + (*(y+1) - *y));

    return resposta;
}


int main()
{
    float x[2], y[2], resul;
    printf("\nDigte o primeiro ponto x: ");
    scanf("%f", x);

    printf("\nDigte o segundo ponto x: ");
    scanf("%f", x+1);

    printf("\nDigte o primeiro ponto y: ");
    scanf("%f", y);

    printf("\nDigte o segundo ponto y: ");
    scanf("%f", y+1);

    resul = dist(x, y);

    printf("\nA distanca entre os pontos e de %f", resul);
    return 0;
}
