/*
 * Arquivo: txtFibonacci.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 23/01/2023
 */

#include <stdio.h>

typedef unsigned long int ulint;

typedef unsigned char byte;
typedef unsigned long long int ullint;

int main() {
	byte N;
	FILE *arq;

	printf("No. ELEMENTOS (1-94): ");
	scanf("%hhu%*c", &N);

	ullint nums[N];                                                      // Vetor da sequência de Fibonacci
	nums[0] = 0;
	nums[1] = 1;

	arq = fopen("fibonacci.txt", "w");
	fprintf(arq, "%llu\n", nums[0]);
	if (N > 1) fprintf(arq, "%llu\n", nums[1]);

	// Cálculo da sequência de Fibonacci
	for (byte i = 2; i < N; i++) {
		nums[i] = nums[i - 1] + nums[i - 2];
		fprintf(arq, "%llu\n", nums[i]);
	}

	printf("%llu\n", nums[N - 1]);                                       // Impressão do último elemento
	fclose(arq);

	return 0;
}
