/*
 * Util.h
 */

#ifndef UTIL_H
#define UTIL_H

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdarg.h>

/*******************************************************
	Modulo Util - Miscelania de definicoes uteis (nao e' TAD)
*******************************************************/

/*------------------------------------------*/
/* Constantes publicas */

#define NAO_EXISTE		(-1)
#define BUFFER_SIZE		1024

/*------------------------------------------*/
/* Tipos publicos */

/***********************************************
Para representar o tipo das strings, voce pode
usar char * ou string; depende da sua preferencia.
***********************************************/
typedef char *string;

/***********************************************
Para representar o tipo das string que reservam
espaco para o texto.
***********************************************/
typedef char buffer[BUFFER_SIZE];


/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
mensagem - Escreve um mensagem formatada no canal de erros.
Parametros:
	txt - a mensagem a escrever
	... - argumentos extra
Retorno: nada
Precondicao: txt != NULL
***********************************************/
void mensagem(string txt, ...);
void message(string txt, ...);


/***********************************************
aviso - Escreve um aviso formatado no canal de erros.
Parametros:
	txt - a mensagem a escrever
	... - argumentos extra
Retorno: nada
Precondicao: txt != NULL
***********************************************/
void aviso(string txt, ...);
void warning(string txt, ...);

/***********************************************
erroFatal - Escreve uma mensagem de erro formatada
	e aborta a execucao do programa.
Parametros:
	txt - a mensagem a escrever
	... - argumentos extra
Retorno: nada
Precondicao: txt != NULL
***********************************************/
void erroFatal(string txt, ...);
void fatalError(string txt, ...);

/***********************************************
semMemoria - Escreve mensagem de falta de memoria e
	aborta a execucao do programa.
Parametros: nada
Retorno: nada
Precondicao: nada
***********************************************/
void semMemoria(void);
void outOfMemoria(void);

/***********************************************
comparaInteiros - Compara dois valores inteiros.
Parametros: i1, i2 - dois inteiros
Retorno: 0 se i1 = i2; -1 se i1 < i2; 1 se i1 > i2
Precondicao: nada
***********************************************/
int comparaInteiros(int i1, int i2);
int compareIntegers(int i1, int i2);

/***********************************************
criaString - Aloca dinamicamente uma string.
Parametros: s - uma string
Retorno: apontador para uma copia da string s
Precondicao: s != NULL
***********************************************/
string criaString(string s);
string createString(string s);

/***********************************************
destroiString - Elimina uma string que foi previamente criada usando
alguma das funcoes de criacao anteriores.
Parametros: s - uma string dinamica
Retorno: nada
Precondicao: s != NULL
***********************************************/
void destroiString(string s);
void destroyString(string s);

#endif /* UTIL_H */
