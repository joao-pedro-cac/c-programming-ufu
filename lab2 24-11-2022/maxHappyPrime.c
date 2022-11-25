/*
 * Arquivo: maxHappyPrime.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 24/11/2022
 */

#include <stdio.h>


typedef unsigned int uint;
typedef unsigned char byte;

int isPrime(uint num);
int isHappy(uint num);
uint sumQuadDigits(uint num);
int squareInt(uint num);


int main() {
	// Variáveis
	uint num;
	uint happyNum = 0;                            // Valor padrão para o maior número primo e feliz de 1 a 'num'

	printf("   Insira um número natural não-nulo\n\n");
	printf("\tNUM: ");
	scanf("%u", &num);
	printf("\n");

	// Captura de erros
	if (num < 1) {
		printf("ERRO! O número deve ser maior que 1...\n");
		return -1;
	}

	printf("   Maior primo feliz de 1 a %d: ", num);

	// Cálculo de maior número primo e feliz
	for (uint i = num; i > 1; i--) {
		if (isPrime(i) && isHappy(i)) {
			happyNum = i;
			break;
		}
	}

	printf("%d", happyNum);

	// Se 'happyNum' é 0, então não há números primos e felizes de 1 a 'num'
	if (!happyNum) {
		printf(" (Não há um número primo e feliz)");
	}

	printf("\n");

	return 0;
}

// Função de verificação de número primo
int isPrime(uint num) {
	if (num <= 1) {
		return 0;                                 // Números menores ou iguais a 1 não são primos
	}

	for (int i = 2; i < num; i++) {
		if (!(num % i)) {
			return 0;                             // Se 'i' é divisor de 'num', então num não é primo
		}
	}

	return 1;                                     // Senão, 'num' é primo
}

int isHappy(uint num) {
	if (num == 1) {
		return 1;                                 // Se o número resultante for 1, então é um número FELIZ
	}

	if (num == 4) {
		return 0;                                 // Senão, se o número resultante for 4, então é um número INFELIZ
	}

	uint sumQuad = sumQuadDigits(num);

	return isHappy(sumQuad);                      // Senão, a função invariante se repete
}

// Função de soma dos quadrados dos dígitos
uint sumQuadDigits(uint num) {
	if (!num) {
		return 0;                                 // Se 'num' é 0, então retorna 0
	}

	byte digit = num % 10;                        // Algarismo das unidades
	uint rem = num / 10;                          // Número restante

	return (digit * digit) + sumQuadDigits(rem);  // Retorna o quadrado do algarismo atual somado aos quadrados dos algarismos restantes
}
