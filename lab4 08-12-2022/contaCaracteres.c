/*
 * Arquivo: contaCaracteres.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 09/12/2022
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

char* strinput();
char* showLetters(char str[]);
char* showDigits(char str[]);
char* showOthers(char str[]);

int main() {
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
