#include <stdio.h>
#include <stdlib.h>

int busca(int v[], int ini, int fim, int k){
    if(ini > fim)
        return -1;
    int m = ini + ((fim - ini) / 2);

    if(v[m] == k)
        return m;

    int esq = busca(v, ini, m - 1, k);

    if(esq != -1)
        return esq;

    int dir = busca(v, m + 1, fim, k);

    if(dir != -1)
        return dir;

}

int main()
{
    int vetor[] = {45, 12, 89, 3, 22, 74, 19, 50, 8, 33};
    int t = sizeof(vetor) / sizeof(vetor[0]);

    int chave = 100;

    int num = busca(vetor, 0, t - 1, chave);

    if(num != -1){
        printf("o valor %i foi encontrado na posicao %i\n", chave, num);
    }
    else{
        printf("o valor %i nao foi encontrado\n", chave);
    }

    return 0;
}
