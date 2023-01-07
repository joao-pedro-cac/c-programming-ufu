/*
 * Arquivo: datas.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 06/01/2023
 */

#include <stdio.h>
#include <stdlib.h>

typedef unsigned char byte;
typedef unsigned int uint;
typedef struct Date Date;

char* format(byte val);
char* attrYear(uint year);

struct Date {
	char *dia;
	char *mes;
	char *ano;
};

int main() {
	char meses[12][4] = {"JAN\0", "FEV\0", "MAR\0", "ABR\0", "MAI\0", "JUN\0", "JUL\0", "AGO\0", "SET\0", "OUT\0", "NOV\0", "DEZ\0"};

	Date data;
	byte d;
	byte m;
	uint a;

	printf("DATA (D/M/YYYY): ");
	scanf("%hhu/%hhu/%u", &d, &m, &a);

	data.dia = format(d);
	data.mes = format(m);
	data.ano = attrYear(a);

	printf("%s.%s.%s\t", data.dia, data.mes, data.ano);
	printf("%s-%s-%s\t", data.mes, data.dia, data.ano);
	printf("%s/%s/%c%c\t", data.dia, data.mes, data.ano[2], data.ano[3]);
	printf("%s%s%s\n", data.dia, meses[m - 1], data.ano);

	return 0;
}


char* format(byte val) {
	char *par = (char *) malloc(3);

	par[0] = val / 10 + '0';
	par[1] = val % 10 + '0';
	par[2] = '\0';

	return par;
}


char* attrYear(uint year) {
	char *ano = (char *) malloc(5);

	ano[0] = year / 1000 + '0';               // Milhar
	year %= 1000;
	ano[1] = year / 100 + '0';                // Centena
	year %= 100;
	ano[2] = year / 10 + '0';                 // Dezena
	year %= 10;
	ano[3] = year / 1 + '0';                  // Unidade
	year %= 1;
	ano[4] = '\0';

	return ano;
}
