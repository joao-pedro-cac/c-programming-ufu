/*
 * Arquivo: cosTaylor.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 03/11/2022
 */ 

#include <stdio.h>

#define PI 3.141592653589793115997963468544185161590576171875

double powDouble(double base, unsigned int exp);
unsigned long int fatorial(unsigned int n);

int main() {
	// Inicialização de variáveis
	unsigned int n;
	double x;

	printf("n = ");
	scanf("%u", &n);

	printf("x = ");
	scanf("%lf", &x);

	// Cálculo do cosseno
	double cos = 0;

	for (int i = 0; i <= n; i++) {          // Série de Taylor
		cos += powDouble(-1, i) * powDouble(PI * x, 2 * i) / fatorial(2 * i);
	}

	printf("cos(πx) = %lf\n", cos);

	return 0;
}

// Função de potenciação
double powDouble(double base, unsigned int exp) {
	double power = 1.0;

	for (int i = 0; i < exp; i++) {
		power *= base;
	}

	return power;
}

// Função de fatorial (forma recursiva)
unsigned long int fatorial(unsigned int n) {
	if (!n) {
		return 1;
	}

	return n * fatorial(n - 1);
}
