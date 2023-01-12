/*
 * Arquivo: cadastro.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 08/01/2023
 */

#include <stdio.h>
#include <stdlib.h>


typedef unsigned int uint;
typedef unsigned char byte;
typedef struct Info Info;
typedef struct Comprimento Comprimento;
typedef struct Data Data;


char* strinput();
uint adjustCm(uint x);


struct Comprimento {
	uint m, cm;
};

struct Data {
	byte dia;
	byte mes;
	uint ano;
};

struct Info {
	char *nome;
	Data aniversario;
	Comprimento altura;
	float peso;
};


int main() {
	char meses[12][4] = {"JAN\0", "FEV\0", "MAR\0", "ABR\0", "MAI\0", "JUN\0", "JUL\0", "AGO\0", "SET\0", "OUT\0", "NOV\0", "DEZ\0"};
	uint qntd;

	printf("No. PESSOAS: ");
	scanf("%u%*c", &qntd);

	Info cadastros[qntd];

	// Loop de entradas
	for (uint i = 0; i < qntd; i++) {
		// Entrada de nome
		printf("NOME #%u: ", i + 1);
		cadastros[i].nome = strinput();

		// Entrada de aniversário
		printf("ANIVERSARIO #%u (D/M/YYYY): ", i + 1);
		scanf("%hhu/%hhu/%u", &cadastros[i].aniversario.dia, &cadastros[i].aniversario.mes, &cadastros[i].aniversario.ano);
	
		// Entrada de altura
		printf("ALTURA #%u (m): ", i + 1);
		scanf("%u.%u", &cadastros[i].altura.m, &cadastros[i].altura.cm);

		// Entrada de peso
    	printf("PESO #%u (kg): ", i + 1);
	    scanf("%f%*c", &cadastros[i].peso);

	    cadastros[i].altura.cm = adjustCm(cadastros[i].altura.cm);

		printf("\n");
	}

	printf("\n");

	// Impressão formatada de pessoas cadastradas
	for (uint i = 0; i < qntd; i++) {
		printf("%s; ", cadastros[i].nome);
		printf("%.2hhu%s%.4u; ", cadastros[i].aniversario.dia, meses[cadastros[i].aniversario.mes - 1], cadastros[i].aniversario.ano);
		printf("%um%u; ", cadastros[i].altura.m, cadastros[i].altura.cm);
		printf("%.1fkg\n", cadastros[i].peso);

		free(cadastros[i].nome);
	}

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


uint adjustCm(uint x) {
	// Ajuste dos centímetros para duas casas decimais
	if (x < 10) return x * 10;
	if (x > 99) return adjustCm(x / 10);
	return x;
}
