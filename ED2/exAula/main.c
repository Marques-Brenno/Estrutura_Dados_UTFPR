#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int chave;
    struct Node *esq, *dir;
} Node;

Node* criarNode(int k) {
    Node *novoNode = (Node *)malloc(sizeof(Node));
    novoNode->chave = k;
    novoNode->esq = novoNode->dir = NULL;
    return novoNode;
}

void addNum(Node **raiz, int k) {
    if (*raiz == NULL) {
        *raiz = criarNode(k);
    } else if (k < (*raiz)->chave) {
        addNum(&(*raiz)->esq, k);
    } else {
        addNum(&(*raiz)->dir, k);
    }
}

Node* busca(Node *raiz, int k) {
    if (raiz == NULL || raiz->chave == k)
        return raiz;
    if (k < raiz->chave)
        return busca(raiz->esq, k);
    else
        return busca(raiz->dir, k);
    return busca(raiz->dir, k);
}


int main() {
    Node *raiz = NULL;
    addNum(&raiz, 50);
    addNum(&raiz, 75);
    addNum(&raiz, 15);
    addNum(&raiz, 12);
    addNum(&raiz, 18);
    addNum(&raiz, 89);
    addNum(&raiz, 40);
    Node *resultado = busca(raiz, 40);
    if (resultado != NULL) {
        printf("Elemento encontrado: %d\n", resultado->chave);
        printf("Endereco do elemento: %p\n", resultado);
    } else {    
        printf("Elemento não encontrado.\n");
    }

    return 0;
}