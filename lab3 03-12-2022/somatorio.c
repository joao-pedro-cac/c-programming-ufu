/*
 * Arquivo: somatorio.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 01/12/2022
 */

#include <stdio.h>

typedef unsigned int uint;

float sumArray(float arr[], int index);

int main() {
	// Variáveis
	uint N;
	float sum;

	printf("# de números: ");
	scanf("%u", &N);

	// Vetor de números
	float nums[N];

	printf("NUMS: ");
	for (uint i = 0; i < N; i++) {
		scanf("%f", nums + i);
	}

	// Somatório dos números do vetor (começando pelo último elemento)
	sum = sumArray(nums, N - 1);

	// Impressão do somatório
	for (uint i = 0; i < N; i++) {
		printf("%g ", *(nums + i));

		if (i < N - 1) {
			printf("+ ");                                  // Caso não seja o último número, imprime '+'
		}
		else {
			printf("= ");                                  // Caso seja o último número, imprime '='
		}
	}

	// Resultado do somatório
	printf("%g\n", sum);

	return 0;
}

// Função de somatório (recursiva)
float sumArray(float arr[], int index) {
	if (index < 0) {
		return 0;                                          // Ao ultrapassar o primeiro elemento, retorna 0
	}

	return *(arr + index) + sumArray(arr, index - 1);      // Soma o elemento atual com o elemento anterior
}
