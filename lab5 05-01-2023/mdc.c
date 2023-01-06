/*
 * Arquivo: mdc.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 05/01/2023
 */

#include <stdio.h>

typedef unsigned int uint;

uint mdc(uint a, uint b);

int main() {
	uint a, b, res;

	printf("NUMS: ");
	scanf("%u %u", &a, &b);

	res = mdc(a, b);
	printf("MDC = %u\n", res);

	return 0;
}

uint mdc(uint a, uint b) {
	if (!b) return a;
	else return mdc(b, a % b);
}
