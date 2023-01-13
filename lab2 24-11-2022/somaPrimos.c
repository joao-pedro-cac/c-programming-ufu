/*
 * Arquivo: somaPrimos.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 24/11/2022
 */

#include <stdio.h>

int isPrime(int n);

int main() {
	// Variáveis
	int a, b;
	int sum = 0;

	printf("   Insira dois números (a < b)\n\n");
	printf("\ta, b: ");
	scanf("%d %d", &a, &b);
	printf("\n");

	// Captura de erros
	if (a >= b) {
		printf("ERRO! O número a deve ser menor que b...\n");
		return -1;
	}

	// Loop de cálculo
	for (int i = a; i <= b; i++) {
		if (isPrime(i)) {
			sum += i;                          // Se 'i' é primo, então ele participa da adição
		}
	}

	// Resultado final
	printf("   SOMA = %d\n", sum);

	return 0;
}

// Verificação de número primo
int isPrime(int n) {
	if (n <= 1) {                              // Números menores ou iguais a 1 não são primos
		return 0;
	}

	for (int i = 2; i < n; i++) {
		if (!(n % i)) {
			return 0;                          // Se o número tiver algum divisor de 2 a n - 1, então ele não é primo
		}
	}

	return 1;                                  // Senão, ele é primo
}
