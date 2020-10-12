#include <stdio.h>
#include <stdlib.h>

int main() {
    int matriz[2][5] = { {1,2,3,4,5},
                         {6,7,8,9,10} };
    int i, j; int *p;

    for (j=0; j < 2; j++) {
        for (i=0; i < 3; i++)
            printf("%d\t", matriz[j][i]);
        printf("\n");
    }


p = &matriz[0][0];

    for(j=0; j<2; j++) {       
        for(i=0; i<3; i++)
            printf("%d\t", *(p+(j*5)+i));       
        printf("\n");   
    }

   return 0;
}