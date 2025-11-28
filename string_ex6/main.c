#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//const char* veri(char sexo, int idade){
//    if((sexo == 'f' || sexo == 'F') && (idade < 25)){
//        return "ACEITA";
//    }
//    else{
//        return "NAO ACEITA";
//    }
//}
//
//int main()
//{
//    char nome[80], sexo, resul[80];
//    int idade;
//
//    printf("Digite seu nome: ");
//    fgets(nome, 80, stdin);
//
//    nome[strcspn(nome, "\n")] = 0;
//
//    printf("Digite seu sexo (M/F): ");
//
//    scanf(" %c", &sexo);
//
//    printf("Digite sua idade: ");
//    scanf("%i", &idade);
//
//
//    strcpy(resul, veri(sexo, idade));
//
//
//    printf("\n%s %s\n", nome, resul);
//
//    return 0;
//}


int veri(char sexo, int idade){
    if((sexo == 'f' || sexo == 'F') && (idade < 25)){
        return 1;
    }
    else{
        return 0;
    }
}

int main()
{
    char nome[80], sexo;
    int idade, resul;

    printf("Digite seu nome: ");
    fgets(nome, 80, stdin);

    nome[strcspn(nome, "\n")] = 0;

    printf("Digite seu sexo (M/F): ");

    scanf(" %c", &sexo);

    printf("Digite sua idade: ");
    scanf("%i", &idade);

    resul = veri(sexo, idade);

    if (resul == 1){
        printf("\n%s ACEITA\n", nome);
    }
    else{
        printf("\n%s NAO ACEITA\n", nome);
    }

    return 0;
}
