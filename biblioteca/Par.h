/*
 * Par.h
 */

#ifndef PAR_H
#define PAR_H

#include "Info.h"

/***********************************************
	TAD Par - Pares ordenados genericos
***********************************************/

/*------------------------------------------*/
/* Tipo publico */
typedef struct Par *Par;
typedef Par Pair;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaPar - Cria um objeto par ordenado.
Parametros: a, b - as componentes a guardar no par
Retorno: o par criado
Precondicao: a != NULL && a != NULL
***********************************************/
Par criaPar(obj a, obj b);
Par createPair(obj a, obj b);

/***********************************************
destroiPar - Elimina um par, mas nao os seus elementos.
Parametros: p - par
Retorno: nada
Precondicao: p != NULL
***********************************************/
void destroiPar(Par p);
void destroyPair(Pair p);

/***********************************************
destroiTudoPar - Elimina um par, mais os seus elementos.
Parametros: p - par
Retorno: nada
Precondicao: p != NULL
***********************************************/
void destroiTudoPar(Par p);
void destroyAllPair(Pair p);

/***********************************************
comparaPar - Compara dois pares.
Parametros: p1, p2 - pares a comparar
Retorno: negativo, zero ou positivo
Precondicao: p1 != NULL && p2 != NULL
***********************************************/
int comparaPar(Par p1, Par p2);
int comparePair(Pair p1, Pair p2);

/***********************************************
debugPar - Converte em string, para mostrar em situacoes de debug.
Parametros: p - par
Retorno: a string criada
Precondicao: p != NULL
***********************************************/
string debugPar(Par p);
string debugPair(Pair p);

/***********************************************
valorAPar - Obtem a primeira componente dum par ordenado.
Parametros: p - par
Retorno: a primeira componente
Precondicao: p != NULL
**********************************************/
obj valorAPar(Par p);
obj valueAPair(Pair p);

/***********************************************
valorBPar - Obtem a segunda componente dum par ordenado.
Parametros: p - par
Retorno: a segunda componente
Precondicao: p != NULL
**********************************************/
obj valorBPar(Par p);
obj valueBPair(Pair p);

/***********************************************
testePar - Alguns testes simples.
***********************************************/
void testePar(void);
void testPair(void);

#endif /* PAR_H */
