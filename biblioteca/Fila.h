/*
 * Fila.h
 */

#ifndef FILA_H
#define FILA_H

#include "Iterador.h"

/***********************************************
	TAD Fila - Filas genericas
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Fila *Fila;
typedef Fila Queue;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaFila - Cria uma fila vazia.
Parametros: nada
Retorno: a fila criada
Precondicao: nada
***********************************************/
Fila criaFila(void);
Queue createQueue(void);

/***********************************************
destroiFila - Elimina uma fila, mas nao os seus elementos.
Parametros: f - fila
Retorno: nada
Precondicao: f != NULL
***********************************************/
void destroiFila(Fila f);
void destroyQueue(Queue q);

/***********************************************
destroiTudoFila - Elimina uma fila, mais os seus elementos.
Parametros: f - fila
Retorno: nada
Precondicao: f != NULL
***********************************************/
void destroiTudoFila(Fila f);
void destroyAllQueue(Queue q);

/***********************************************
debugFila - Converte em string, para mostrar em situacoes de debug.
Parametros: f - fila
Retorno: a string criada
Precondicao: f != NULL
***********************************************/
string debugFila(Fila f);
string debugQueue(Queue q);

/***********************************************
vaziaFila - Testa se a fila esta vazia.
Parametros: f - fila
Retorno: true - caso fila vazia; false - caso contrario
Precondicao: f != NULL
***********************************************/
bool vaziaFila(Fila f);
bool emptyQueue(Queue q);

/***********************************************
tamanhoFila - Numero de elementos na fila.
Parametros: f - fila
Retorno: numero de elementos
Precondicao: f != NULL
***********************************************/
int tamanhoFila(Fila f);
int sizeQueue(Queue q);

/***********************************************
primeiroFila - O primeiro elemento.
Parametros: f - fila
Retorno: o primeiro elemento
Precondicao: f != NULL && !vaziaFila(f)
***********************************************/
obj primeiroFila(Fila f);
obj firstQueue(Queue q);

/***********************************************
acrescentaFila - Acrescenta um elemento no final.
Parametros: f - fila; elem - elemento
Retorno: nada
Precondicao: f != NULL
***********************************************/
void acrescentaFila(Fila f, obj elem);
void addQueue(Queue q, obj elem);

/***********************************************
removeFila - Remove o primeiro elemento.
Parametros: f - fila
Retorno: retorna o elemento
Precondicao: f != NULL && !vaziaFila(f)
***********************************************/
obj removeFila(Fila f);
obj removeQueue(Queue q);

/***********************************************
iteradorFila - Iterador para os elementos da fila.
Parametros: f - fila
Retorno: iterador dos elementos
Precondicao: f != NULL
***********************************************/
Iterador iteradorFila(Fila f);
Iterador iteradorQueue(Queue q);

/***********************************************
iteradorOrdenadoFila - Iterador ordenado para os elementos da fila.
Parametros: f - fila
Retorno: iterador dos elementos
Precondicao: f != NULL && comp != NULL
***********************************************/
Iterador iteradorOrdenadoFila(Fila f, comparador comp);
Iterador sortedIteradorQueue(Queue q, comparator comp);

/***********************************************
testeFila - Alguns testes simples.
***********************************************/
void testeFila(void);
void testeQueue(void);

#endif /* FILA_H */
