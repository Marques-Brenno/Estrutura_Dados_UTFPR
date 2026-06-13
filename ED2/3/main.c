#include <stdio.h>
#include <stdlib.h>

int buscaBI(int v[], int ini, int fim, int k){
    if(ini > fim)
        return -1;

    int m = ini + ((fim - ini) / 2);

    if(v[m] == k)
        return m;
    else if(v[m] > k)
        return buscaBI(v, ini, m - 1, k);
    else
        return buscaBI(v, m + 1, fim, k);
}

int buscaDesordenada(int v[], int ini, int fim, int k){
    for(int i = ini; i <= fim; i++){
        if(v[i] == k){
            return i;
        }
    }
    return -1;
}

int busca(int v[], int t, int k){

    if(t == 0)
        return -1;

    int m = t/2;

    if(v[m] == k)
        return m;

    int b1;
    b1 = buscaDesordenada(v, 0, m - 1, k);

    if(b1 != -1)
        return b1;

    b1 = buscaBI(v, m + 1, t, k);

     if(b1 != -1)
        return b1;

    return -1;

}


int main()
{
    int v[] = {89, 12, 45, 3, 22, 30, 40, 50, 74, 99};
    int t = sizeof(v) / sizeof(v[0]);

    int chave = 45;

    // Teste 1
    int res = busca(v, t, chave);
    printf("Buscando %d (primeira metade): Indice retornado = %d\n", chave, res);

    // Teste 2
    chave = 30;
    res = busca(v, t, chave);
    printf("Buscando %d (no meio): Indice retornado = %d\n", chave, res);

    // Teste 3
    chave = 74;
    res = busca(v, t, chave);
    printf("Buscando %d (segunda metade): Indice retornado = %d\n", chave, res);

    // Teste 3
    chave = 100;
    res = busca(v, t, chave);
    printf("Buscando %d (inexistente): Indice retornado = %d\n", chave, res);

    return 0;
}
