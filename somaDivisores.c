/*
 * Arquivo: somaDivisores.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 03/11/2022
 */

#include <stdio.h>

int main() {
	// Inicialização de variáveis
	unsigned int num;
	printf("NUM: ");
	scanf("%u", &num);

	// Captura de erros
	if (!num) {
		printf("ERRO! O NÚMERO DEVE SER POSITIVO.\n");
		return -1;
	}

	// Cálculo da soma de divisores
	unsigned int soma = 0;

	for (int i = 1; i <= num; i++) {                        // 'i' vai de 1 a 'num'
		if (!(num % i)) {                                   // Se o resto da divisão de 'num' por 'i' for 0, então 'i' é um divisor de 'num'
			soma += i;
		}
	}

	printf("SOMA = %d\n", soma);

	return 0;
}
