// Prova II - Estrutura de dados  I
// Gustavo André Simon
#include <stdio.h>

// Funcao para multiplicar os valores de forma recursiva
int multi(int x, int y) {
// Se y for igual a 1 retorna o valor de x
	if (y == 1) {
		return x;	
	}
// Se y for maior que 1, chama a rotina novamente	
	if (y > 1) {
		return x + multi(x, y - 1);
	}
}

int main() {
// Valor 1 da multiplicacao
	int x = 3;
// Valor 2 da multiplicacao	
	int y = 4;
// Chama a multiplicacao dos valores e salva em result
	int result = multi(x, y);
// Imprime o resultado da multiplicacao	
	printf("Multiplicacao: %d", result);
    return 0;
}
