#include <stdio.h>
#include <string.h>

struct PontoTuristico
{
    char descricao[41];
    float latitude;
    float longitude;
    struct PontoTuristico *proximo;
};

struct PontoTuristico* criar_lista(void)
{
    return NULL;
}

struct PontoTuristico* inserir_inicio(struct PontoTuristico* cabeca)
{
    struct PontoTuristico* novo = (struct PontoTuristico*) malloc(sizeof(struct PontoTuristico));
    lerPontoTuristico(novo);
    novo->proximo = cabeca;
    return (novo);
}


void lerPontoTuristico(struct PontoTuristico *aux) {
 	printf("\nDescricao: ");
 	scanf("%[^\n]", aux->descricao);
 	fflush(stdin);
 	printf("\nLatitude: ");
 	scanf("%f", &aux->latitude);
 	fflush(stdin);
 	printf("\nLongitude: ");
 	scanf("%f", &aux->longitude);
 	fflush(stdin);
}


void imprimir(struct PontoTuristico* cabeca) {
	struct PontoTuristico* paux;
	for (paux = cabeca; cabeca != NULL; paux=paux->proximo)
		printf("%s: lat:%.2f log: %.2f\n", paux->descricao, paux->latitude, paux->longitude);
}

int main()
{
    struct PontoTuristico* cabeca;

    cabeca = criar_lista();
    cabeca = inserir_inicio(cabeca);
    imprimir(cabeca);

    return 0;
}
