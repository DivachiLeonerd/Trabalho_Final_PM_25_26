/*
 * Int.h
 */

#ifndef INT_H
#define INT_H

#include "Util.h"

/***********************************************
	TAD Int - Inteiros representados por objetos
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Int *Int;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaInt - Cria um objeto que representa um inteiro.
Parametros: valor - o inteiro a representar
Retorno: o objeto criado
Precondicao: nada
***********************************************/
Int criaInt(int valor);
Int createInt(int valor);

/***********************************************
destroiInt - Elimina um objeto inteiro.
Parametros: i - objeto inteiro
Retorno: nada
Precondicao: i != NULL
***********************************************/
void destroiInt(Int i);
void destroyInt(Int i);

/***********************************************
comparaInt - Compara dois ints.
Parametros: i1, i2 - ints a comparar
Retorno: negativo, zero ou positivo
Precondicao: i1 != NULL && i2 != NULL
***********************************************/
int comparaInt(Int i1, Int i2);
int compareInt(Int i1, Int i2);

/***********************************************
dispersaoInt - Funcao de dispersao dos ints.
Parametros: i - objeto inteiro; dim - dimensao da tabela
Retorno: valor de dispersao
Precondicao: i != NULL && dim > 0
***********************************************/
int dispersaoInt(Int i, int dim);
int hashInt(Int i, int dim);

/***********************************************
debugInt - Converte em string, para mostrar em situacoes de debug.
Parametros: i - objeto inteiro
Retorno: a string criada
Precondicao: i != NULL
***********************************************/
string debugInt(Int i);
string debugInt(Int i);

/***********************************************
valorInt - Extrai o valor inteiro guardado num objeto inteiro.
Parametros: i - objeto inteiro
Retorno: o inteiro guardado no objeto
Precondicao: i != NULL
**********************************************/
int valorInt(Int i);
int valueInt(Int i);

/***********************************************
testeInt - Alguns testes simples.
***********************************************/
void testeInt(void);
void testInt(void);

#endif /* INT_H */
