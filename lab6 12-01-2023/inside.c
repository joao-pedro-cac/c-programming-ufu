/*
 * Arquivo: inside.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 13/01/2023
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef unsigned int uint;

char* strinput();
uint strlength(char *str);
int findInText(char *str, char *txt);

int main() {
	char *txt;                                                         // Texto completo
	char *str;                                                         // Trecho

	printf("STRING: ");
	str = strinput();

	printf("TEXTO:  ");
	txt = strinput();


	int index = findInText(str, txt);
	int sizeTxt = strlength(txt);
	int sizeStr = strlength(str);


	printf("\n");

	if (index == -1) printf("Mensagem não contida...\n");              // Mensagem de ausência do trecho
	else {
		for (int i = 0; i <= sizeTxt; i++) {
			if (i == index || i == index + sizeStr) printf("*");       // Cerca o trecho no texto com asteriscos
			printf("%c", txt[i]);
		}
		printf("\n");
	}

	return 0;
}

// Função de entrada de string
char* strinput() {
	int i = 0;
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

// Tamanho efetivo da string ('\0' excluso)
uint strlength(char *str) {
	return *str ? 1 + strlength(str + 1) : 0;                          // O tamanho de uma string é 1 + o tamanho do resto
}

// Busca de string em um texto
int findInText(char *str, char *txt) {
	int i = 0;
	bool check = false;                                                // Checagem de presença
	const int sizeStr = strlength(str);

	while (txt[i] != '\0') {
		if (txt[i] == str[0]) {
			for (int j = 0; j < sizeStr; j++) {                        // Verifica se o trecho está contido a partir do índice 'i' atual
				if (txt[i + j] != str[j]) {
					check = false;
					break;
				}
				check = true;
			}
			if (check) return i;                                       // Se o trecho está contido, retorna o índice da primeira ocorrência no texto
		}
		i++;
	}

	return -1;                                                         // Retorno de erro
}
