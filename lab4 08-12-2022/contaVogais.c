/*
 * Arquivo: contaVogais.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 08/12/2022
 */

#include <stdio.h>

#define N 1024

typedef unsigned int uint;

void getStr(char str[], uint size);
uint countVowel(char str[], uint size);
void toUpper(char str[], uint size);

int main() {
	char text[N];
	uint numVowels;

	printf("TEXTO (sem diacríticos): ");
	getStr(text, N);

	numVowels = countVowel(text, N);

	printf("\nQuantidade de vogais: %d\n", numVowels);

	return 0;
}


void toUpper(char str[], uint size) {
	// Função de tornar letras maiúsculas

	uint i = 0;

	while (str[i]) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 32;
		i++;
	}
}


uint countVowel(char str[], uint size) {
	// Função de contagem de vogais

	uint c = 0;
	toUpper(str, size);                                        // String se torna maiúscula -> desconsidera os casos de verificação para letras minúsculs

	for (uint i = 0; i < size; i++) {
		switch (str[i]) {
			case 'A':
				c++;
				break;
			case 'E':
				c++;
				break;
			case 'I':
				c++;
				break;
			case 'O':
				c++;
				break;
			case 'U':
				c++;
				break;
		}
	}

	return c;
}


void getStr(char str[], uint size) {
	// Função de entrada de string

	uint i = 0;

	while (1) {
		if (i >= size - 1) {
			break;                                             // Caso 'i' ultrapasse o tamanho da string, quebra a sequência de entradas
		}

		scanf("%c", &str[i]);

		if (str[i] == '\n') {
			break;
		}

		i++;
	}

	while (i < size) {
		str[i++] = '\0';                                       // Remoção de lixo
	}
}
