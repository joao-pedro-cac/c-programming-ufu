/*
 * Arquivo: reverteString.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 08/12/2022
 */

#include <stdio.h>
#include <stdlib.h>

#define N 1024

typedef unsigned int uint;

char* reverse(char str[], uint size);
void getStr(char str[], uint size);
uint lenStr(char str[]);
void toUpper(char str[], uint size);

int main() {
	char text[N];
	char *invText;

	printf("TEXTO (sem diacríticos): ");
	getStr(text, N);

	invText = reverse(text, N);
	toUpper(invText, sizeof(invText));

	printf("\nTexto revertido: %s\n", invText);

	free(invText);                                             // Liberar a memória da pilha ("stack")

	return 0;
}


char* reverse(char str[], uint size) {
	// Função de inversão de string

	char *p;
	uint i;
	uint tam = lenStr(str);

	p = (char*) malloc(tam + 1);

	for (i = 0; i < tam; i++) p[tam - 1 - i] = str[i];         // Cada i-ésimo elemento de 'str' se torna o (size - i)-ésimo elemento de 'p'
	p[tam] = '\0';                                             // Último caractere útil se torna '\0'

	return p;
}


void getStr(char str[], uint size) {
	// Função de entrada de string
	
	uint i = 0;

	while (i < size - 1) {
		scanf("%c", str + i);

		if (str[i] == '\n') break;                             // Caso o i-ésimo caractere seja uma quebra de linha (ENTER), quebra a sequência de entradas

		i++;
	}

	str[i] = '\0';                                             // Último caractere útil é o '\0'
}


uint lenStr(char* str) {
	// Função de obtenção de tamanho efetivo (utilizado) de string
	
	return *str ? 1 + lenStr(str + 1) : 0;                     // Recursão: tamanho da string = 1 + tamanho do resto da string (até chegar em '\0')
}


void toUpper(char str[], uint size) {
	// Função de tornar letras maiúsculas

	uint i = 0;

	while (str[i]) {                                           // Enquanto o caractere atual não for '\0'
		if (str[i] >= 'a' && str[i] <= 'z') {
			str[i] -= 32;                                      // Subtrai 32 de cada caractere alfabético (tabela ASCII)
		}

		i++;
	}
}
