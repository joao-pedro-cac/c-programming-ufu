/*
 * Arquivo: malabarista.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 12/01/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define TAM sizeof(luint)

typedef unsigned int uint;
typedef long unsigned int luint;

luint juggler(luint n);

int main() {
	uint N;                                           // Quantidade de números
	luint base, max, min;                             // Número base, máximo e mínimo
	double avg;                                       // Média

	printf("No. NUMEROS: ");
	scanf("%u", &N);

	printf("NUMERO BASE: ");
	scanf("%lu", &base);
	
	luint *nums = (luint *) malloc(N * TAM);          // Vetor de números

	// Inicialização de cálculos
	*nums = base;
	min = base;
	max = base;
	avg = base;

	for (uint i = 1; i < N; i++) {
		nums[i] = juggler(nums[i - 1]);               // Formação da sequência malabarista

		// Atualização de variáveis
		avg += nums[i];
		if (nums[i] < min) min = nums[i];
		if (nums[i] > max) max = nums[i];
	}

	avg /= N;

	printf("MINIMO: %lu\n", min);
	printf("MAXIMO: %lu\n", max);
	printf("MEDIA:  %lg\n", avg);

	free(nums);

	return 0;
}

// Função da sequência malabarista
luint juggler(luint n) {
	if (n % 2) return floor(sqrtf(n * n * n));
	else return floor(sqrtf(n));
}
