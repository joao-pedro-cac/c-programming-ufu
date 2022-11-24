/*
 * Arquivo: impares.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 24/11/2022
 */

#include <stdio.h>

int main() {
	// Variáveis
	int a, b;

	printf("a: ");
	scanf("%d", &a);

	printf("b: ");
	scanf("%d", &b);

	// Se a é par, então a + 1 é ímpar
	if (!(a % 2)) {
		a++;
	}

	printf("ÍMPARES: ");

	// Laço de ímpares (2 em 2)
	for (int i = a; i <= b; i += 2) {
		printf("%d", i);

		if (i < b - 1) {
			printf(", ");
		}
	}

	printf("\n");
	return 0;
}
