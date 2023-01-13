/*
 * Arquivo: raizes2grau.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 13/01/2023
 */

#include <stdio.h>
#include <math.h>

typedef unsigned char byte;

byte solveQuadratic(float a, float b, float c, float *x1, float *x2);

int main() {
	float a, b, c, x1, x2;

	printf("COEFICIENTES (a b c): ");
	scanf("%f %f %f", &a, &b, &c);

	// Captura de erros
	if (!a) {
		printf("ERRO! O coeficiente 'a' não pode ser nulo\n");
		return -1;
	}


	byte n = solveQuadratic(a, b, c, &x1, &x2);                            // Solução da equação quadrática


	printf("\n");

	printf("No. RAIZES: %hhu\n", n);
	if (n == 1) printf("x = %g\n", x1);
	else if (n == 2) {
		printf("x1 = %g\n", x1);
		printf("x2 = %g\n", x2);
	}

	return 0;
}

// Solucionador de equações quadráticas
byte solveQuadratic(float a, float b, float c, float *x1, float *x2) {
	float delta = b * b - 4 * a * c;

	if (delta < 0) return 0;

	// x1 deve ser a menor raíz
	if (a > 0) {
		*x1 = (-b - sqrtf(delta)) / (2 * a);
		*x2 = (-b + sqrtf(delta)) / (2 * a);
	}
	else {
		*x1 = (-b + sqrtf(delta)) / (2 * a);
		*x2 = (-b - sqrtf(delta)) / (2 * a);
	}

	if (delta == 0) return 1;
	return 2;
}
