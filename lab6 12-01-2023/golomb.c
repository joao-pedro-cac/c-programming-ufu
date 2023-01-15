/*
 * Arquivo: golomb.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 13/01/2023
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

int golomb(uint n);
void swap(uint *a, uint *b);

int main() {
	uint a, b;                                                  // Índices inicial e final
	uint first, last;                                           // Primeiro e último elemento
	double avg = 0;                                             // Média aritmética

	printf("INDICES: ");
	scanf("%u %u", &a, &b);

	if (b < a) swap(&a, &b);                                    // 'b' deve ser maior ou igual a 'a'


	uint *nums = (uint *) malloc((b - a + 1) * sizeof(uint));   // Vetor de números

	for (uint i = 0; i <= b; i++) {
		nums[i] = golomb(a + i);
		if (i < b - a + 1) avg += nums[i];                      // Evita percorrer um vetor grande duas vezes
		if (i == 0) first = nums[i];
		if (i == b) last = nums[i];
	}
	avg /= b - a + 1;


	printf("PRIMEIRO: %u\n", nums[0]);
	printf("ULTIMO:   %u\n", nums[b - a]);
	printf("MEDIA:    %lg\n", avg);

	free(nums);

	return 0;
}

// Relação de ocorrência da sequência de Golomb
int golomb(uint n) {
	if (n == 0) return 1;
	return 1 + golomb(n - golomb(golomb(n - 1) - 1));
}

// Troca de valor entre duas variáveis
void swap(uint *a, uint *b) {
	uint aux = *a;
	*a = *b;
	*b = aux;
}
