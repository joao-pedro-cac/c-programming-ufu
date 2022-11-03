/*
 * Arquivo: somaGauss.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 03/11/2022
 */

#include <stdio.h>

unsigned long int soma(unsigned int n);

int main() {
	// Inicialização de variáveis
	unsigned int num;                                               // Número
	printf("NUM: ");
	scanf("%u", &num);

	// Cálculo da soma de Gauss
	unsigned long int sum = soma(num);                              // Obtém a soma de Gauss
	printf("SOMA GAUSS = %lu\n", sum);

	return 0;
}

// Soma de Gauss (forma recursiva)
unsigned long int soma(unsigned int n) {
	if (n == 1) {
		return 1;
	}
	
	return n + soma(n - 1);
}
