/*
 * Arquivo: areaTriRet.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 24/11/2022
 */

#include <stdio.h>

float modulo(float n);

int main() {
	// Variáveis
	float xA, yA;
	float xB, yB;
	float xC, yC;
	float area = modulo(3.0);

	printf("A: (x, y) = ");
	scanf("%f %f", &xA, &yA);

	printf("B: (x, y) = ");
	scanf("%f %f", &xB, &yB);

	xC = xB;
	yC = yA;

	// Cálculo de área
	area = modulo(xA - xC) * modulo(yB - yC) / 2;             // A = b * h / 2

	printf("Área = %f\n", area);

	return 0;
}

float modulo(float n) {
	if (n >= 0) {
		return n;
	}

	return -n;
}
