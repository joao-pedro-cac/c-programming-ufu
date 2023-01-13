/*
 * Arquivo: somavetores.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 13/01/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INT_TAM sizeof(int)

typedef unsigned int uint;

void fillArray1(int **arr, uint size);
void fillArray2(int **arr, uint size);
bool arraySum(int *v1, uint size1, int *v2, uint size2, int *sums);

int main() {
	uint N, M;                                                                   // Tamanhos dos vetores

	printf("TAMANHOS (a b): ");
	scanf("%u %u", &N, &M);


	int *arr1 = (int *) malloc(N * INT_TAM);
	int *arr2 = (int *) malloc(M * INT_TAM);
	int sums[N];

	fillArray1(&arr1, N);
	fillArray2(&arr2, M);

	bool check = arraySum(arr1, N, arr2, M, sums);


	if (check) {
		for (uint i = 0; i < N; i++) {
			printf("%d", sums[i]);
			if (i < N - 1) printf(", ");
		}
	}
	else printf("Vetores de tamanho diferentes. Soma inexistente.");

	printf("\n");


	free(arr1);
	free(arr2);

	return EXIT_SUCCESS;
}

// Preenche o primeiro vetor com ímpares
void fillArray1(int **arr, uint size) {
	for (uint i = 0; i < size; i++) *(*arr +i) = 1 + 2 * i;
}

// Preenche o segundo vetor com múltiplos de 4 a partir de 0
void fillArray2(int **arr, uint size) {
	for (uint i = 0; i < size; i++) *(*arr + i) = 4 * i;
}

// Soma vetores e armazena em um vetor estaticamente alocado
bool arraySum(int *v1, uint size1, int *v2, uint size2, int *sums) {
	if (size1 != size2) return false;
	for (uint i = 0; i < size1; i++) *(sums + i) = *(v1 + i) + *(v2 + i);
	return true;
}
