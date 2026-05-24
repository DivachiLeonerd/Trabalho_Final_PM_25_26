/*
 * Lista.h
 */

#ifndef LISTA_H
#define LISTA_H

#include "Iterador.h"

/***********************************************
	Modulo Lista - Listas genericas (nao e' TAD)
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct no {
	obj elem;
	struct no *seg;	// tipo recursivo
} *lista;
typedef lista list;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaNo - Cria um no'.
Parametros:
	elem - o elemento guardado no no'
	seg - o no' seguinte
Retorno: o no' criado
Precondicao: elem != NULL (seg pode ser NULL)
***********************************************/
lista criaNo(obj elem, lista seg);
list createNode(obj elem, list next);

/***********************************************
destroiNo - Elimina o no' apontado por l.
Parametros: l - apontador para o no' a eliminar
	(nao elimina a lista completa)
Retorno: nada
Precondicao: l != NULL
***********************************************/
void destroiNo(lista l);
void destroyNode(list l);

/***********************************************
criaLista - Cria lista vazia.
Parametros: nada
Retorno: lista vazia
Precondicao: nada
***********************************************/
lista criaLista(void);
list createList(void);

/***********************************************
destroiLista - Elimina todos os nos da lista,
	mas nao os elementos guardados.
Parametros: l - lista
Retorno: nada
Precondicao: nada (l pode ser NULL)
***********************************************/
void destroiLista(lista l);
void destroyList(list l);

/***********************************************
destroiTudoLista - Elimina todos os nos da lista,
	mais os elementos la' guardados.
Parametros: l - lista
Retorno: nada
Precondicao: nada (l pode ser NULL)
***********************************************/
void destroiTudoLista(lista l);
void destroyAllList(list l);

/***********************************************
debugLista - Converte em string, para mostrar em situacoes de debug.
Parametros: l - lista
Retorno: a string criada
Precondicao: nada
***********************************************/
string debugLista(lista l);
string debugList(list l);

/***********************************************
vaziaLista - Testa se a lista esta vazia.
Parametros: l - lista
Retorno: true - se lista vazia; false - caso contrario
Precondicao: nada
***********************************************/
bool vaziaLista(lista l);
bool emptyList(list l);

/***********************************************
tamanhoLista - Numero de elementos na lista.
Parametros: l - lista
Retorno: numero de elementos
Precondicao: nada
***********************************************/
int tamanhoLista(lista l);
int sizeList(list l);

/***********************************************
primeiroNoLista - O primeiro no' da lista.
Parametros: l - lista
Retorno: O primeiro no' da lista.
Precondicao: l != NULL
***********************************************/
lista primeiroNoLista(lista l);
list firstNodeList(list l);

/***********************************************
primeiroNoLista - O segundo no' da lista.
Parametros: l - lista
Retorno: O segundo no' da lista.
Precondicao: l != NULL
***********************************************/
lista segundoNoLista(lista l);
list secondNodeList(list l);

/***********************************************
ultimoNoLista - O ultimo no' da lista.
Parametros: l - lista
Retorno: O ultimo no' da lista.
Precondicao: l != NULL
***********************************************/
lista ultimoNoLista(lista l);
list lastNodeList(list l);

/***********************************************
noLista - O i-esimo no' da lista.
Parametros: l - lista
Retorno: O i-esimo no' da lista.
Precondicao: 0 <= idx <= tamanhoLista(l)
***********************************************/
lista noLista(lista l, int idx);
list nodeList(list l, int idx);

/***********************************************
acrescentaPrimeiroLista - Acrescenta elemento para
				ficar a ser o primeiro da lista.
Parametros: l - lista; elem - elemento a acrescentar
Retorno: a lista modificada.
Precondicao: nada (l pode ser NULL)
***********************************************/
lista acrescentaPrimeiroLista(lista l, obj elem);
list addFirstList(list l, obj elem);

/***********************************************
acrescentaSegundoLista - Acrescenta elemento para
				ficar a ser o segundo da lista.
Parametros: l - lista; elem - elemento a acrescentar
Retorno: nada
Precondicao: l != NULL
***********************************************/
void acrescentaSegundoLista(lista l, obj elem);
void addSecondList(list l, obj elem);

/***********************************************
removePrimeiroLista - Remove elemento no
				início duma lista.
Parametros: l - lista; elem - elemento removido
Retorno: a lista modificada.
Precondicao: l != NULL
***********************************************/
lista removePrimeiroLista(lista l, obj *elem);
list removeFirstList(list l, obj *elem);

/***********************************************
removeSegundoLista - Remove elemento na
				posicao 2 duma lista.
Parametros: l - lista; elem - elemento removido
Retorno: nada
Precondicao: l != NULL && l->seg != NULL
***********************************************/
void removeSegundoLista(lista l, obj *elem);
void removeSecondList(list l, obj *elem);

/***********************************************
iteradorLista - Iterador para os elementos da lista.
Parametros: l - lista
Retorno: iterador dos elementos
Precondicao: nada
***********************************************/
Iterador iteradorLista(lista l);
Iterator iteratorList(list l);

/***********************************************
iteradorOrdenadoLista - Iterador ordenado para os
				elementos da lista.
Parametros: l - lista, comp - funcao de comparacao
Retorno: iterador ordenado dos elementos
Precondicao: comp != NULL
***********************************************/
Iterador iteradorOrdenadoLista(lista l, comparador comp);
Iterator sortedIteratorList(list l, comparator comp);

/***********************************************
vetorLista - Converte lista para vetor. Usar apenas como
	auxiliar para criar iteradores.
Parametros: l - lista, n - apontador para var inteira
Retorno: vetor com os elementos da lista pela mesma ordem.
	Destruir o vetor depois de usar.
Precondicao: n != NULL
***********************************************/
vetor vetorLista(lista l, int *n);
vector vectorList(list l, int *n);

/***********************************************
testeLista - Alguns testes simples.
***********************************************/
void testeLista(void);
void testList(void);

#endif /* LISTA_H */
