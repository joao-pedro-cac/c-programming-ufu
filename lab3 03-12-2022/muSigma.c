/*
 * Arquivo: muSigma.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 01/12/2022
 */

#include <stdio.h>
#include <math.h>

typedef unsigned int uint;

float average(float nums[], uint size, int index);
float standardDeviation(float nums[], uint size, float avg);

int main() {
	// Variáveis
	uint N;
	float avg;
	float dp;

	printf("# de números: ");
	scanf("%u", &N);

	// Vetor de números
	float nums[N];

	printf("NUMS: ");
	for (uint i = 0; i < N; i++) {
		scanf("%f", nums + i);
	}

	// Cálculos estatísticos
	avg = average(nums, N, N - 1);                                          // Média
	dp = standardDeviation(nums, N, avg);                                   // Desvio padrão

	// Impressão dos resultaldos
	printf("\nMÉDIA ARITMÉTICA   %g\n", avg);
	printf("DESVIO PADRÃO      %g\n", dp);

	return 0;
}

// Função de média (recursiva)
float average(float nums[], uint size, int index) {
	if (index < 0) {
		return 0;                                                           // Ao ultrapassar o primeiro elemento, retorna 0
	}

	return *(nums + index) / size + average(nums, size, index - 1);         // Soma o elemento atual dividido por 'size' com o número anterior dividido por 'size'
}

// Função de desvio padrão
float standardDeviation(float nums[], uint size, float avg) {
	float var = 0.0;                                                        // Variância
	float diff = 0.0;                                                       // Diferença entre o i-ésimo elemento de 'nums' e a média

	for (uint i = 0; i < size; i++) {
		diff = nums[i] - avg;
		var += diff * diff / size;
	}

	return sqrtf(var);
}
