/*
 * Arquivo: mediaimpares.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 12/01/2023
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

double avg(int *nums, uint size);

int main() {
	uint N;
	int s;                                                   // Número inicial

	printf("No. NUMEROS: ");
	scanf("%u", &N);

	printf("NUM INICIAL: ");
	scanf("%d", &s);

	int *nums = (int *) malloc(N * sizeof(int));             // Vetor de inteiros

	if (!(s % 2)) s++;                                       // Caso 's' seja par, sobe para o próximo ímpar
	for (uint i = 0; i < N; i++) nums[i] = s + 2 * i;        // Adiciona os N primeiros ímpares a partir de 's' ao vetor

	printf("\n");
	printf("PENULTIMO ELEMENTO:  %d\n", nums[N - 2]);
	printf("MEDIA:               %lg\n", avg(nums, N));

	free(nums);

	return 0;
}

// Função de média
double avg(int *nums, uint size) {
	double sum = 0;
	for (uint i = 0; i < size; i++) sum += nums[i];
	return sum / size;
}
