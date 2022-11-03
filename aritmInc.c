/*
 * Arquivo: aritmInc.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 03/11/2022
 */ 

#include <stdio.h>

int main() {
	int n1, n2;                                   // Números
    printf("NUMS: ");
	scanf("%d %d", &n1, &n2);

	printf("%d + %d = %d\n", n1, n2, n1 + n2);    // Adição
	printf("%d - %d = %d\n", n1, n2, n1 - n2);    // Subtração
	printf("%d x %d = %d\n", n1, n2, n1 * n2);    // Multiplicação
	printf("%d / %d = %d\n", n1, n2, n1 / n2);    // Divisão inteira
	printf("%d %% %d = %d\n", n1, n2, n1 % n2);  // Resto da divisão

	return 0;
}
