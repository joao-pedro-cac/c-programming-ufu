/*
 * Arquivo: altura.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 06/01/2023
 */

#include <stdio.h>

typedef unsigned int uint;
typedef struct Comprimento Comprimento;

uint adjustCm(uint x);

struct Comprimento {
	uint m;
	uint cm;
};

int main() {
	Comprimento altura;

	printf("ALTURA (m): ");
	scanf("%u.%u", &(altura.m), &(altura.cm));

	altura.cm = adjustCm(altura.cm);
	printf("Altura %um%u\n", altura.m, altura.cm);

	return 0;
}

// Ajuste dos centímetros para duas casas decimais
uint adjustCm(uint x) {
	if (x < 10) return x * 10;
	if (x > 99) return adjustCm(x / 10);
	return x;
}
