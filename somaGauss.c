/*
 * Arquivo: somaGauss.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 03/11/2022
 */

#include <stdio.h>

int soma(int n);

int main() {
	int num;
	printf("NUM: ");
	scanf("%d", &num);

	if (num <= 1) {
		printf("ERRO! NÚMERO DEVE SER MAIOR QUE 1...");
		return -1;
	}

	int sum = soma(num);

	printf("SOMA GAUSS = %d\n", sum);

	return 0;
}

int soma(int n) {
	if (n == 1) {
		return 1;
	}
	
	return n + soma(n - 1);
}
