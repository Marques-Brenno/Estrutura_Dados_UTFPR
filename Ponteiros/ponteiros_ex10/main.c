#include <stdio.h>
#include <stdlib.h>

int *busca(int *v, int num){
    for(int i = 0; i < 5; i++){
        if(*(v+i) == num){
            return v+i;
        }
    }
    return NULL;
}

int main()
{
    int v[] = {1,2,3,4,5}, num, *resul = NULL;
    for(int i = 0; i < 5; i++){
        printf("%p \n", v+i);
    }

    printf("\n Digite o numero q deseja buscar: ");

    fflush(stdout);

    scanf("%i", &num);

    resul = busca(v, num);

    if(resul != NULL){
        printf("\n O numero %i tem o indereco de memoria %p", num, resul);
    }
    else{
        printf("\n O numero %i nao foi encontrado", num);
    }
    return 0;
}
