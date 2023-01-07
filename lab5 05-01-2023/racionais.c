/*
 * Arquivo: racionais.c
 * Autor: João Pedro Cavalcante Albuquerque Costa
 * Matrícula: 12121ECP021
 * Criado em: 07/01/2023
 */

#include <stdio.h>

typedef struct Racional Racional;

int mdc(int a, int b);
Racional simp(Racional f);
Racional add(Racional f1, Racional f2);
Racional sub(Racional f1, Racional f2);
Racional mult(Racional f1, Racional f2);
Racional div(Racional f1, Racional f2);

struct Racional {
	int num;                                                       // Numerador
	int den;                                                       // Denominador
};

int main() {
	Racional frac1, frac2, soma, diff, prod, quoc;

	printf("FRACAO 1 (p/q): ");
	scanf("%d/%d", &frac1.num, &frac1.den);

	printf("FRACAO 2 (p/q): ");
	scanf("%d/%d", &frac2.num, &frac2.den);
	
	// Captura de erros
	if (!(frac1.den && frac2.den)) {
		printf("ERRO! Denominador nulo.\n");
		return -1;
	}

	frac1 = simp(frac1);
	frac2 = simp(frac2);

	soma = add(frac1, frac2);
	diff = sub(frac1, frac2);
	prod = mult(frac1, frac2);
	quoc = div(frac1, frac2);

	printf("\n");
	printf("FRACAO 1:   %d/%d\n", frac1.num, frac1.den);
	printf("FRACAO 2:   %d/%d\n\n", frac2.num, frac2.den);
	printf("SOMA:       %d/%d\n", soma.num, soma.den);
	printf("DIFERENCA:  %d/%d\n", diff.num, diff.den);
	printf("PRODUTO:    %d/%d\n", prod.num, prod.den);
	printf("DIVISAO:    ");

	// Determinação da existência da divisão
	if (quoc.den) printf("%d/%d\n", quoc.num, quoc.den);
	else printf("ERRO\n");

	return 0;
}


int mdc(int a, int b) {
	if (!b) return a;
	else return mdc(b, a % b);
}


Racional simp(Racional f) {
	// Função de simplificação de fração
	
	int x = mdc(f.num, f.den);
	f.num /= x;
	f.den /= x;

	// O sinal de negativo deve permanecer no numerador
	if (f.num > 0 && f.den < 0) {
		f.num *= -1;
		f.den *= -1;
	}

	return f;
}


Racional add(Racional f1, Racional f2) {
	Racional f;

	f.num = (f1.num * f2.den) + (f1.den * f2.num);
	f.den = f1.den * f2.den;
	f = simp(f);

	return f;
}


Racional sub(Racional f1, Racional f2) {
	Racional f;

	f.num = (f1.num * f2.den) - (f1.den * f2.num);
	f.den = f1.den * f2.den;
	f = simp(f);

	return f;
}


Racional mult(Racional f1, Racional f2) {
	Racional f;

	f.num = f1.num * f2.num;
	f.den = f1.den * f2.den;
	f = simp(f);

	return f;
}


Racional div(Racional f1, Racional f2) {
	Racional f;

	f.num = f1.num * f2.den;
	f.den = f1.den * f2.num;
	f = simp(f);

	return f;
}
