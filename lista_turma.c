#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct aluno
{
    int codigo;
    char nome[30];
    float nota;
    struct aluno *proximo;
};

struct aluno *criar_lista(void)
{
    return NULL;
}

void lerAluno(struct aluno *aux)
{
    printf("\nCodigo: ");
    scanf("%d", &aux->codigo);
    fflush(stdin);
    printf("\nNome: ");
    scanf("%[^\n]", aux->nome);
    fflush(stdin);
    printf("\nNota do aluno: ");
    scanf("%f", &aux->nota);
    fflush(stdin);
}

struct aluno *inserir_inicio(struct aluno *cabeca)
{
    struct aluno *novo = (struct aluno*) malloc(sizeof(struct aluno));
    lerAluno(novo);
    novo->proximo = cabeca;
    return (novo);
}

float calcula_media(struct aluno *cabeca)
{
    struct aluno *paux;
    int numero_alunos = 0;
    float soma_notas = 0;
	float media = 0;
    for (paux = cabeca; paux != NULL; paux = paux->proximo) {
	    numero_alunos++;
        soma_notas += paux->nota;
    }
    media = (soma_notas / numero_alunos);
    return media;
}


void imprimir(struct aluno *cabeca)
{
    struct aluno *paux;
    for (paux = cabeca; paux != NULL; paux = paux->proximo)
        printf("Codigo: %d Nome:%s Nota: %.2f\n", paux->codigo, paux->nome, paux->nota); 
}

int main()
{
// Declara as duas listas de alunos
    struct aluno *l1;
    struct aluno *l2;
    float media_turma_1;
    float media_turma_2;
    
// Cria as duas listas de aluno
    l1 = criar_lista();
    l2 = criar_lista();
    
// Aceita os alunos da turma 1
    printf("TURMA 1");
	l1 = inserir_inicio(l1);
    l1 = inserir_inicio(l1);
    l1 = inserir_inicio(l1);
	
// Aceita os alunos da turma 2
    printf("TURMA 2");
    l2 = inserir_inicio(l2);
    l2 = inserir_inicio(l2);
    l2 = inserir_inicio(l2);

// Calcula a média das turmas
    media_turma_1 = calcula_media(l1);
    media_turma_2 = calcula_media(l2);
    
// Imprime os resultados
    printf("Media da turma 1: %.2f\n", media_turma_1);
    printf("Media da turma 2: %.2f\n", media_turma_2);
	
// Verifica qual turma se saiu melhor
	if (media_turma_1 > media_turma_2) {
	    printf("A turma 1 se saiu melhor!\n");
	} else if (media_turma_1 < media_turma_2) {
	    printf("A turma 2 se saiu melhor!\n");
	} else {
	    printf("As duas turmas se sairam com o mesmo aproveitamento!\n");
	}
	
// Libera as listas da memória
	free(l1);
	free(l2);

    return 0;
}
