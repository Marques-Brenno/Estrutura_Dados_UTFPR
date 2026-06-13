#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Bárbara, Brenno e Otávio

//Structs
typedef struct Produto {
    int codigo;
    char descricao[64];
    float preco;
    struct Produto *prox; 
} Produto;

typedef struct ItemEstoque {
    int codigo_produto;
    int quantidade;
    struct ItemEstoque *prox;
} ItemEstoque;

typedef struct Filial {
    int id_filial;
    char nome[40];
    ItemEstoque *estoque; 
    struct Filial *prox;
} Filial;

typedef struct ItemCarrinho {
    int codigo_produto;
    int qtd;
    float preco_unit; 
    struct ItemCarrinho *prox;
} ItemCarrinho;

typedef struct Carrinho {
    ItemCarrinho *itens;
    float total; 
} Carrinho;


//Funções - Produto
void carregarProduto(char* nomeArquivo, Produto *cabeca); //Feito
Produto *alocarProduto(int cod, char* desc, float preco); //Feito
void inserirProduto(Produto *cabeca, Produto* novo); //Feito
Produto *buscarProdutoPorCodigo(Produto *cabeca, int codigoBuscar); //Feito
Produto *buscarProdutoPorNome(Produto *cabeca, char* nomeBuscar); //Feito
void imprimirProdutos(Produto *cabeca); //Feito
void liberarProdutos(Produto *cabeca); //Feito

//Funções - Filiais e Item Estoque
void carregarFiliais(char* nomeArquivo, Filial *cabeca); //Feito
void carregarEstoques(Filial *cabeca, char* nomeArquivo); //Feito
Filial *alocarFilial(int id, char* nome); //Feito
void inserirFilial(Filial *cabeca, Filial *nova); //Feito
ItemEstoque *alocarItemEstoque(int cod, int qtd); //Feito
void inserirItemEstoque(ItemEstoque *cabeca, ItemEstoque *novo); //Feito
ItemEstoque *buscarEstoque(Filial *filial, int codProduto);	//Feito
Filial *buscarFilialPorId(Filial *cabeca, int id); //Feito
void atualizarEstoque(Filial *filial, int codProduto, int qtdVendida); //Feito
int verificaEstoqueFilial(Filial *filial, Carrinho *c);	//Feito
void listarFaltasFilial(Filial *filial, Carrinho *c); //Feito
void ajustarCarrinhoParaFilial(Filial *filial, Carrinho *c); //Feito
void imprimirFiliais(Filial *lista); //Feito
void liberarEstoques(ItemEstoque *cabeca); //Feito
void liberarFiliais(Filial *cabeca); //Feito

//Funções - Carrinho
void inicializarCarrinho(Carrinho *c); //Feito
ItemCarrinho *alocarItemCarrinho(int cod, int qtd, float preco); //Feito
void adicionarItemCarrinho(Carrinho *c, Produto *cabeca, int qtd); //Feito
ItemCarrinho *buscarItemCarrinho(Carrinho *c, int cod); //Feito
void removerItemCarrinho(Carrinho *c, int cod, int qtd); //Feito
void removerItemTotal(Carrinho *c, int cod); //Feito
void listarCarrinho(Carrinho *c, Produto *cabeca); //Feito 
void limparCarrinho(Carrinho *c); //Feito
void finalizarCompra(Filial *filial, Carrinho *c, Produto *cabecaProduto); //feito

//Função Relatório
void gerarRelatorio(Filial *cabecaFilial, Carrinho *c);

int main()
{
    Produto *cabecaProdutos = malloc(sizeof(Produto)); 
    if (cabecaProdutos == NULL) return 1;
    cabecaProdutos->prox = NULL;
    
    Filial *cabecaFilial = malloc(sizeof(Filial)); 
    if (cabecaFilial == NULL) return 1;
    cabecaFilial->prox = NULL;
    
    Carrinho carrinho;
    inicializarCarrinho(&carrinho);

    printf("\n--- Carregando Dados ---");
    carregarProduto("produtos_v2.txt", cabecaProdutos);
    carregarFiliais("filiais_v2.txt", cabecaFilial);
    carregarEstoques(cabecaFilial, "estoques_v2.txt");
    printf("\nDados Carregados com Sucesso!\n");

    printf("\nOla usuario, aqui vai o Menu:");

    int opc;
    do {
        printf("\n1-Pesquisar Produto.\n2-Inserir Item ao Carrinho.\n3-Remover Item do Carrinho.\n4-Listar Itens do Carrinho.\n5-Verificar Disponibilidade por Filial.\n6-Finalizar Compra.\n7-Relatorio.\n8-Sair.\nEscolha sua opcao: ");
        scanf("%d", &opc);
        
        switch(opc) {
            
            case 1:
            {
                
                int repetir = 1;

                

                printf("\n--- Catalogo de Produtos ---"); 
                imprimirProdutos(cabecaProdutos);

                while (repetir == 1) { 

                    int cn;
                    int codigoBuscar;
                    Produto *achei = NULL;
                    char nomeBuscar[64];

                    printf("\nVoce deseja pesquisar por codigo ou nome? Digite 0 - Codigo ou 1 - Nome: ");
                    scanf("%d", &cn);
                
                    if(cn == 0) {
                        printf("\nInsira o codigo do produto: ");
                        scanf("%d", &codigoBuscar);
                        achei = buscarProdutoPorCodigo(cabecaProdutos, codigoBuscar);

                        if(achei) {
                            printf("\nProduto Encontrado!");
                            printf("\nCodigo: %d", achei->codigo);
                            printf("\nDescricao: %s", achei->descricao);
                            printf("\nPreco: %.2f\n", achei->preco);
                        }
                        else {
                            printf("\nCodigo do produto nao encontrado.");
                        }

                    }

                    if(cn == 1) {
                        printf("\nInsira o nome do produto: ");
                        getchar(); //adicionado
                        scanf("%[^\n]", nomeBuscar);
                        achei = buscarProdutoPorNome(cabecaProdutos, nomeBuscar);

                        if(achei) {
                            printf("\nProduto Encontrado!");
                            printf("\nCodigo: %d", achei->codigo);
                            printf("\nDescricao: %s", achei->descricao);
                            printf("\nPreco: %.2f\n", achei->preco);
                        }
                        else {
                            printf("\nNome do produto nao encontrado.\n");
                        }

                    }

                    printf("\nDeseja pesquisar por outro produto? (1 - Sim, 0 - Nao): "); 
                    scanf("%d", &repetir);
                }

            } break;
            
            case 2:
            {
                int numProdutos;

                do{
                    int cod, qtd, i = 0;
                    Produto *prod = NULL;
                    Filial *f;
                    ItemEstoque *ie;
                    int encontrou = 0;

                    printf("\n--- Produto %d ---", i + 1);

                    printf("\nDigite o codigo do produto: ");
                    scanf("%d", &cod);

                    // 1) Buscar no catálogo
                    prod = buscarProdutoPorCodigo(cabecaProdutos, cod);
                    if (!prod) {
                        printf("\nProduto nao encontrado!\n");
                        continue;
                    }

                    printf("\nProduto: %s |  Preco: %.2f", prod->descricao, prod->preco);

                    // 2) Verificar estoque
                    f = cabecaFilial->prox;
                    while(f != NULL) {
                        ie = buscarEstoque(f, cod);
                        if (ie && ie->quantidade > 0) {
                            printf("\n-> Filial %d (%s) possui %d unidades", f->id_filial, f->nome, ie->quantidade);
                            encontrou = 1;
                        }
                        f = f->prox;
                    }

                    if (!encontrou) {
                        printf("\nNenhuma filial possui esse produto em estoque.\n");
                    }

                    // 3) Inserir no carrinho
                    printf("\nQuantidade desejada: ");
                    scanf("%d", &qtd);

                    if (qtd <= 0) {
                        printf("\nQuantidade invalida.");
                    }

                    adicionarItemCarrinho(&carrinho, prod, qtd);
                    printf("\nProduto adicionado ao carrinho!");
                    printf("\n   --> TOTAL ACUMULADO: R$ %.2f\n", carrinho.total); //adicionado

                    printf("\nDeseja adicionar mais produtos (1 - Sim / 0 - Nao) ? ");
                    scanf("%d", &numProdutos);
                    i++;

                }while(numProdutos != 0);

                printf("\nFinalizado processo de adicao ao carrinho.\n");

                

            } break;
            
            case 3:
            {
                int cod, qtd;

                if (carrinho.itens == NULL) { 
                    printf("\nCarrinho vazio. Nao ha o que remover.\n");
                    break;
                }
                printf("\n--- Remover Item do Carrinho ---");

                printf("\nDigite o codigo do produto: ");
                scanf("%d", &cod);

                ItemCarrinho *item = buscarItemCarrinho(&carrinho, cod); 
                if(item == NULL) {
                    printf("\nErro: este produto nao esta no carrinho.\n");
                    break;
                }

                printf("\nDigite a quantidade a remover: ");
                scanf("%d", &qtd);

                if (qtd <= 0) { 
                    printf("\nQuantidade invalida.\n");
                    break;
                }

                printf("\nItem removido do carrinho.");

                removerItemCarrinho(&carrinho, cod, qtd);

                printf("\n   --> NOVO TOTAL DO CARRINHO: R$ %.2f\n", carrinho.total);


            } break;
            
            case 4:
            {
                printf("\n--- Itens no Carrinho ---");
                listarCarrinho(&carrinho, cabecaProdutos);

            } break;
            
            case 5:
            {
                

                 if(carrinho.itens == NULL) {
                    printf("\nCarrinho vazio. Nao ha o que verificar.\n");
                    break;
                }

                
                printf("\n--- Verificar Disponibilidade por Filial ---\n");

                Filial *f = cabecaFilial->prox;
                
                while (f != NULL) { 
                    printf("\nFilial %d - %s", f->id_filial, f->nome);

                    if (verificaEstoqueFilial(f, &carrinho)) {
                        printf("  --> ATENDE 100%% do carrinho.");
                        
                    } else {
                        printf("  --> NAO atende totalmente o carrinho.");
                        
                    }

                    listarFaltasFilial(f, &carrinho);

                    f = f->prox;
                }

                printf("\nLembrando que voce pode escolher uma filial que nao tenha todos os produtos no estoque. Seu carrinho sera reajustado!\n");
                
                int escolha;
                printf("\n\nDigite o ID da filial desejada: ");
                scanf("%d", &escolha);

                
                Filial *escolhida = cabecaFilial->prox;
                while (escolhida && escolhida->id_filial != escolha)
                    escolhida = escolhida->prox;

                if (!escolhida) {
                    printf("\nFilial nao encontrada!\n");
                    break;
                }

                printf("\n--- Estoque da Filial %d (%s) ---\n",
                escolhida->id_filial, escolhida->nome);

                if (verificaEstoqueFilial(escolhida, &carrinho)) { 
                    printf("\nA filial escolhida ATENDE 100%% do carrinho!\n");
                } else {
                    printf("\nA filial escolhida NAO atende 100%% do carrinho!\n");
                    
                }


            } break;
            
            case 6:
            {
                

                if(carrinho.itens == NULL) {
                    printf("\nCarrinho vazio. Nao ha o que finalizar.\n");
                    break;
                }

                int filialId;
                printf("\nDigite novamente o codigo da Filial para finalizar a compra: ");
                scanf("%d", &filialId);

                Filial *filial = buscarFilialPorId(cabecaFilial, filialId);

                if (filial == NULL) {
                    printf("\nFilial com ID %d nao encontrada.\n", filialId);
                    break;
                }

                finalizarCompra(filial, &carrinho, cabecaProdutos);
                
                
            } break;
            
            case 7:
            {
                printf("\n--- Relatorio ---");

                gerarRelatorio(cabecaFilial, &carrinho);

            } break;

            case 8:
            {
                printf("\nVoce encerrou o programa...");
            } break;

            default:
            {
                printf("\nOpcao Invalida");
            } 

        }
    }
    while(opc!=8);
    
    liberarProdutos(cabecaProdutos);
    free(cabecaProdutos);
    
    liberarFiliais(cabecaFilial);
    free(cabecaFilial);

    limparCarrinho(&carrinho); 
    
    return 0;
}

//Produto
void carregarProduto(char* nomeArquivo, Produto *cabeca) {
    FILE *arq = fopen(nomeArquivo, "r");
    if(!arq){
        printf("\nErro ao abrir arquivo de produto!\n");
        return;
    }

    char linha[200];
    while(fgets(linha, sizeof(linha), arq)){
        int cod;
        char desc[64];
        float preco;

        if (sscanf(linha, "%d %s %f", &cod, desc, &preco) == 3) {
                Produto *novo = alocarProduto(cod, desc, preco);
                inserirProduto(cabeca, novo);
        }
    }

    fclose(arq);

}

Produto *alocarProduto(int cod, char* desc, float preco){
    Produto *novo = NULL;
    novo = (Produto*)malloc(sizeof(Produto));
    
    if(novo == NULL) { 
        return NULL;
    }
    
    novo->codigo = cod;
    strcpy(novo->descricao, desc);
    novo->preco = preco;
    novo->prox = NULL;
    
    return novo;
    
}

void inserirProduto(Produto *cabeca, Produto *novo) {
    if(novo == NULL) { 
        printf("\nErro: produto nao foi alocado corretamente."); 
        return; }

    novo->prox = cabeca->prox;
    cabeca->prox = novo;

}

Produto *buscarProdutoPorCodigo(Produto *cabeca, int codigoBuscar) {
    Produto *p = cabeca->prox;

    while(p) {
        if(p->codigo == codigoBuscar) {
            return p;
        }
        p = p->prox;
    }
    return NULL;
}

Produto *buscarProdutoPorNome(Produto *cabeca, char* nomeBuscar) {
    Produto *p = cabeca->prox;

    while(p) {
        if(strcmp(p->descricao, nomeBuscar) == 0 || strstr(p->descricao, nomeBuscar) != NULL) {
            return p;
        }
        p = p->prox;
    }
    return NULL;

}

void imprimirProdutos(Produto *cabeca){
    Produto *p = cabeca->prox;

    if(p == NULL) {
        printf("\nLista de produtos vazia!");
        return;
    }

    while(p) {
        printf("\nCodigo: %d", p->codigo);
        printf("\nDescricao: %s", p->descricao);
        printf("\nPreco: %.2f", p->preco);
        p = p->prox;

    }
}

void liberarProdutos(Produto *cabeca) { 
    Produto *paux = cabeca->prox;
    Produto *lixo;
    
    while(paux != NULL) {
        lixo = paux;
        paux = paux->prox;
        free(lixo);
    }
    cabeca->prox = NULL;
    printf("\nProdutos Liberados.");
}

//Filiais e Estoque1
void carregarFiliais(char* nomeArquivo, Filial *cabeca) {
    FILE *arq = fopen(nomeArquivo, "r");
    if(!arq){
        printf("\nErro ao abrir arquivo de filiais!\n");
        return;
    }

    char linha[200];
    while(fgets(linha, sizeof(linha), arq)){
        int id;
        char nome[40];

        if (sscanf(linha, "%d %39[^\n]", &id, nome) == 2) { 
            Filial *novo = alocarFilial(id, nome);
            inserirFilial(cabeca, novo);
        }
    }

    fclose(arq);
}
Filial *alocarFilial(int id, char* nome){
    Filial *novo = NULL;
    novo = (Filial*)malloc(sizeof(Filial));
    
    if(novo == NULL) { 
        return NULL;
    }
    
    novo->id_filial = id;
    strcpy(novo->nome, nome);
    
    novo->estoque = malloc(sizeof(ItemEstoque)); 
    novo->estoque->prox = NULL;
    
    novo->prox = NULL;
    
    return novo;
    
}

ItemEstoque* alocarItemEstoque(int cod, int qtd){
    ItemEstoque *novo = NULL;
    novo = (ItemEstoque*)malloc(sizeof(ItemEstoque));
    
    if(novo == NULL) { 
        return NULL;
    }
    
    novo->codigo_produto = cod;
    novo->quantidade = qtd;
    novo->prox = NULL;
    
    return novo;
}

void inserirFilial(Filial *cabeca, Filial *nova) {
    if(nova == NULL) {
        printf("\nErro: filial não foi alocada corretamente.");
        return; }

    nova->prox = cabeca->prox;
    cabeca->prox = nova;

}

void carregarEstoques(Filial *cabeca, char* nomeArquivo){
    FILE *arq = fopen(nomeArquivo, "r");
    if(!arq){
        printf("\nErro ao abrir arquivo de estoques!\n");
        return;
    }

    char linha[200];
    while(fgets(linha, sizeof(linha), arq)){
        int id_filial;
        int cod_produto;
        int qtd;

        if (sscanf(linha, "%d %d %d", &id_filial, &cod_produto, &qtd) == 3) { 
            Filial *filial = cabeca->prox;
            while(filial) {
                if(filial->id_filial == id_filial) {
                    ItemEstoque *novo = alocarItemEstoque(cod_produto, qtd);
                    inserirItemEstoque(filial->estoque, novo);
                    break;
                }
                filial = filial->prox;
            }
        }
    }    

    fclose(arq);
}

void inserirItemEstoque(ItemEstoque *cabeca, ItemEstoque *novo) {
    if(novo == NULL) {
        printf("\nErro: item de estoque não foi alocado corretamente.");
        return; }

    novo->prox = cabeca->prox;
    cabeca->prox = novo;

}

ItemEstoque *buscarEstoque(Filial *filial, int codProduto) { 
    if (filial->estoque->prox == NULL){
        return NULL;
    }
    ItemEstoque *aux = filial->estoque->prox;
    while (aux){
        if (aux->codigo_produto == codProduto){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;

}

Filial *buscarFilialPorId(Filial *cabeca, int id){
    Filial *f = cabeca->prox;

    while(f) {
        if(f->id_filial == id) {
            return f;
        }
        f = f->prox;
    }
    return NULL;
}

void atualizarEstoque(Filial *filial, int codProduto, int qtdVendida) { 
    if(filial == NULL) {
        printf("\nerro: Filial invalida para atualizar no estoque.\n");
        return;
    }

    ItemEstoque *item = buscarEstoque(filial, codProduto);

    if(item == NULL) {
        printf("\nErro: Produto %d nao encontrado no estoque da filial %d.\n", codProduto, filial->id_filial);
        return;
    }

    if(item->quantidade < qtdVendida) {
        printf("\nErro: Tentativa de vender mais do que o disponivel no estoque.\n");
        return;
    }

    item->quantidade -= qtdVendida;

    printf("\nEstoque da Filial %d (%s) atualizado. Nova quantidade do produto %d = %d.\n", filial->id_filial, filial->nome, item->codigo_produto, item->quantidade); 

}

int verificaEstoqueFilial(Filial *filial, Carrinho *c){
    ItemCarrinho *item = c->itens;
    while (item){
        ItemEstoque *estoqueItem = buscarEstoque(filial, item->codigo_produto);
        if (estoqueItem == NULL || estoqueItem->quantidade < item->qtd){
            return 0;
        }
        item = item->prox;
    }
    return 1;
}

void listarFaltasFilial(Filial *filial, Carrinho *c){
    if (c == NULL || c->itens == NULL){
        printf("\nCarrinho vazio.");
        return;
    }

    int atendeTotalmente = verificaEstoqueFilial(filial, c);

    if (atendeTotalmente == 1){
        printf("\n[OK] A filial %d (%s) possui TODOS os itens do carrinho.", filial->id_filial, filial->nome);

        printf("\n--- Quantidades Disponiveis ---"); 

        ItemCarrinho *item = c->itens;

        while (item){
            ItemEstoque *estoqueItem = buscarEstoque(filial, item->codigo_produto);
            int qtdNaLoja = (estoqueItem == NULL) ? 0 : estoqueItem->quantidade;

            printf("\n -> Prod Cod %d: Cliente quer %d, Loja tem %d.",
                   item->codigo_produto,
                   item->qtd,
                   qtdNaLoja);

            item = item->prox;
        }

        printf("\n--------------------------------\n");
        return; // até aqui
    }
    else {
        printf("\n--- ATENCAO: Itens em Falta na Filial %d (%s) ---", filial->id_filial, filial->nome);
        
        ItemCarrinho *item = c->itens;
        while (item){
            ItemEstoque *estoqueItem = buscarEstoque(filial, item->codigo_produto);
            
            int qtdNaLoja = (estoqueItem == NULL) ? 0 : estoqueItem->quantidade;

            if (qtdNaLoja < item->qtd){
                int falta = item->qtd - qtdNaLoja;
                printf("\n -> Prod Cod %d: Voce quer %d, Loja tem %d. (Faltam: %d)", 
                       item->codigo_produto, 
                       item->qtd, 
                       qtdNaLoja, 
                       falta);
            }
            item = item->prox;
        }
        printf("\n-------------------------------------------------\n");
    }
}

void ajustarCarrinhoParaFilial(Filial *filial, Carrinho *c){
    if (c == NULL || c->itens == NULL){
        printf("\nCarrinho vazio.");
        return;
    }

    ItemCarrinho *item = c->itens;
    ItemCarrinho *proxItem = NULL;
    while (item){
        proxItem = item->prox;
        ItemEstoque *estoqueItem = buscarEstoque(filial, item->codigo_produto);
        if (estoqueItem == NULL || estoqueItem->quantidade < item->qtd){
            int qtdDisponivel = (estoqueItem == NULL) ? 0 : estoqueItem->quantidade;
            printf("\nAjustando item codigo %d: Quantidade solicitada %d, Quantidade disponivel %d.", item->codigo_produto, item->qtd, qtdDisponivel);
            c->total -= item->preco_unit * (item->qtd - qtdDisponivel);
            item->qtd = qtdDisponivel;
            if (item->qtd == 0){
                removerItemTotal(c, item->codigo_produto);
            }
        }
        item = proxItem;
    }
}

void liberarEstoques(ItemEstoque *cabeca){
    ItemEstoque *paux = cabeca->prox;
    ItemEstoque *lixo;
    
    while(paux != NULL) {
        lixo = paux;
        paux = paux->prox;
        free(lixo);
    }
    cabeca->prox = NULL;
    
}

void liberarFiliais(Filial *cabeca){
    Filial *paux = cabeca->prox;
    Filial *lixo;
    
    while(paux != NULL) {
        liberarEstoques(paux->estoque); 
        free(paux->estoque);

        lixo = paux;
        paux = paux->prox;
        free(lixo);
    }
    cabeca->prox = NULL;
    printf("\nFiliais e estoques Liberados.");
}

void imprimirFiliais(Filial *lista){
    if (lista == NULL){
        printf("\nLista de filiais vazia.");
        return;
    }
    Filial *aux = lista->prox;
    while (aux){
        printf("\nFilial id %d: %s", aux->id_filial, aux->nome);
        aux = aux->prox;
    }
}


//Carrinho e Item Carrinho
void inicializarCarrinho(Carrinho* c){ 
    c->itens = NULL;
    c->total = 0;
}
ItemCarrinho *alocarItemCarrinho(int cod, int qtd, float preco){
    ItemCarrinho *novo = NULL;
    novo = (ItemCarrinho*)malloc(sizeof(ItemCarrinho));
    
    if(novo == NULL) { 
        return NULL;
    }
    
    novo->codigo_produto = cod;
    novo->qtd = qtd;
    novo->preco_unit = preco;
    novo->prox = NULL;
    
    return novo;
    
}

ItemCarrinho *buscarItemCarrinho(Carrinho *c, int cod){
    ItemCarrinho *aux = c->itens;
    while (aux){
        if (aux->codigo_produto == cod){
            return aux;
        }
        aux = aux->prox;
    }
    return NULL;
}

void adicionarItemCarrinho(Carrinho *c, Produto *p, int qtd){
    if (p == NULL) {
        printf("\nProduto invalido.");
        return;
    }
    if (qtd <= 0){
        printf("\nA quantidade deve ser maior que 0.");
        return;
    }

    ItemCarrinho *item = buscarItemCarrinho(c, p->codigo);
    if (item){
        item->qtd += qtd;
        c->total += p->preco * qtd;
        return;

    }
    
    ItemCarrinho *novoItem = alocarItemCarrinho(p->codigo, qtd, p->preco);
    if (novoItem == NULL){
            printf("\nErro ao alocar o item.");
            return;
    }

    ItemCarrinho *aux = c->itens; 
    c->itens = novoItem;
    novoItem->prox = aux;
    
    c->total += p->preco * qtd;
   
}

void removerItemTotal(Carrinho *c, int cod){
    if (c->itens == NULL){
        printf("\nLista vazia.");
        return;
    }

    ItemCarrinho *atual = c->itens;
    ItemCarrinho *anterior = NULL;

    while (atual != NULL && atual->codigo_produto != cod){
        anterior = atual;
        atual = atual->prox;
    }

    if (anterior == NULL) c->itens = atual->prox;
    else anterior->prox = atual->prox;

    free(atual);
}

void removerItemCarrinho(Carrinho *c, int cod, int qtd) {
    if (c->itens == NULL) {
        printf("\nCarrinho vazio.");
        return;
    }
    if (qtd <= 0) {
        printf("\nQuantidade a remover deve ser positiva.");
        return;
    }

    ItemCarrinho *item = buscarItemCarrinho(c, cod);

    if (item) {
        int qtdOriginal = item->qtd;
        int qtdRemovida;

        if (qtd >= item->qtd) {
            item->qtd = 0;
            qtdRemovida = qtdOriginal;
        } else {
            item->qtd -= qtd;
            qtdRemovida = qtd;
        }

        c->total -= (item->preco_unit * qtdRemovida);

        if (item->qtd == 0) {
            removerItemTotal(c, cod);
        }

    } else {
        printf("\nItem nao encontrado no carrinho.\n");
    }

    if (c->total < 0.0f) c->total = 0.0f;
}

void listarCarrinho(Carrinho *c, Produto *cabeca){ 
    if (c->itens == NULL){
        printf("\nCarrinho vazio.\n");
        return;
    }
    
    ItemCarrinho *item = c->itens;
    int contador = 1;
    while (item) {
        Produto *p = buscarProdutoPorCodigo(cabeca, item->codigo_produto);
        printf("\nItem %d:\nCodigo: %d\nDescricao: %s\nValor Unitario: R$%.2f\nQuantidade: %d\n", contador, item->codigo_produto, p->descricao, item->preco_unit, item->qtd);
        contador += 1;
        item = item->prox;
    }
    printf("\nValor total: %.2f\n", c->total);
}

void limparCarrinho(Carrinho *c){
    if (c->itens == NULL){
        printf("\nCarrinho vazio.\n");
        return;
    }
    while (c->itens != NULL){
        removerItemTotal(c, c->itens->codigo_produto);
    }
    c->total = 0;
}

void finalizarCompra(Filial *filial, Carrinho *c, Produto *cabecaProdutos){
    if (c == NULL || c->itens == NULL){
        printf("\nCarrinho vazio. Nao ha o que finalizar.\n");
        return;
    }

    if (!verificaEstoqueFilial(filial, c)){
        printf("\nNao ha estoque suficiente na filial %d (%s) para finalizar a compra.\n", filial->id_filial, filial->nome);
        ajustarCarrinhoParaFilial(filial, c);
        printf("\nCarrinho ajustado para a disponibilidade da filial.\n");
        listarCarrinho(c, cabecaProdutos);
    }

    ItemCarrinho *item = c->itens;
    while (item){
        atualizarEstoque(filial, item->codigo_produto, item->qtd);
        item = item->prox;
    }

    printf("\nCompra finalizada com sucesso na filial %d (%s). \nTotal pago: R$ %.2f\n", filial->id_filial, filial->nome, c->total);
    limparCarrinho(c);
}

//Relatório
void gerarRelatorio(Filial *cabecaFilial, Carrinho *c) {
    // 1. Validação básica
    if (cabecaFilial == NULL || cabecaFilial->prox == NULL) {
        printf("\nNao ha filiais cadastradas para gerar relatorio.\n");
        return;
    }

    // 2. Tenta abrir/criar o arquivo de saída
    char *nomeArquivo = "estoques_atualizado.txt";
    FILE *arq = fopen(nomeArquivo, "w");
    
    if (arq == NULL) {
        printf("\nErro fatal: Nao foi possivel criar o arquivo %s\n", nomeArquivo);
        return;
    }

    printf("\n========================================================");
    printf("\n            RELATORIO GERAL DE ESTOQUES");
    printf("\n========================================================");

    Filial *f = cabecaFilial->prox; 

    while (f != NULL) {
        printf("\n\n[FILIAL ID: %d] - %s", f->id_filial, f->nome);
        printf("\n--------------------------------------------------------");

        ItemEstoque *ie = f->estoque->prox;

        if (ie == NULL) {
            printf("\n   (Sem itens em estoque)");
        }

        while (ie != NULL) {
            printf("\n   -> Cod: %d | Qtd: %d", ie->codigo_produto, ie->quantidade);

            fprintf(arq, "%d %d %d\n", f->id_filial, ie->codigo_produto, ie->quantidade);

            ie = ie->prox;
        }
        f = f->prox;
    }

    fclose(arq);

    printf("\n\n========================================================");
    printf("\nSUCESSO! O arquivo '%s' foi gerado.", nomeArquivo);
    printf("\nTodas as baixas de estoque foram salvas.");
    printf("\n========================================================\n");

    if (c != NULL && c->itens != NULL) {
        printf("\nobs: Ainda existe um carrinho aberto com total R$ %.2f\n", c->total);
    }
}
