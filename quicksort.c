// Trabalho Final Estrutura de Dados I - Algoritmo quicksort
// Gustavo André Simon

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Define constante para tamanho máximo do vetor e numero para geração de vetor aleatorio
#define MAX 10
#define NUM_ALEAT 10

// Função para ordenação do vetor
void quicksort(int *vetor, int posicao_inicial, int posicao_final) {
// Declara variáveis de trabalho
    int i = posicao_inicial, j = posicao_final, auxiliar = 0;
// Atribui para x o valor da posição do pivô
    int x = vetor[(posicao_inicial + posicao_final) / 2];
// Enquanto a posição inicial for menor ou igual a posição final
    while(i <= j) {
// Procura a primeira posição do vetor da esquerda que é maior que o valor do que o pivô
        while(vetor[i] < x && i < posicao_final) {
            i++;
        }
// Procura a primeira posição do vetor da direita que é menor que o valor do que o pivô
        while(vetor[j] > x && j > posicao_inicial) {
            j--;
        }
// Se a posição incicial for menor que a final, faz a troca dos valores
        if(i <= j) {
            auxiliar = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = auxiliar;
            i++;
            j--;
        }
    }
// Se ainda não finalizou a ordenação, chama recursivamente o algoritmo de ordenação para ordenar as demais fraçoes do vetor
    if(j > posicao_inicial) {
        quicksort(vetor, posicao_inicial, j);
    }
// Se ainda não finalizou a ordenação, chama recursivamente o algoritmo de ordenação para ordenar as demais fraçoes do vetor
    if(i < posicao_final) {
        quicksort(vetor, i, posicao_final);
    }
}

// Função para preencher o vetor com valores aletórios
void monta_vetor(int vetor[]) {
    int i;
    srand(time(NULL));
    for (i=0; i<MAX; i++)
        vetor[i] = rand()%(NUM_ALEAT+1);
}

int main() {
// Define o vetor e variável para iterar o vetor ordenado
	int i, vetor[MAX] = {9,8,7,6,5,4,3,2,1,0};
// Variáveis com o valor do início e fim para calcular o tempo de execução
	clock_t inicio, fim;
    double diferenca;
//    monta_vetor(vetor);
// Salva o valor inicial da execução 
	inicio = clock()/(CLOCKS_PER_SEC/1000);
// Ordena o vetor	
	quicksort(vetor, 0, MAX - 1);	
// Salva o valor final da execução 
	fim = clock()/(CLOCKS_PER_SEC/1000);
// Calcula a diferença de tempo, para saber quanto tempo levou para executar o algoritmo
	diferenca = fim - inicio;
// Imprime o vetor ordenado
    for (i=0; i<MAX; i++) {
    	printf("%d ", vetor[i]);
	}
	printf("\n");
// Imprime o tempo de execução do algoritmo em milisegundos
	printf("Tempo em ms: %10.4f", diferenca);	
}


