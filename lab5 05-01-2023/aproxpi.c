/*
 * Arquivo: aproxpi.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 06/01/2023
 */

#include <stdio.h>

typedef unsigned int uint;

double leibnizPi(uint n);

int main() {
	uint n;
	double pi;

	printf("PRECISÃO: ");
	scanf("%u", &n);

	pi = leibnizPi(n);
	printf("PI = %lf\n", pi);

	return 0;
}

double leibnizPi(uint n) {
	 if (!n) return 4;
	 else if (n % 2) return leibnizPi(n - 1) - 4.0 / (2 * n + 1);
	 else return leibnizPi(n - 1) + 4.0 / (2 * n + 1);
}
