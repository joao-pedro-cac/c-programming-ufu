/*
 * Arquivo: fatorial.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 03/11/2022
 */

#include <stdio.h>

unsigned long int fatorial(unsigned int n);

int main() {
	// Inicialização de variáveis
	unsigned int num;                                          // Número
	printf("NUM: ");
	scanf("%u", &num);

	// Cálculo do fatorial
	unsigned long int fatNum = fatorial(num);
	printf("%u! = %lu\n", num, fatNum);

	return 0;
}

unsigned long int fatorial(unsigned int n) {                   // Função de fatorial (forma recursiva)
	if (n == 0) {
		return 1;
	}

	return n * fatorial(n - 1);
}
