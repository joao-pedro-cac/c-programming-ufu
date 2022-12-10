/*
 * Arquivo: palindromos.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 09/12/2022
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;

char* strinput();
char* reverse(char str[]);
void toUpper(char str[]);
char isPalindrome(char str[]);
uint lenstring(char str[]);

int main() {
	char *txt;
	char pal;

	printf("TEXTO: ");

	txt = strinput();
	pal = isPalindrome(txt);

	printf("PALÍNDROMO: ");

	if (pal)
		printf("Verdadeiro\n");
	else
		printf("Falso\n");

	free(txt);

	return 0;
}


char* strinput() {
	// Função de entrada de string
	
	uint i = 0;
	char *txt = (char*) malloc(1);

	while (1) {
		scanf("%c", txt + i);
		if (txt[i] == '\n') break;
		if (!(txt[i] >= 'a' && txt[i] <= 'z') && !(txt[i] >= 'A' && txt[i] <= 'Z')) continue;       // Ignora caracteres não alfabéticos

		i++;
		txt = realloc(txt, i + 1);
	}

	txt[i] = '\0';

	return txt;
}


char* reverse(char str[]) {
	// Função inversora de string
	
	uint i = 0;
	uint size = lenstring(str);
	char *inv = (char*) malloc(size + 1);

	while (str[i]) {
		inv[i] = str[size - 1 - i];
		i++;
	}

	inv[i] = '\0';
	return inv;
}


void toUpper(char str[]) {
	// Capitalização de string

	uint i = 0;

	while (str[i]) {
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= 'a' - 'A';
		i++;
	}
}


char isPalindrome(char *str) {
	// Verificação de string palíndromo
	char *inv = reverse(str);
	uint i = 0;

	toUpper(str);
	toUpper(inv);

	while (1) {
		if (str[i] == 0 && inv[i] == 0) return 1;
		if (str[i] != inv[i]) return 0;
		i++;
	}
}


uint lenstring(char str[]) {
	// Obtenção de tamanho efetivo (utilizado) da string
	return *str ? 1 + lenstring(str + 1) : 0;
}
