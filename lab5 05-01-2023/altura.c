/*
 * Arquivo: fib.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 05/01/2023
 */

#include <stdio.h>

typedef unsigned int uint;

uint fib(uint n);

int main() {
	uint n, res;

	printf("NUM: ");
	scanf("%u", &n);

	res = fib(n);
	printf("FIBONACCI: %u\n", res);

	return 0;
}

uint fib(uint n) {
	if (!n) return 0;
	else if (n == 1 || n == 2) return 1;
	else return fib(n - 1) + fib(n - 2);
}
