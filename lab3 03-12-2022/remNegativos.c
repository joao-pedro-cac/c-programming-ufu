/*
 * Arquivo: remNegativos.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 03/12/2022
 */

#include <stdio.h>

typedef unsigned int uint;

int lastNonNeg(int arr[], uint size);

int main() {
	// Variáveis
	uint N;
	int last;

	printf("# de números: ");
	scanf("%u", &N);

	// Vetor de números
	int nums[N];

	printf("NUMS: ");
	for (uint i = 0; i < N; i++) {
		scanf("%d", nums + i);
	}

	printf("\n");

	// Último número não-negativo do vetor
	last = lastNonNeg(nums, N);

	if (last != -1) {                                        // Caso 'last' não seja -1, então há números não-negativos
		for (uint i = 0; i < N; i++) {                       // Imprime os números não-negativos
			if (nums[i] >= 0) {
				printf("%d", nums[i]);

				if (nums[i] != last) {
					printf(", ");                            // Adiciona separador por vírgula caso não seja o último número não-negativo
				}
			}
		}
	}
	else {                                                   // Caso 'last' seja -1, então não há números não-negativos
		printf("vazio");                                     // Imprime 'vazio' como mensagem de exclusividade de números negativos
	}

	printf("\n");

	return 0;
}

// Função de obtenção do último elemento não-negativo do vetor
int lastNonNeg(int arr[], uint size) {
	for (int i = --size; i >= 0; i--) {                      // Percorre o vetor a partir do último elemento
		if (*(arr + i) >= 0) {
			return *(arr + i);                               // Se o primeiro elemento encontrado for não-negativo, então ele é retornado
		}
	}

	return -1;                                               // Se nenhum elemento for encontrado, retorna -1 (sinal de exclusividade de negativos)
}
