/*
 * Arquivo: produtorio.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 01/12/2022
 */

#include <stdio.h>

typedef unsigned int uint;

float prodArray(float arr[], int index);

int main() {
	// Variáveis
	uint N;
	float prod;

	printf("# de números: ");
	scanf("%u", &N);

	// Vetor de números
	float nums[N];

	printf("NUMS: ");
	for (uint i = 0; i < N; i++) {
		scanf("%f", nums + i);
	}

	// Produtório dos números do vetor (começando pelo último elemento)
	prod = prodArray(nums, N - 1);

	// Impressão do produtório
	for (uint i = 0; i < N; i++) {
		printf("%g ", *(nums + i));

		if (i < N - 1) {
			printf("* ");                                  // Caso não seja o último número, imprime '*'
		}
		else {
			printf("= ");                                  // Caso seja o último número, imprime '='
		}
	}

	// Resultado do produtório
	printf("%g\n", prod);

	return 0;
}

// Função de produtório (recursiva)
float prodArray(float arr[], int index) {
	if (index < 0) {
		return 1;                                          // Ao ultrapassar o primeiro elemento, retorna 1
	}

	return *(arr + index) * prodArray(arr, index - 1);     // Multiplica o elemento atual com o elemento anterior
}
