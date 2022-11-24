/*
 * Arquivo: divisores.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 24/11/2022
 */

#include <stdio.h>

void divisores(int n, int i);

int main() {
	// Variáveis
	int num;

	printf("NUM: ");
	scanf("%d", &num);

	printf("Divisores: ");

	// Loop de divisores
	for (int i = 1; i <= num; i++) {
		if (!(num % i)) {
			printf("%d", i);                      // Se num / i tem resto 0, então i é divisor de num
			
			if (i < num) {
				printf(", ");
			}
		}
	}

	printf("\n");

	return 0;
}
