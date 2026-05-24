/*
 * Sequencia.h
 */

#ifndef SEQUENCIA_H
#define SEQUENCIA_H

#include "Iterador.h"

/***********************************************
	TAD Sequencia - Sequencias genericas
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Sequencia *Sequencia;
typedef Sequencia Sequence;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaSequencia - Cria uma sequencia vazia.
Parametros: nada
Retorno: a sequencia criada
Precondicao: nada
***********************************************/
Sequencia criaSequencia(void);
Sequencia createSequence(void);

/***********************************************
destroiSequencia - Elimina uma sequencia, mas nao os seus elementos.
Parametros: s - sequencia
Retorno: nada
Precondicao: s != NULL
***********************************************/
void destroiSequencia(Sequencia s);
void destroySequence(Sequence s);

/***********************************************
destroiTudoSequencia - Elimina uma sequencia, mais os seus elementos.
Parametros: s - sequencia
Retorno: nada
Precondicao: s != NULL
***********************************************/
void destroiTudoSequencia(Sequencia s);
void destroyAllSequence(Sequence s);

/***********************************************
debugSequencia - Converte em string, para mostrar em situacoes de debug.
Parametros: s - sequencia
Retorno: a string criada
Precondicao: s != NULL
***********************************************/
string debugSequencia(Sequencia s);
string debugSequence(Sequence s);

/***********************************************
vaziaSequencia - Testa se a sequencia esta vazia.
Parametros: s - sequencia
Retorno: true - se sequencia vazia; false - caso contrario
Precondicao: s != NULL
***********************************************/
bool vaziaSequencia(Sequencia s);
bool emptySequence(Sequence s);

/***********************************************
tamanhoSequencia - Numero de elementos na sequencia.
Parametros: s - sequencia
Retorno: numero de elementos
Precondicao: s != NULL
***********************************************/
int tamanhoSequencia(Sequencia s);
int sizeSequence(Sequence s);

/***********************************************
elementoSequencia - O i-esimo elemento da sequencia.
Parametros:
	s - sequencia
	i - posicao ocupada na sequencia; conta a partir de 0;
		i tambem pode ser negativo para indicar uma
		posicao contada a partir do final
Retorno: elemento na posicao i
Precondicao: s != NULL
		&& -tamanhoSequencia(s) <= i < tamanhoSequencia(s)
***********************************************/
obj elementoSequencia(Sequencia s, int i);
obj elementSequence(Sequence s, int i);

/***********************************************
atribuiSequencia - Coloca o elemento na posicao ocupada i,
	trocando o elemento que la' se encontrava.
Parametros:
	s - sequencia
	elem - elemento a colocar
	i - posicao ocupada da sequencia; conta a partir de 0;
		i tambem pode ser negativo para indicar uma
		posicao ocupada, contada a partir do final
Retorno: retorna o elemento que ocupava a posicao i
Precondicao: s != NULL && elem != NULL
		&& -tamanhoSequencia(s) <= i < tamanhoSequencia(s)
***********************************************/
obj atribuiSequencia(Sequencia s, obj elem, int i);
obj assignSequence(Sequence s, obj elem, int i);

/***********************************************
insereSequencia - Insere um elemento na posicao i,
	empurrando para a frente todos os elementos
	da posicao i em diante.
Parametros:
	s - sequencia
	elem - elemento
	i - posicao ocupada na sequencia; conta a partir de 0;
		i tambem pode indicar a primeira posicao livre de s;
		i tambem pode ser negativo para indicar uma
		posicao ocupada, contada a partir do final
Retorno: nada
Precondicao: s != NULL && elem != NULL
		&& -tamanhoSequencia(s) <= i <= tamanhoSequencia(s)
***********************************************/
void insereSequencia(Sequencia s, obj elem, int i);
void insertSequence(Sequence s, obj elem, int i);

/***********************************************
acrescentaSequencia - Acrescenta um elemento no final, na
	primeira posicao livre.
	Equivalente a insereSequencia(s, elem, tamanhoSequencia(s))
Parametros:
	s - sequencia
	elem - elemento
Retorno: nada
Precondicao: s != NULL && elem != NULL
***********************************************/
void acrescentaSequencia(Sequencia s, obj elem);
void addSequence(Sequence s, obj elem);

/***********************************************
removeSequencia - Remove o elemento da posicao ocupada i.
Parametros:
	s - sequencia
	i - posicao ocupada na sequencia; conta a partir de 0;
		i tambem pode ser negativo para indicar uma
		posicao ocupada, contada a partir do final
Retorno: o elemento removido
Precondicao: s != NULL
		&& -tamanhoSequencia(s) <= i < tamanhoSequencia(s)
***********************************************/
obj removeSequencia(Sequencia s, int i);
obj removeSequence(Sequence s, int i);

/***********************************************
iteradorSequencia - Iterador para os elementos da sequencia.
Parametros: s - sequencia
Retorno: iterador dos elementos
Precondicao: s != NULL
***********************************************/
Iterador iteradorSequencia(Sequencia s);
Iterator iteratorSequence(Sequence s);

/***********************************************
iteradorOrdenadoSequencia - Iterador ordenado para os elementos da sequencia.
Parametros: s - sequencia, comp - funcao de comparacao
Retorno: iterador dos elementos
Precondicao: s != NULL && comp != NULL
***********************************************/
Iterador iteradorOrdenadoSequencia(Sequencia s, comparador comp);
Iterator sortedIteradorSequence(Sequencia s, comparator comp);

/***********************************************
testeSequencia - Alguns testes simples.
***********************************************/
void testeSequencia(void);
void testSequence(void);

#endif /* SEQUENCIA_H */
