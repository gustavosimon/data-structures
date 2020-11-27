	
#include <stdio.h>

void recursao1(int n) {

    if (n<=4) {

        printf("%d\t", n);

        recursao1(n + 1);

    }

}

void recursao2(int n) {

    if (n<=4) {

        recursao2(n + 1);

        printf("%d\t", n);

    }

}

int main() {

    recursao1(0);

    printf("\n");

    recursao2(0);

    return 0;

}
