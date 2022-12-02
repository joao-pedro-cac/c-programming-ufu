/*
 * Arquivo: quaisDiv.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 24/11/2022
 */

#include <stdio.h>

typedef unsigned int uint;

int main() {
	// Variáveis
	uint N;
	int ref;

	printf("# de números: ");
	scanf("%u", &N);

	// Vetor de números
	int nums[N];

	printf("NUMS: ");
	for (int i = 0; i < N; i++) {
		scanf("%d", nums + i);
	}

	printf("REFERÊNCIA: ");
	scanf("%d", &ref);

	// Impressão dos números
	for (int i = 0; i < N; i++) {
		printf("%d", *(nums + i));

		if (ref % *(nums + i) == 0) {
			printf("#");                              // Caso o número seja divisor, marca-o com um '#'
		}

		printf(" ");
	}

	printf("\n");

	return 0;
}
