/*
 * PilhaLista.c
 */

#include "Pilha.h"
#include "Lista.h"

/*------------------------------------------*/
/* Tipo privado */

struct Pilha{
	Info info;
	lista elems;
};

/*	Os elementos entram e saem pela cabeca da lista.
	Fica eficiente. Comparar com a discussao
	em "FilaLista.c"
*/

/*------------------------------------------*/
/* Funcoes publicas */

Pilha criaPilha(void){
	Pilha p = malloc(sizeof(struct Pilha));
	if (p == NULL) semMemoria();
	p->info = criaInfo("Pilha", destroiPilha, destroiTudoPilha,
				NULL, NULL, debugPilha);
	p->elems = criaLista();	// lista vazia
	return p;
}

void destroiPilha(Pilha p){
	destroiLista(p->elems);
	free(p);
}

void destroiTudoPilha(Pilha p){
	destroiTudoLista(p->elems);
	free(p);
}

string debugPilha(Pilha p){
	return debugLista(p->elems);
}

bool vaziaPilha(Pilha p){
	return vaziaLista(p->elems);
}

int tamanhoPilha(Pilha p){
	return tamanhoLista(p->elems);
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj topoPilha(Pilha p){
	return primeiroNoLista(p->elems)->elem;
}

void emPilha(Pilha p, obj elem){
	p->elems = acrescentaPrimeiroLista(p->elems, elem);
}

/* Precondicao: p != NULL && !vaziaPilha(p) */
obj desemPilha(Pilha p){
	obj res;
	p->elems = removePrimeiroLista(p->elems, &res);
	return res;
}

Iterador iteradorPilha(Pilha p){
	return iteradorLista(p->elems);
}

Iterador iteradorOrdenadoPilha(Pilha p, comparador comp){
	return iteradorOrdenadoLista(p->elems, comp);
}

#include "Int.h"

void testePilha(void){
	printf("Testando Pilha:\n");

	Pilha p = criaPilha();
	emPilha(p, criaInt(0));
	emPilha(p, criaInt(1));
	emPilha(p, criaInt(2));
	emPilha(p, criaInt(3));
	printf("%s\n", debug(p));

	Iterador it = iteradorPilha(p);
	while (temSeguinteIterador(it))
		printf("%s\n", debug(seguinteIterador(it)));
	destroiIterador(it);

	printf("topo = %s\n", debug(topoPilha(p)));
	printf("desempilha = %s\n", debug(desemPilha(p)));
	printf("desempilha = %s\n", debug(desemPilha(p)));
	printf("%s\n", debug(p));
}

/*
Testando Pilha:
<3 2 1 0>
3
2
1
0
topo = 3
desempilha = 3
desempilha = 2
<1 0>
*/

/* ENGLISH */

Stack createStack(void)
			{ return criaPilha(); }
void destroyStack(Stack s)
			{ destroiPilha(s); }
void destroyAllStack(Stack s)
			{ destroiTudoPilha(s); }
string debugStack(Stack s)
			{ return debugPilha(s); }
bool emptyStack(Stack s)
			{ return vaziaPilha(s); }
int sizeStack(Stack s)
			{ return tamanhoPilha(s); }
obj topStack(Stack s)
			{ return topoPilha(s); }
void pushStack(Stack s, obj elem)
			{ emPilha(s, elem); }
obj popStack(Stack s)
			{ return desemPilha(s); }
Iterator iteratorStack(Stack s)
			{ return iteradorPilha(s); }
Iterator sortedIteradorStack(Stack s, comparator comp)
			{ return iteradorOrdenadoPilha(s, comp); }
void testStack(void)
			{ testePilha(); }
