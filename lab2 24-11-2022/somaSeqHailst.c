/*
 * Arquivo: sumSeqHailst.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 24/11/2022
 */

#include <stdio.h>

unsigned int collatzSum(int n);

int main() {
	// Variáveis
	int num;
	unsigned int sum;

	printf("NUM: ");
	scanf("%d", &num);
	
	sum = num + collatzSum(num);                     // Soma da sequência de Hailstone (incluindo 'num' à adição)

	printf("SOMA = %d\n", sum);

	return 0;
}

// Função de soma de sequência de Hailstone (excluindo n)
unsigned int collatzSum(int n) {
	unsigned int s;

	if (n == 1) {
		return 0;
	}

	if (n % 2) {
		s = 3 * n + 1;
	}
	else {
		s = n / 2;
	}

	return s + collatzSum(s);
}

