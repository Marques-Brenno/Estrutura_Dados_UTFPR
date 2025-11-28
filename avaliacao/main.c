#include <stdio.h>
#include <stdlib.h>

void vendas(int **p, int *t, int i){
    int numVendas = 0;

    do{
        printf("Digite o numero de vendas do %i vendedor: ", i+1);
        scanf("%i", &numVendas);
    }while(numVendas < 0);

    *t = numVendas;
    if(numVendas != 0){
        *p = (int *) malloc(numVendas * sizeof(int));

        if(*p == NULL){
            printf("Falha ao alocar memoria/n");
            exit(1);
        }
        printf("Preenchas as avaliacoes: \n");
        printf("1 - Exelente\n");
        printf("2 - Bom\n");
        printf("3 - Regular\n");
        printf("4 - Ruim\n");

        for(int j = 0; j < numVendas; j++){
            do{
                printf("Avaliacao da %i venda: ", j+1);
                scanf("%i", *p+j);
            }while(*(*p+j) < 1 || *(*p+j) > 4);
        }
    }


}

void relatorio(int *p, int tam, int i){
    if(tam != 0){
        int ex = 0,bom = 0, reg = 0, ruim = 0;
        for(int j = 0; j < tam; j++){
            if(*(p+j) == 1){
                ex++;
            }
            else if(*(p+j) == 2){
                bom++;
            }
            else if(*(p+j) == 3){
                reg++;
            }
            else{
                ruim++;
            }
        }

        printf("As avaliacoes do %i funcionario foram:\n", i+1);
        printf("%i Excelentes, %i Boas, %i regulares, %i Ruins\n", ex, bom, reg, ruim);
    }
    else{
        printf("O %i funcionario nao teve vendas\n", i+1);
    }


}

void desaloca(int **p){
    free(*p);
    *p = NULL;

}

int main()
{
    int n = 4;
    int *vendedores[n];
    int tamanhos[n];

    for(int i = 0; i < n; i++){
        vendas(vendedores + i, tamanhos + i, i);
    }


    for(int i = 0; i < n; i++){
        relatorio(*(vendedores + i), *(tamanhos + i), i);
    }

    for(int i = 0; i < n; i++){
        desaloca(vendedores + i);
    }


    printf("Hello world!\n");
    return 0;
}
