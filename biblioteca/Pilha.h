/*
 * Pilha.h
 */

#ifndef PILHA_H
#define PILHA_H

#include "Iterador.h"

/***********************************************
	TAD Pilha - Pilhas genericas
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Pilha *Pilha;
typedef Pilha Stack;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaPilha - Cria uma pilha vazia.
Parametros: nada
Retorno: a pilha criada
Precondicao: nada
***********************************************/
Pilha criaPilha(void);
Stack createStack(void);

/***********************************************
destroiPilha - Elimina uma pilha, mas nao os seus elementos.
Parametros: p - pilha
Retorno: nada
Precondicao: p != NULL
***********************************************/
void destroiPilha(Pilha p);
void destroyStack(Stack s);

/***********************************************
destroiTudoPilha - Elimina um pilha, mais os seus elementos.
Parametros: p - pilha
Retorno: nada
Precondicao: p != NULL
***********************************************/
void destroiTudoPilha(Pilha p);
void destroyAllStack(Stack s);

/***********************************************
debugPilha - Converte em string, para mostrar em situacoes de debug.
Parametros: p - pilha
Retorno: a string criada
Precondicao: p != NULL
***********************************************/
string debugPilha(Pilha p);
string debugStack(Stack s);

/***********************************************
vaziaPilha - Testa se a pilha esta vazia.
Parametros: p - pilha
Retorno: true - caso pilha vazia; false - caso contrario
Precondicao: p != NULL
***********************************************/
bool vaziaPilha(Pilha p);
bool emptyStack(Stack s);

/***********************************************
tamanhoPilha - Numero de elementos na pilha.
Parametros: p - pilha
Retorno: numero de elementos
Precondicao: p != NULL
***********************************************/
int tamanhoPilha(Pilha p);
int sizeStack(Stack s);

/***********************************************
topoPilha - O elemento no topo.
Parametros: p - pilha
Retorno: o elemento no topo
Precondicao: p != NULL && !vaziaPilha(p)
***********************************************/
obj topoPilha(Pilha p);
obj topStack(Stack s);

/***********************************************
emPilha - Empilha um elemento dado.
Parametros: p - pilha, elem - elemento
Retorno: nada
Precondicao: p != NULL
***********************************************/
void emPilha(Pilha p, obj elem);
void pushStack(Stack s, obj elem);

/***********************************************
desemPilha - Desempilha o elemento no topo.
Parametros: p - pilha
Retorno: retorna o elemento desempilhado
Precondicao: p != NULL && !vaziaPilha(p)
***********************************************/
obj desemPilha(Pilha p);
obj popStack(Stack s);

/***********************************************
iteradorPilha - Iterador para os elementos da pilha.
Parametros: p - pilha
Retorno: iterador dos elementos
Precondicao: p != NULL
***********************************************/
Iterador iteradorPilha(Pilha p);
Iterator iteratorStack(Stack s);

/***********************************************
iteradorOrdenadoPilha - Iterador ordenado para os elementos da pilha.
Parametros: p - pilha, comp - funcao de comparacao
Retorno: iterador dos elementos
Precondicao: p != NULL && comp != NULL
***********************************************/
Iterador iteradorOrdenadoPilha(Pilha p, comparador comp);
Iterator sortedIteradorStack(Stack s, comparator comp);

/***********************************************
testePilha - Alguns testes simples.
***********************************************/
void testePilha(void);
void testStack(void);

#endif /* PILHA_H */
