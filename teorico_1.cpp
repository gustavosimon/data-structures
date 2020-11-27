#include <stdio.h>

#define TAM 6

void sort1(int A[]) {

    int i, j, k, aux;

    for (i=0; i< TAM; i++) {

        k = i;

        for (j=i+1; j< TAM; j++)

            if (A[j] < A[k])

                k = j; 

        aux = A[k];

        A[k] = A[i];

        A[i] = aux;  

        for (aux=0;aux<TAM;aux++)

            printf("%d\t", A[aux]);

        printf("\n");

    }

}

int main() {

    int A[TAM] = {5,6,4,3,1,2};

    sort1(A);

}
