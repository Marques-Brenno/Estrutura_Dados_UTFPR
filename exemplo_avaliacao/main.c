#include <stdio.h>
#include <stdlib.h>

int *avaliar(int i, int *t){
    int aten;
    do{
        printf("Quantas atendimentos o %i vendedor teve: ", i + 1);
        scanf("%i", &aten);
    }while(aten < 0);

    *(t+i) = aten;

    if(aten == 0){
        return NULL;
    }

    int *vendedor = (int *) malloc(aten * sizeof(int));

    if (vendedor == NULL) {
        printf("Erro ao alocar memoria!\n");
        *(t+i) = 0;
        return NULL;
    }

    for(int ct = 0; ct < aten; ct++){
        do{
            printf("De a avaliacao do %i atendimento: ", ct + 1);
            scanf("%i", vendedor + ct);
        }while(*(vendedor + ct) < 1 || *(vendedor + ct) > 4);
    }

    return vendedor;

}

void relatorio(int *p, int tam, int i){
    int ex = 0, bom = 0, reg = 0, ruim = 0;

    if(p != NULL){
        for(int ct = 0; ct < tam; ct++){
            if(*(p+ct) == 1){
                ex++;
            }
            else if(*(p+ct) == 2){
                bom++;
            }
            else if(*(p+ct) == 3){
                reg++;
            }
            else{
                ruim++;
            }
        }

        printf("O vendedor %i teve %i excelente, %i Bom, %i Regular, %i Ruim\n", i + 1, ex, bom, reg, ruim);
    }
    else{
        printf("O vendedor %i nao teve vendas\n", i+1);
    }

}

int main()
{
    int vendedores = 4;
    int *atendimentos[vendedores];
    int tamanhos[vendedores];
    for(int i = 0; i < vendedores; i++){
        *(atendimentos + i) = avaliar(i, tamanhos);
    }

    for(int i = 0; i < vendedores; i++){
        relatorio(*(atendimentos + i), *(tamanhos + i), i);
    }

    printf("Liberando memoria\n");
    for(int i = 0; i < vendedores; i++){
        if(*(atendimentos + i) != NULL){
          free(*(atendimentos + i));
        }

    }
    return 0;
}
