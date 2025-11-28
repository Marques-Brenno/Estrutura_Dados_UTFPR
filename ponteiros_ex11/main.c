#include <stdio.h>
#include <stdlib.h>

void media(float *v, int tam, float *resul){
    for(int i = 0; i < tam; i++){
        *resul += *(v+i);
    }

    *resul = *resul / tam;
}

int main()
{
    float notas[] = {10,5,5,5,5}, resul = 0;
    int tam = 5;

    media(notas, tam, &resul);

    printf("A media das notas é %.2f\n", resul);
    return 0;
}
