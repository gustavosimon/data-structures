// Trabalho Final Estrutura de Dados I - Algoritmo quicksort
// Gustavo Andr� Simon

#include <stdio.h>
#include <stdlib.h>

// Define constante para tamanho m�ximo do vetor
#define MAX 10

// Fun��o para ordena��o do vetor
void quicksort(int *vetor, int posicao_inicial, int posicao_final) {
// Declara vari�veis de trabalho
    int i = posicao_inicial, j = posicao_final, auxiliar = 0;
// Atribui para x o valor da posi��o central do vetor
    int x = vetor[(posicao_inicial + posicao_final) / 2];
// Enquanto a posi��o inicial for menor ou igual a posi��o final
    while(i <= j) {
// Procura a primeira posi��o do vetor da esquerda que � maior que o valor do centro do vetor
        while(vetor[i] < x && i < posicao_final) {
            i++;
        }
// Procura a primeira posi��o do vetor da direita que � menor que o valor do centro do vetor
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
// Se ainda n�o finalizou a ordena��o, chama recursivamente o algoritmo de ordena��o para ordenar as dmeais fra�oes do vetor
    if(j > posicao_inicial) {
        quicksort(vetor, posicao_inicial, j);
    }
// Se ainda n�o finalizou a ordena��o, chama recursivamente o algoritmo de ordena��o para ordenar as dmeais fra�oes do vetor
    if(i < posicao_final) {
        quicksort(vetor, i, posicao_final);
    }
}

int main() {
	int i, vetor[MAX] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
// Ordena o vetor	
	quicksort(vetor, 0, MAX - 1);	
// Imprime os valores ordenadods	
	printf("Valores ordenados");
	for(i = 0; i < MAX; i++) {
 		printf("\n%d", vetor[i]);
	}
}


