#include <stdio.h>
#include <stdlib.h>

int strlen(char *p){
    int i = 0;
    while(*(p+i) != '\0'){
        i++;
    }

    return i;

}

char *strcopy(char *p){
    int tam = strlen(p);

    char *copy = (char *) malloc(tam * sizeof(char));

    for(int i = 0; i < tam; i++){
        *(copy+i) = *(p+i);

    }

    return copy;

}

char *strupper(char *p){
    int tam = strlen(p);

    for(int i = 0; i < tam; i++){
        if(*(p+i) >= 'a' && *(p+i) <= 'z'){
            *(p+i) = *(p+i) - 32;
        }
    }

    return p;
}

char *strlower(char *p){
    int tam = strlen(p);

    for(int i = 0; i < tam; i++){
        if(*(p+i) >= 'A' && *(p+i) <= 'Z'){
            *(p+i) = *(p+i) + 32;
        }
    }

    return p;
}

char *strchr(char *p, char c){
    int tam = strlen(p);

    for(int i = 0; i < tam; i++){
        if(*(p+i) == c){
            return p+i;
        }

    }

    return NULL;
}

char *strcat(char *p1, char *p2){
    int tam1 = strlen(p1);
    int tam2 = strlen(p2);
    int tot = tam1 + tam2
    ;

    char *junto = (char *) malloc(tot * sizeof(int));

    for(int i = 0; i < tam1; i++){
        *(junto + i) = *(p1 + i);
    }

    for(int j = 0; j < tam2; j++){
        *(junto + j + tam1) = *(p2 + j);
    }

    *(junto + tot) = '\0';
    return junto;

}

int main()
{
    char str1[] = "brenno";
    printf("%s tem %i letras\n", str1, strlen(str1));

    char str2[] = "ola a todos";
    printf("%s a copia de %s\n", strcopy(str2), str2);

    printf("%s com todas as letras maiusculas %s\n", str1, strupper(str1));

    printf("%s com todas as letras minusculas %s\n", str1, strlower(str1));


    char *resul = strchr(str1, 'm');

    if(resul == NULL){
        printf("caracter nao encontrado\n");
    }
    else{
        printf("caracter encontrado\n");
    }

    printf("juntando tudo %s\n", strcat(str1, str2));

    return 0;
}
