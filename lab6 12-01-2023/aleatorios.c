/*
 * Arquivo: aleatorios.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 13/01/2023
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

void fillRandom(uint **arr, uint size);
void defMinMax(uint *arr, uint size, uint *min, uint *max);
void defAverage(uint *arr, uint size, double *avg);

int main() {
	uint *nums;                                           // Vetor de números pseudoaleatórios
	uint N;                                               // Quantidade de elementos
	uint min;                                             // Menor elemento
	uint max;                                             // Maior elemento
	double avg;                                           // Média aritmética
 
	printf("No. ELEMENTOS: ");
	scanf("%u", &N);


	nums = (uint *) malloc(N * sizeof(uint));
	srand(N);                                             // Define a semente de aleatoriedade para 'N'

	fillRandom(&nums, N);
	defMinMax(nums, N, &min, &max);
	defAverage(nums, N, &avg);

	printf("\n");
	printf("MINIMO: %u\n", min);
	printf("MAXIMO: %u\n", max);
	printf("MEDIA:  %lg\n", avg);

	free(nums);

	return 0;
}

// Preenche um vetor com números pseudoaleatórios de 0 a TAMANHO - 1
void fillRandom(uint **arr, uint size) {
	for (uint i = 0; i < size; i++) (*arr)[i] = rand() % size;
}

// Menor e maior número de um vetor
void defMinMax(uint *arr, uint size, uint *min, uint *max) {
	*min = *arr;
	*max = *arr;

	for (uint i = 1; i < size; i++) {
		if (arr[i] < *min) *min = arr[i];
		if (arr[i] > *max) *max = arr[i];
	}
}

// Média dos números de um vetor
void defAverage(uint *arr, uint size, double *avg) {
	*avg = 0;
	for (uint i = 0; i < size; i++) *avg += arr[i];
	*avg /= size;
}
