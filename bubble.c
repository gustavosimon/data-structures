#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>


void bubblesort(int x[]) {
	bool trocou = true;
	int i = 0;
	int aux = 0;

	for(i=0; i < 10; i++){
		printf("%d", x[i]);
	}

	printf("\n");

	do {
		trocou = false;
		for(i=0; i < 9; i++){
			if (x[i] > x[i + 1]) {
				aux = x[i+1];
				x[i+1] = x[i];
				x[i] = aux;
				trocou = true;
			}
		}
		
	} while (trocou);
	
	for(i=0; i < 10; i++){
		printf("%d", x[i]);
	}

}


int main() {

	int vetor[10] = {9,8,7,6,5,4,3,2,1,0};
	
	bubblesort(vetor);

	return 0;
}












