// Prova II - Estrutura de dados  I
// Gustavo André Simon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VETOR 101

// Estrutura de um caracter
struct caracter {
	char car;
	struct caracter *prox;
};
typedef struct caracter TipoCaracter;

// Estrutura da fila de caracteres
struct fila {
    caracter caracteres[MAX_VETOR];
    int inicio;
    int fim;
};
typedef struct fila TipoFila;

// Estrutura de um digito
struct digito {
    char digito;
};
typedef struct digito TipoDigito;

// Estrutura de pilha de digitos
struct pilha {
    TipoDigito digito[MAX_VETOR];
    int topo;
};
typedef struct pilha TipoPilha;

// Cria a fila de caracteres
TipoFila criar(TipoFila fila) {
    fila.inicio = -1;
    fila.fim = -1;
    return fila;
}

// Verifica se a fila de caracteres está vazia
int verificar_vazia(TipoFila fila) {
    if (fila.inicio < 0 || fila.inicio > fila.fim)
        return 1;
    else
        return 0;
}

// Adiciona um caracter na fila
TipoFila adicionar_fila(TipoCaracter car, TipoFila fila) {
    if (verificar_vazia(fila)) { // primeiro elemento da fila sendo adicionado
        fila.caracteres[++fila.fim] = car;
        fila.inicio++;
    }
    else
        if (fila.fim < MAX_VETOR - 1)
            fila.caracteres[++fila.fim] = car;
        else
            printf("Overflow !!!\n");
    return fila;
}

// Cria a pilha de digitos
TipoPilha criar(TipoPilha pilha) {
    pilha.topo = 0;
    return pilha;
}

// Verifica se a pilha de digitos está vazia
int verificar_vazia(TipoPilha pilha) {
    return !pilha.topo;
}

// Empilha um nodo na pilha de digitos
TipoPilha push(TipoDigito digito, TipoPilha pilha) {
    if (pilha.topo >= 0 && pilha.topo < MAX_VETOR)
        pilha.digito[pilha.topo++] = digito;
     else
        printf("FORA DOS LIMITES DA PILHA !!!\n");
    return pilha;
}

// Retorna se o caracter passado por parâmetro é um digito
bool ehDigito(char digito) {
	
	if (digito >= 48 && digito <= 57) {
		return true;
	} 
	return false;
}

void imprime_vetor(char* vetor) {
// Declara um tipo caracter
	TipoCaracter car;
// Declara a fila de caracteres
	TipoFila fila;
// Declara um tipo digito
    TipoDigito digito;
// Declara a pilha de digitos
    TipoPilha pilha;
// Cria a fila
	fila = criar(fila);
// Cria a pilha
    pilha = criar(pilha);
// Percorre o vetor recebido por parâmetro, verifica se é um digito e adiciona na estrutura (FIFO ou LIFO) correta
	for (int i=0; i < 10; i++) {
// Se é um digito, adiciona na pilha
		if (ehDigito(vetor[i])) {
			digito.digito = vetor[i];
			pilha = push(digito, pilha);
// Do contrário, adiciona na fila
		} else {
			car.car = vetor[i];
			fila = adicionar_fila(car, fila);
		}
	}
    
// Percorre a fila imprimindo os elementos    
	int inicio_fila = fila.inicio;
    while (inicio_fila <= fila.fim) {
        printf(" %c", fila.caracteres[inicio_fila].car);
        inicio_fila++;
    }
// Percorre a pilha imprimindo os elementos
    int topo_pilha = pilha.topo - 1;
    while (topo_pilha >= 0) {
        printf("%c ", pilha.digito[topo_pilha].digito);
        topo_pilha--;
    }
}

int main() {
// Declara o vetor 1
	char vetor1[MAX_VETOR] = {'A', '1', 'E', '5', 'T', '7', 'W', '8', 'G'};
// Imprime o vetor
	imprime_vetor(vetor1);
	printf("\n");
// Declara o vetor 2
	char vetor2[MAX_VETOR] = {'3', 'C', '9', 'H', '4', 'Q', '6'};
// Imprime o vetor
	imprime_vetor(vetor2);
    return 0;
}
