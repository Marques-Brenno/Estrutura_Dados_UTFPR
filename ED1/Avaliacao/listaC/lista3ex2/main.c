#include <stdio.h>
#include <stdlib.h>

typedef struct data{
 int dia;
 int mes;
 int ano;
}Data;

int calc(Data *data){
    int resul = 0;

    if(((data+1)->ano) > (data->ano)){
        resul += ((data + 1)->ano - data->ano) * 365;
    }
    else{
        resul += (data->ano - (data+1)->ano) * 365;
    }

    if(((data+1)->mes) > (data->mes)){
        resul += ((data + 1)->mes - data->mes) * 30;
    }
    else{
        resul += (data->mes - (data+1)->mes) * 30;
    }

    if(((data+1)->dia) > (data->dia)){
        resul += ((data + 1)->dia - data->dia);
    }
    else{
        resul += (data->dia - (data+1)->dia);
    }

    return resul;

}

int main()
{
    Data data[2];

    int resul;

    printf("\nDigite o dia: ");
    scanf("%d", &data[0].dia);

    printf("\nDigite o mes: ");
    scanf("%d", &data[0].mes);

    printf("\nDigite o ano: ");
    scanf("%d", &data[0].ano);


    printf("\nDigite o dia: ");
    scanf("%d", &data[1].dia);

    printf("\nDigite o mes: ");
    scanf("%d", &data[1].mes);

    printf("\nDigite o ano: ");
    scanf("%d", &data[1].ano);

    resul = calc(data);


    printf("\na diferenca e de %d dias", resul);
    return 0;
}
