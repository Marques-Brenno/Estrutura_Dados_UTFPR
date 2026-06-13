#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct atleta{
    char nome[20];
    int tempos[6];
    int velocidade[6];
    int batimentos[6];
}atleta;

int main()
{
    atleta ResulAtleta;
    int Vmax = 0, maiorBPS = 0, menorBPS = 0;
    float Ttotal = 0;
    printf("Digite o nome do atleta: ");
    fgets(ResulAtleta.nome, 20, stdin);

    for(int i = 0; i < 6; i++){
        printf("\n----------------------------------------------------------------------");
        printf("\nDigite as informacoes da %d prova\n", i + 1);
        printf("\nDigite o tempo em segundos: ");
        scanf("%d", &ResulAtleta.tempos[i]);
        printf("\nDigite a velocidade em m/s: ");
        scanf("%d", &ResulAtleta.velocidade[i]);
        printf("\nDigite o batimeto em BPS: ");
        scanf("%d", &ResulAtleta.batimentos[i]);
        printf("\n----------------------------------------------------------------------");

    }

    menorBPS = ResulAtleta.batimentos[1];

    for(int i = 0; i < 6; i++){
        Ttotal += ResulAtleta.tempos[i];

        if(ResulAtleta.velocidade[i] > Vmax){
            Vmax = ResulAtleta.velocidade[i];
        }

        if(maiorBPS < ResulAtleta.batimentos[i]){
            maiorBPS = ResulAtleta.batimentos[i];
        }
        if(menorBPS > ResulAtleta.batimentos[i]){
            menorBPS = ResulAtleta.batimentos[i];
        }

    }

    printf("\n----------------------------------------------------------------------");
    printf("\nO tempo medio de corrida foi de %.2f segundos", Ttotal / 6);
    printf("\nA velocidade maxima foi de %d m/s", Vmax);
    printf("\nA amplitude de batimentos foi %d", maiorBPS - menorBPS);


    return 0;
}
