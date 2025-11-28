#include <stdio.h>
#include <stdlib.h>

void mm(int *p, int tam, int *max, int *min){

    *max = *p;
    *min = *p;

    for(int i = 1; i < tam; i++){
        if(*max < *(p+i)){
            *max = *(p+i);
        }
        if(*min > *(p+i)){
            *min = *(p+i);
        }
    }
}

void desaloca(int **p){
    free(*p);

    *p = NULL;

    printf("devolvido");

}

int main()
{
    int tam, max, min;

    do{
        printf("Qual o tamanho do vetor: ");
        scanf("%i", &tam);
    }while(tam < 1);


    int *num = (int *) malloc(tam * sizeof(int));

    for(int i = 0; i < tam; i++){
        printf("Digite o %i digito: ", i+1);
        scanf("%i", (num+i));
    }

    mm(num, tam, &max, &min);

    printf("o maximo foi %i, e o minimo foi %i\n", max, min);



    desaloca(&num);
    return 0;
}
