#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char frase1[80], frase2[80], frase1M[80], frase2M[80];

    printf("Digite a primeira frase: ");
    fgets(frase1, 80, stdin);
    frase1[strcspn(frase1, "\n")] = 0;

    printf("Digite a segunda frase: ");
    fgets(frase2, 80, stdin);
    frase2[strcspn(frase2, "\n")] = 0;

    int i = 0;
    while(frase1[i] != '\0'){
        frase1M[i] = toupper(frase1[i]);
        i++;
    }

    frase1M[i] = '\0';

    i = 0;
    while(frase2[i] != '\0'){
        frase2M[i] = toupper(frase2[i]);
        i++;
    }

    frase2M[i] = '\0';

    int tam1 = strlen(frase1M), tam2 = strlen(frase2M), tamanho = tam1 - tam2;



    i = 0;
    int tot = 0;
    for(int ct = tamanho; ct < tam1; ct++){
        if(frase1M[ct] != frase2M[i]){
            tot++;
        }
        i++;
    }

    if(tot == 0){
        printf("a segunda frase esta na primeira, ' %s ', contem, ' %s '",frase1M, frase2M);
    }
    else{
        printf("a segunda frase nao esta na primeira, ' %s ', nao contem, ' %s '",frase1M, frase2M);
    }



    return 0;
}
