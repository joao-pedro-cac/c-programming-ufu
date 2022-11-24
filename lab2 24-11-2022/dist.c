/*
 * Arquivo: dist.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 24/11/2022
 */

#include <stdio.h>
#include <math.h>

int main() {
	// Variáveis
	float xA, yA;
	float xB, yB;
	float dist;

	printf("A: (x, y) = ");
	scanf("%f %f", &xA, &yA);

	printf("B: (x, y) = ");
	scanf("%f %f", &xB, &yB);

	dist = sqrtf(powf(xA - xB, 2) + powf(yA - yB, 2));    // Equação de distância

	printf("\nDistância AB = %f\n", dist);

	return 0;
}
