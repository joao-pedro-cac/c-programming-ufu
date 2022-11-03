/*
 * Arquivo: fibonacci.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 03/11/2022
 */

#include <stdio.h>

int main() {
	// Inicialização de variáveis
	unsigned int n;
	printf("NUM: ");
	scanf("%u", &n);

	// Captura de erros
	if (!n) {
		printf("ERRO! O NÚMERO DEVE SER POSITIVO.\n");
		return -1;
	}

	// Impressão da sequência de Fibonacci
	printf("0, ");

	for (unsigned int pre = 0, pos = 1, t = 1, k = 1; k < n; t = pre + pos, pre = pos, pos = t, k++) printf("%u, ", pos);

	printf("...\n");
	return 0;
}
