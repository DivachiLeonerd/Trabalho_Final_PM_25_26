/*
 * Iterador.h
 */

#ifndef ITERADOR_H
#define ITERADOR_H

#include "Vetor.h"

/***********************************************
	TAD Iterador - Iteradores genericos
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Iterador *Iterador;
typedef Iterador Iterator;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaIterador - Cria um iterador
Parametros:
	v - vetor a iterar
	n - numero de elementos no vetor v
Retorno: o iterador criado
Precondicao: v != NULL && n >= 0
***********************************************/
Iterador criaIterador(vetor v, int n);
Iterador createIterator(vetor v, int n);

/***********************************************
criaOrdenadoIterador - Cria um iterador ordenado.
Parametros:
	v - vetor a iterar
	n - numero de elementos no vetor v
	comp - funcao de comparacao
Retorno: o iterador ordenado criado
Precondicao: v != NULL && n >= 0 && comp != NULL
***********************************************/
Iterador criaOrdenadoIterador(vetor v, int n, comparador comp);
Iterator createSortedIterator(vetor v, int n, comparator comp);

/***********************************************
destroiIterador - Elimina um iterador, mas nao os seus elementos.
Parametros: it - iterador
Retorno: nada
Precondicao: it != NULL
***********************************************/
void destroiIterador(Iterador it);
void destroyIterator(Iterator it);

/***********************************************
debugIterador - Converte em string, para mostrar em situacoes de debug.
Parametros: it - iterador
Retorno: a string criada
Precondicao: it != NULL
***********************************************/
string debugIterador(Iterador it);
string debugIterator(Iterator it);

/***********************************************
temSeguinteIterador - Testa se existe pelo menos mais um elemento para iterar.
Parametros: it - iterador
Retorno: true - caso existam mais elementos; false - caso contrario
Precondicao: it != NULL
***********************************************/
bool temSeguinteIterador(Iterador it);
bool hasNextIterator(Iterator it);

/***********************************************
seguinteIterador - Obtem o elemento seguinte no iterador.
Parametros: it - iterador
Retorno: elemento
Precondicao: it != NULL && temSeguinteIterador(it)
***********************************************/
obj seguinteIterador(Iterador it);
obj nextIterator(Iterator it);

/***********************************************
testeIterador - Alguns testes simples.
***********************************************/
void testeIterador(void);
void testIterator(void);

#endif /* ITERATOR_H */
