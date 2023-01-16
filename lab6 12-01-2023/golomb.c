/*
 * Arquivo: golomb.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 13/01/2023
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

uint golomb(uint n);
double averageInterval(uint *nums, uint a, uint b);
void swap(uint *a, uint *b);

int main() {
	uint a, b;                                                  // Índices inicial e final
	uint first, last;                                           // Primeiro e último elemento
	double avg;                                                 // Média aritmética

	printf("INDICES: ");
	scanf("%u %u", &a, &b);

	if (b < a) swap(&a, &b);                                    // 'b' deve ser maior ou igual a 'a'


	uint *nums = (uint *) malloc((b + 1) * sizeof(uint));   // Vetor de números
	for (uint i = 0; i <= b; i++) nums[i] = golomb(i);

	avg = averageInterval(nums, a, b);


	printf("PRIMEIRO: %u\n", nums[a]);
	printf("ULTIMO:   %u\n", nums[b]);
	printf("MEDIA:    %lg\n", avg);

	free(nums);

	return 0;
}

// Relação de ocorrência da sequência de Golomb
uint golomb(uint n) {
	if (n == 0) return 1;
	return 1 + golomb(n - golomb(golomb(n - 1) - 1));
}

// Média aritmética em um intervalo
double averageInterval(uint *nums, uint a, uint b) {
	double avg = 0;
	for (uint i = a; i <= b; i++) avg += nums[i];
	return avg / (b - a + 1);
}

// Troca de valor entre duas variáveis
void swap(uint *a, uint *b) {
	uint aux = *a;
	*a = *b;
	*b = aux;
}
