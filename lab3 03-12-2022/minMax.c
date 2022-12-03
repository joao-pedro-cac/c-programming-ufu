/*
 * Arquivo: minMax.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 01/12/2022
 */

#include <stdio.h>

typedef unsigned int uint;

int minArray(int arr[], uint size);
int maxArray(int arr[], uint size);

int main() {
	// Variáveis
	uint N;
	int min;
	int max;

	printf("# de números: ");
	scanf("%u", &N);

	// Vetor de números
	int nums[N];

	printf("NUMS: ");
	for (int i = 0; i < N; i++) {
		scanf("%d", nums + i);
	}

	min = minArray(nums, N);                        // Cálculo de menor número
	max = maxArray(nums, N);	    				// Cálculo de maior número

	// Impressão dos números
	for (int i = 0; i < N; i++) {
		printf("%d", *(nums + i));

		if (*(nums + i) == min) {
			printf("<");                            // Caso seja o menor número do vetor, marca-o com um '<'
		}
		if (*(nums + i) == max) {
			printf(">");                            // Caso seja o maior número do vetor, marca-o com um '>'
		}

		printf(" ");
	}

	printf("\n");

	return 0;
}


// Função de menor número em um vetor
int minArray(int arr[], uint size) {
	int minNum = arr[0];                            // O menor elemento é o primeiro do vetor

	for (int i = 1; i < size; i++) {                // Verifica a lista a partir do segundo elemento
		if (*(arr + i) < minNum) {
			minNum = *(arr + i);                    // Se houver um número ainda menor que 'minNum', então a variável é atualizada
		}
	}

	return minNum;
}


// Função de maior número em um vetor
int maxArray(int arr[], uint size) {
	int maxNum = arr[0];                            // O maior elemento é o primeiro do vetor

	for (int i = 1; i < size; i++) {                // Verifica a lista a partir do segundo elemento
		if (*(arr + i) > maxNum) {
			maxNum = *(arr + i);                    // Se houver um número ainda maior que 'maxNum', então a variável é atualizada
		}
	}

	return maxNum;
}
