/*
 * Arquivo: contaCaracteres.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 10/12/2022
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

char* strinput();
uint* countChars(char str[]);
char isAlpha(char chr);
char isDigit(char chr);

int main() {
	char *txt;
	uint *amounts;

	printf("TEXTO (sem diacríticos): ");
	txt = strinput();

	amounts = countChars(txt);

	printf("\nLetras:  %u\n", amounts[0]);
	printf("Dígitos: %u\n", amounts[1]);
	printf("Outros:  %u\n", amounts[2]);

	free(txt);
	free(amounts);

	return 0;
}


char* strinput() {
	// Função de entrada de string
	
	uint i = 0;
	char *txt = (char*) malloc(1);

	while (1) {
		scanf("%c", txt + i);
		if (txt[i] == '\n') break;

		i++;
		txt = realloc(txt, i + 1);
	}

	txt[i] = '\0';

	return txt;
}

uint* countChars(char str[]) {
	/* 
	 * Contagem de caracteres
	 * Retorna um vetor com 3 elementos:
	 *     Elemento 1: Quantidade de letras
	 *     Elemento 2: Quantidade de algarismos
	 *     Elemento 3: Quantidade de caracteres não alfanuméricos
	 */

	uint *counts = (uint*) calloc(3, sizeof(int));
	uint i = 0;
	char letter = str[i];

	while (letter) {
		if (isAlpha(letter))
			counts[0]++;
		else if (isDigit(letter))
			counts[1]++;
		else
			counts[2]++;

		i++;
		letter = str[i];
	}

	return counts;
}


char isAlpha(char chr) {
	// Verifica se o caractere é uma letra

	if (chr >= 'A' && chr <= 'Z')
		return 1;
	if (chr >= 'a' && chr <= 'z')
		return 1;
	return 0;
}


char isDigit(char chr) {
	// Verifica se o caractere é um algarismo

	if (chr >= '0' && chr <= '9')
		return 1;
	return 0;
}
