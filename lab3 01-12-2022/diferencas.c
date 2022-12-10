/*
 * Arquivo: diferencas.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 02/12/2022
 */

#include <stdio.h>

typedef unsigned int uint;

float minArray(float arr[], uint size);                   // Função de menor número em um vetor
float maxArray(float arr[], uint size);                   // Função de maior número em um vetor
void setDiff(float arr[], uint sizeArr, float diff[]);    // Função de definição do vetor das diferenças

int main() {
	uint N;                                               // Quantidade de elementos
	float min;                                            // Menor diferença
	float max;                                            // Maior diferença

	printf("# de números: ");
	scanf("%u", &N);

	float nums[N];                                        // Vetor de números
	float diff[N - 1];                                    // Vetor das diferenças

	printf("NUMS: ");
	for (int i = 0; i < N; i++) {
		scanf("%f", nums + i);
	}

	setDiff(nums, N, diff);                               // Define o vetor das diferenças
	min = minArray(diff, N - 1);                          // Menor diferença
	max = maxArray(diff, N - 1);                          // Maior diferença

	printf("\n");

	// Impressão do vetor das diferenças
	for (uint i = 0; i < N - 1; i++) {
		printf("%g", diff[i]);

		if (i < N - 2) {
			printf(", ");                                 // Separa os termos por vírgula
		}
	}

	printf("\n");

	printf("MIN: %g\n", min);                             // Impressão da menor diferença
	printf("MAX: %g\n", max);                             // Impressão da maior diferença

	return 0;
}


float minArray(float arr[], uint size) {
	float minNum = arr[0];                                // O menor elemento é o primeiro do vetor

	for (uint i = 1; i < size; i++) {                     // Verifica a lista a partir do segundo elemento
		if (*(arr + i) < minNum) {
			minNum = *(arr + i);                          // Se houver um número ainda menor que 'minNum', então a variável é atualizada
		}
	}

	return minNum;
}


float maxArray(float arr[], uint size) {
	float maxNum = arr[0];                                // O maior elemento é o primeiro do vetor

	for (uint i = 1; i < size; i++) {                     // Verifica a lista a partir do segundo elemento
		if (*(arr + i) > maxNum) {
			maxNum = *(arr + i);                          // Se houver um número ainda maior que 'maxNum', então a variávei é atualizada
		}
	}

	return maxNum;
}


void setDiff(float arr[], uint sizeArr, float diff[]) {
	for (uint i = 0; i < sizeArr - 1; i++) {              // Percorre toda a lista
		diff[i] = arr[i + 1] - arr[i];                    // A i-ésima diferença é o (i+1)-ésimo número menos seu antecessor
	}
}
