#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct colaborador {
  char cpf[12];
  char nome[41];
  float salario;
  struct colaborador* prox;
};

struct colaborador* criar (void) {
  return NULL;       
}

struct colaborador* inserir_inicio (struct colaborador* l, char cpf[], char nome[], float salario) {
  struct colaborador* novo = (struct colaborador*) malloc(sizeof(struct colaborador));
  strcpy(novo->cpf,cpf);
  strcpy(novo->nome,nome);
  novo->salario = salario;
  novo->prox = l;
  return novo;                                 
}

void imprimir (struct colaborador* l) {
    struct colaborador* p;
    for (p = l; p != NULL; p = p->prox) {
        printf("Codigo = %s\t", p->cpf);
        printf("Nome = %s\t", p->nome);
        printf("Salario = %.2f\n", p->salario);
    }                   
}
/*
int main(void) {
    struct colaborador *colaborador;
    colaborador = (struct colaborador *) malloc(5 * sizeof(struct colaborador));
    colaborador = criar();
    colaborador = inserir_inicio(colaborador,"11111111111","Ian Anderson",3000.99);
    colaborador = inserir_inicio(colaborador,"22222222222","Robert Plant",5500.99);
    imprimir(colaborador);
    return 0;
} */

int main(void) {
    struct colaborador *colaborador;
    colaborador = (struct colaborador *) malloc(5 * sizeof(struct colaborador));
    int i;
    for (i=0;1<2;i++){
        printf("Digite o CPF do colaborador %d: ",i+1);
        scanf("%s", colaborador[i].cpf);
        printf("Digite o Nome do colaborador %d: ",i+1);
        scanf("%s", colaborador[i].nome);
        fflush(stdin);
        printf("Digite o salario do colaborador %d: ", i+1);
        scanf("%f", &colaborador[i].salario);
    } 
    for (i = 0; i < 2 ;i++) {
        printf("\nColaborador %d CPF: %s", i+1, colaborador[i].cpf);
        printf("\nColaborador %d NOME: %s", i+1, colaborador[i].nome);
        printf("\nColaborador %d SALARIO: %.2f", i+1, colaborador[i].salario);
    }
}