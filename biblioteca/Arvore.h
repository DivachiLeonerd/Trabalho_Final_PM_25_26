/*
 * Arvore.h
 */

#ifndef ARVORE_H
#define ARVORE_H

#include "Iterador.h"

/***********************************************
	Modulo Arvore - Arvores binarias genericas (nao e' TAD)
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct noArvore {
	obj elem;
	struct noArvore *esq, *dir;	// tipo recursivo
} *arvore;
typedef arvore tree;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaNoArvore - Cria um no de arvore binaria.
Parametros:
	elem - o elemento guardado
	esq, dir - as subarvorees esquerda e direita
Retorno: o no' criado
Precondicao: elem != NULL (dir e esq pode ser NULL)
***********************************************/
arvore criaNoArvore(obj elem, arvore esq, arvore dir);
tree createNodeTree(obj elem, tree left, tree right);

/***********************************************
destroiNoArvore - Elimina o no' apontado por a.
Parametros: a - apontador para o no' a eliminar
	(nao elimina a arvore completa)
Retorno: nada
Precondicao: a != NULL
***********************************************/
void destroiNoArvore(arvore a);
void destroyNodeTree(tree t);

/***********************************************
destroiArvore - Elimina todos os nos da arvore,
	mas nao os elementos la' guardados.
Parametros: a - arvore
Retorno: nada
Precondicao: nada (a pode ser NULL)
***********************************************/
void destroiArvore(arvore a);
void destroyTree(tree t);

/***********************************************
destroiTudoArvore - Elimina todos os nos da lista,
	mais os elementos la' guardados.
Parametros: a - arvore
Retorno: nada
Precondicao: nada (a pode ser NULL)
***********************************************/
void destroiTudoArvore(arvore a);
void destroyAllTree(tree t);

/***********************************************
debugArvore - Converte em string, para mostrar em situacoes de debug.
Parametros: a - arvore
Retorno: a string criada
Precondicao: nada
***********************************************/
string debugArvore(arvore a);
string debugTree(tree t);

/***********************************************
vaziaArvore - Testa se a arvore esta vazia.
Parametros: a - arvore
Retorno: true - se arvore vazia; false - caso contrario
Precondicao: nada
***********************************************/
bool vaziaArvore(arvore a);
bool emptyTree(tree t);

/***********************************************
tamanhoArvore - Numero de elementos na arvore.
Parametros: a - arvore
Retorno: numero de elementos
Precondicao: nada
***********************************************/
int tamanhoArvore(arvore a);
int sizeTree(tree t);

/***********************************************
iteradorArvore - Iterador para os elementos da arvore.
Parametros: a - arvore
Retorno: iterador dos elementos
Precondicao: nada
***********************************************/
Iterador iteradorArvore(arvore a);
Iterator iteratorTree(tree t);

/***********************************************
iteradorOrdenadoArvore - Iterador para os elementos da arvore.
Parametros: a - arvore, comp - funcao de comparacao
Retorno: iterador ordenado dos elementos
Precondicao: comp != NULL
***********************************************/
Iterador iteradorOrdenadoArvore(arvore l, comparador comp);
Iterator sortedIteratorTree(tree t, comparator comp);

/***********************************************
testeArvore - Alguns testes simples.
***********************************************/
void testeArvore(void);
void testTree(void);

#endif /* ARVORE_H */
