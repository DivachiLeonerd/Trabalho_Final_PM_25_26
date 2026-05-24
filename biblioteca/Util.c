/*
 * Util.c
 */

#include "Util.h"

/*------------------------------------------*/
/* Funcoes publicas */

void mensagem(string txt, ...){
	fflush(stdout);
	va_list args;
	va_start(args, txt);
	vfprintf(stderr, txt, args);
	fprintf(stderr, "\n");
	va_end(args);
}

void aviso(string txt, ...){
	fflush(stdout);
	va_list args;
	va_start(args, txt);
	fprintf(stderr, "AVISO: ");
	vfprintf(stderr, txt, args);
	fprintf(stderr, "!\n");
	va_end(args);
}

void erroFatal(string txt, ...){
	fflush(stdout);
	va_list args;
	va_start(args, txt);
	fprintf(stderr, "ERRO FATAL: ");
	vfprintf(stderr, txt, args);
	fprintf(stderr, "!\n");
	va_end(args);
	exit(1);
}

void semMemoria(void){
	erroFatal("Memoria esgotada");
}

int comparaInteiros(int i1, int i2){
	if (i1 == i2) return 0;
	else if (i1 < i2) return -1;
	else return 1;
}

string criaString(string s){
	string str = strdup(s);
	if (str == NULL) semMemoria();
	return str;
}

void destroiString(string s){
	free(s);
}

/* ENGLISH */

void message(string txt, ...){
	fflush(stdout);
	va_list args;
	va_start(args, txt);
	vfprintf(stderr, txt, args);
	fprintf(stderr, "\n");
	va_end(args);
}

void warning(string txt, ...){
	fflush(stdout);
	va_list args;
	va_start(args, txt);
	fprintf(stderr, "WARNING: ");
	vfprintf(stderr, txt, args);
	fprintf(stderr, "!\n");
	va_end(args);
}

void fatalError(string txt, ...){
	fflush(stdout);
	va_list args;
	va_start(args, txt);
	fprintf(stderr, "FATAL ERROR: ");
	vfprintf(stderr, txt, args);
	fprintf(stderr, "!\n");
	va_end(args);
	exit(1);
}

void outOfMemoria(void){
	erroFatal("Out of memory");
}

int compareIntegers(int i1, int i2)
			{ return comparaInteiros(i1, i2); }
string createString(string s)
			{ return criaString(s); }
void destroyString(string s)
			{ return destroiString(s); }
