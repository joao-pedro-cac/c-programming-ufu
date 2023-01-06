/*
 * Arquivo: altura.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 05/01/2023
 */

#include <stdio.h>

typedef unsigned int uint;

uint adjustCm(uint x);

int main() {
	uint m, cm;

	printf("ALTURA (m): ");
	scanf("%u.%u", &m, &cm);

	cm = adjustCm(cm);
	printf("Altura %um%u\n", m, cm);

	return 0;
}

uint adjustCm(uint x) {
	// Ajuste dos centímetros para duas casas decimais
	if (x < 10) return x * 10;
	if (x > 99) return adjustCm(x / 10);
	return x;
}
