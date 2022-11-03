/*
 * Arquivo: imc.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 03/11/2022
 */

#include <stdio.h>

int main() {
	// Inicialização de variáveis
	float m, h;

	printf("PESO (kg): ");
	scanf("%f", &m);

	printf("ALTURA (m): ");
	scanf("%f", &h);

	float imc = m / (h * h);

	printf("IMC = %.2f (", imc);

	if (imc < 16) {
		printf("Perigo de vida");
	}
	else if (imc < 17) {
		printf("Muito abaixo do peso");
	}
	else if (imc < 18.5) {
		printf("Abaixo do peso");
	}
	else if (imc < 25) {
		printf("Peso normal");
	}
	else if (imc < 30) {
		printf("Acima do peso");
	}
	else if (imc < 35) {
		printf("Obesidade grau I");
	}
	else if (imc < 40) {
		printf("Obesidade grau II");
	}
	else {
		printf("Obesidade grau III");
	}
	
	printf(")\n");
	return 0;
}
