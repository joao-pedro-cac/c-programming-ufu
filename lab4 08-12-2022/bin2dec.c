/*
 * Arquivo: bin2dec.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 09/12/2022
 */

#include <stdio.h>
#include <stdlib.h>

#define N 1024

typedef unsigned int uint;
typedef unsigned long ulong;

ulong bintodec(char str[]);
char* reverse(char str[]);
void strget(char str[], uint size);
uint strlength(char str[]);

int main() {
	char string[N];
	ulong decNum;

	printf("BIN: ");
	strget(string, N);

	decNum = bintodec(string);
	printf("DEC: %lu\n", decNum);

	return 0;
}


ulong bintodec(char str[]) {
	// Função de conversão de número binário (bit string) para decimal

	char *inv = reverse(str);
	ulong dec = 0;
	ulong base = 1;
	uint tam = strlength(str);

	for (int i = 0; i < tam; i++) {
		dec += (inv[i] - '0') * base;
		base = base << 1;
	}

	return dec;
}


char* reverse(char str[]) {
	// Função de inversão de string
	
	uint i = 0;
	uint size = strlength(str);
	char *inv = (char*) malloc(size + 1);

	while (*(str + i)) {
		inv[i] = str[size - 1 - i];
		i++;
	}

	inv[i] = '\0';
	return inv;
}


void strget(char str[], uint size) {
	// Função de entrada de string
	
	uint i = 0;

	while (i < size - 1) {
		scanf("%c", str + i);

		if (str[i] == '\n') break;                             // Caso o i-ésimo caractere seja uma quebra de linha (ENTER), quebra a sequência de entradas
		if (str[i] != '0' && str[i] != '1') continue;          // Ignora caracteres diferentes de 0 e 1

		i++;
	}

	str[i] = '\0';                                             // Último caractere útil é o '\0'
}


uint strlength(char str[]) {
	// Função de tamanho efetivo (utilizado) da string
	return *str ? 1 + strlength(str + 1) : 0;
}
