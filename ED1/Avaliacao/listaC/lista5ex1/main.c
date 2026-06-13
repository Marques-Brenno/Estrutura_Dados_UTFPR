#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct funcionario{
    char cpf[12];
    char nomeCompleto[25];
    char telefone[15];
    char email[25];
    double salario;
} Funcionario;

typedef struct departamento{
    char setor[50];
    int qtd_funcionarios;
    Funcionario *funcionarios;
} Departamento;

void cadFunci(Departamento *cabeca);
void imprimir(Departamento *cabeca);

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    Departamento *cabeca = NULL;
    cabeca = (Departamento *) malloc(sizeof(Departamento));

    printf("\nDite o nome do setor: ");
    fgets(cabeca->setor, 50, stdin);
    cabeca->setor[strcspn(cabeca->setor, "\n")] = 0;

    printf("\nDigite a quantidade de funcionarios: ");
    scanf("%d", &cabeca->qtd_funcionarios);

    limpar_buffer();

    cabeca->funcionarios = (Funcionario *) malloc(sizeof(Funcionario) * cabeca->qtd_funcionarios);

    cadFunci(cabeca);
    imprimir(cabeca);



    free(cabeca->funcionarios);
    cabeca->funcionarios = NULL;

    free(cabeca);
    cabeca = NULL;

    return 0;
}


void cadFunci(Departamento *cabeca){
    for(int i = 0; i < cabeca->qtd_funcionarios; i++){
        printf("\n----------------------------------------------------");
        printf("\nDigite o CPF do %d funcionario (apenas numeros): ", i+1);
        fgets(cabeca->funcionarios[i].cpf, 12, stdin);
        cabeca->funcionarios[i].cpf[strcspn(cabeca->funcionarios[i].cpf, "\n")] = 0;

        printf("\nDigite o Nome completo do %d funcionario: ", i+1);
        fgets(cabeca->funcionarios[i].nomeCompleto, 15, stdin);
        cabeca->funcionarios[i].nomeCompleto[strcspn(cabeca->funcionarios[i].nomeCompleto, "\n")] = 0;

        printf("\nDigite o telefone do %d funcionario: ", i+1);
        fgets(cabeca->funcionarios[i].telefone, 25, stdin);
        cabeca->funcionarios[i].telefone[strcspn(cabeca->funcionarios[i].telefone, "\n")] = 0;

        printf("\nDigite o email do %d funcionario: ", i+1);
        fgets(cabeca->funcionarios[i].email, 25, stdin);
        cabeca->funcionarios[i].email[strcspn(cabeca->funcionarios[i].email, "\n")] = 0;


        printf("\nDigite o salario do %d funcionario: ", i+1);
        scanf("%lf", &cabeca->funcionarios[i].salario);

    }
    printf("\n----------------------------------------------------");
    printf("\nFuncionarios cadastrados");
    printf("\n----------------------------------------------------");
}

void imprimir(Departamento *cabeca){
    printf("\nO setor %s tem %d funcionarios", cabeca->setor, cabeca->qtd_funcionarios);

    for(int i = 0; i < cabeca->qtd_funcionarios; i++){
        printf("\n----------------------------------------------------");
        printf("\nInformacoes do %d funcionario", i+1);
        printf("\nCPF: %s",cabeca->funcionarios[i].cpf);
        printf("\nNome completo: %s",cabeca->funcionarios[i].nomeCompleto);
        printf("\nTelefone: %s",cabeca->funcionarios[i].telefone);
        printf("\nEmail: %s",cabeca->funcionarios[i].email);
        printf("\nSalario: %.2lf",cabeca->funcionarios[i].salario);
    }
    printf("\n----------------------------------------------------");
}
