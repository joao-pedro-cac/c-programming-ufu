/*
 * Arquivo: contaPalavras.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 11/12/2022
 */

#include <stdio.h>

#define N 1024

typedef unsigned int uint;

void strinput(char str[], uint maxSize);
char isValid(char chr);

int main() {
	char txt[N];
	uint c = 0;
	uint i = 0;

	printf("TEXTO (sem diacríticos): ");
	strinput(txt, N);

	// Contagem de palavras
	while (txt[i]) {
		while (isValid(txt[i])) {                                         // Ao chegar a um caractere válido, uma palavra começa
			if (!isValid(txt[i + 1])) {                                   // A palavra só termina quando o próximo caractere é inválido
				c++;
				break;
			}
			i++;
		}
		i++;
	}

	printf("PALAVRAS: %u\n", c);

	return 0;
}


void strinput(char str[], uint maxSize) {
	// Função de entrada de string
	
	uint i = 0;

	while (i < maxSize - 1) {
		scanf("%c", str + i);
		if (str[i] == '\n') break;                                        // Sequência de entradas é interrompida ao pressionar [ENTER]
		i++;
	}

	str[i] = 0;
}


char isValid(char chr) {
	// Verifica se o caractere é válido (alfanumérico ou hífen) para participar de uma palavra
	
	if (chr >= 'a' && chr <= 'z') return 1;
	else if (chr >= 'A' && chr <= 'Z') return 1;
	else if (chr >= '0' && chr <= '9') return 1;
	else if (chr == '-') return 1;
	return 0;
}
