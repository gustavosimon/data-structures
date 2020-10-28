#include <stdio.h>
#include <stdlib.h>

int factorial(int number) {
	int result = 0;
	if (number == 1) {
		return 1;
	} else {
		result = number * factorial(number - 1);
		return result;
	}
}

int main() {
	int number;
	printf("Tell me a number: ");
	scanf("%d", &number);
	printf("Factorial: %d", factorial(number));
}
