// Trabalho Final Estrutura de Dados I - Algoritmo quicksort
// Gustavo Andr� Simon

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constante para tamanho m�ximo do vetor e numero para gera��o de vetor aleatorio
#define MAX 10
#define NUM_ALEAT 10

// Fun��o para ordena��o do vetor
void quicksort(int *vetor, int posicao_inicial, int posicao_final) {
// Declara vari�veis de trabalho
    int i = posicao_inicial, j = posicao_final, auxiliar = 0;
// Atribui para x o valor da posi��o do piv�
    int x = vetor[(posicao_inicial + posicao_final) / 2];
// Enquanto a posi��o inicial for menor ou igual a posi��o final
    while(i <= j) {
// Procura a primeira posi��o do vetor da esquerda que � maior que o valor do que o piv�
        while(vetor[i] < x && i < posicao_final) {
            i++;
        }
// Procura a primeira posi��o do vetor da direita que � menor que o valor do que o piv�
        while(vetor[j] > x && j > posicao_inicial) {
            j--;
        }
// Se a posi��o incicial for menor que a final, faz a troca dos valores
        if(i <= j) {
            auxiliar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = auxiliar;
            i++;
            j--;
        }
    }
// Se ainda n�o finalizou a ordena��o, chama recursivamente o algoritmo de ordena��o para ordenar as demais fra�oes do vetor
    if(j > posicao_inicial) {
        quicksort(vetor, posicao_inicial, j);
    }
// Se ainda n�o finalizou a ordena��o, chama recursivamente o algoritmo de ordena��o para ordenar as demais fra�oes do vetor
    if(i < posicao_final) {
        quicksort(vetor, i, posicao_final);
    }
}

// Fun��o para preencher o vetor com valores alet�rios
void monta_vetor(int vetor[]) {
    int i;
    srand(time(NULL));
    for (i=0; i<MAX; i++)
        vetor[i] = rand()%(NUM_ALEAT+1);
}

int main() {
// Define o vetor e vari�vel para iterar o vetor ordenado
	int i, vetor[MAX] = {9,8,7,6,5,4,3,2,1,0};
// Vari�veis com o valor do in�cio e fim para calcular o tempo de execu��o
	clock_t inicio, fim;
    double diferenca;
//    monta_vetor(vetor);
// Salva o valor inicial da execu��o 
	inicio = clock()/(CLOCKS_PER_SEC/1000);
// Ordena o vetor	
	quicksort(vetor, 0, MAX - 1);	
// Salva o valor final da execu��o 
	fim = clock()/(CLOCKS_PER_SEC/1000);
// Calcula a diferen�a de tempo, para saber quanto tempo levou para executar o algoritmo
	diferenca = fim - inicio;
// Imprime o vetor ordenado
    for (i=0; i<MAX; i++) {
    	printf("%d ", vetor[i]);
	}
	printf("\n");
// Imprime o tempo de execu��o do algoritmo em milisegundos
	printf("Tempo em ms: %10.4f", diferenca);	
}


