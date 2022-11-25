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

	printf("   Insira dois números (a < b)\n\n");
	printf("\ta, b: ");
	scanf("%d %d", &a, &b);

	// Captura de erros
	if (a > b) {
		printf("\nERRO! O número a deve ser menor que b...\n");
		return -1;
	}

	// Se a é par, então a + 1 é ímpar
	if (!(a % 2)) {
		a++;
	}

	printf("\n   ÍMPARES: ");

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
