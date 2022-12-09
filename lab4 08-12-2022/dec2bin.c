/*
 * Arquivo: dec2bin.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 08/12/2022
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned int uint;
typedef unsigned long long ullong;

char* dectobin(ullong num);
char* reverse(char str[]);
void strget(char str[], uint size);
uint strlength(char str[]);

int main() {
	ullong num;
	char *bitNum;

	printf("NUM (max. 64 bits): ");
	scanf("%llu", &num);

	bitNum = dectobin(num);
	printf("BIN: %s\n", bitNum);
	free(bitNum);

	return 0;
}


char* dectobin(ullong num) {
	// Função de conversão de número em bit string

	uint tam = 1;
	char *bitstring = (char*) malloc(2);

	bitstring[0] = '0';                                        // Garante impressão caso 'num' seja 0


	while (num) {
		bitstring[tam - 1] = (num % 2) + '0';
		num /= 2;
		tam++;
		bitstring = realloc(bitstring, tam);
	}

	bitstring[tam] = '\0';

	char *bitInv = reverse(bitstring);

	free(bitstring);

	return bitInv;
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
		i++;
	}

	str[i] = '\0';                                             // Último caractere útil é o '\0'
}


uint strlength(char str[]) {
	// Função de tamanho efetivo (utilizado) da string
	return *str ? 1 + strlength(str + 1) : 0;
}
