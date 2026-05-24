/*
 * List.c
 */

#include "Lista.h"

/*------------------------------------------*/
/* Funcoes publicas */

lista criaNo(obj elem, lista seg){
	lista n = malloc(sizeof(struct no));
	if (n == NULL) semMemoria();
	n->elem = elem;
	n->seg = seg;
	return n;
}

void destroiNo(lista l){
	free(l); // liberta apenas o no' apontado
}

lista criaLista(void){
	return NULL;
}

void destroiLista(lista l){
	lista seg;
	for ( ; l != NULL; l = seg){
		seg = l->seg;
		destroiNo(l);
	}
}

void destroiTudoLista(lista l){
	lista seg;
	for ( ; l != NULL; l = seg){
		seg = l->seg;
		destroiTudo(l->elem);
		destroiNo(l);
	}
}

string debugLista(lista l){
	int n;
	vetor v = vetorLista(l, &n);
	string d = debugVetorGeneral(v, n, "<", " ", ">");
	destroiVetor(v);
	return d;
}

bool vaziaLista(lista l){
	return l == NULL;
}

int tamanhoLista(lista l){
	int n = 0;
	for ( ; l != NULL ; l = l->seg, n++);
	return n;
}

/* Precondicao: l != NULL */
lista primeiroNoLista(lista l){
	return l;
}

/* Precondicao: l != NULL */
lista segundoNoLista(lista l){
	return l->seg;
}

/* Precondicao: l != NULL */
lista ultimoNoLista(lista l){
	for ( ; l->seg != NULL ; l = l->seg)
		/* nada */;
	return l;
}

/* Precondicao: 0 <= idx <= tamanhoLista(l) */
lista noLista(lista l, int idx){
	for (int i = 0; i < idx && l != NULL; i++, l = l->seg)
		/* nada */;
	if (l == NULL)
		erroFatal("Ultrapassou o final da lista %s", debugLista(l));
	return l;
}

lista acrescentaPrimeiroLista(lista l, obj elem){
	return criaNo(elem, l);
}

/* Precondicao: l != NULL */
void acrescentaSegundoLista(lista l, obj elem){
	lista segundo = criaNo(elem, l->seg);
	l->seg = segundo;
}

/* Precondicao: l != NULL */
lista removePrimeiroLista(lista l, obj *elem){
	*elem = l->elem;
	lista resto = l->seg;
	destroiNo(l);
	return resto;
}

/* Precondicao: l != NULL && l->seg != NULL */
void removeSegundoLista(lista l, obj *elem){
	l->seg = removePrimeiroLista(l->seg, elem);
}

Iterador iteradorLista(lista l){
	int n;
	vetor v = vetorLista(l, &n);
	Iterador it = criaIterador(v, n);
	destroiVetor(v);
	return it;
}

Iterador iteradorOrdenadoLista(lista l, comparador comp){
	int n;
	vetor v = vetorLista(l, &n);
	Iterador it = criaOrdenadoIterador(v, n, comp);
	destroiVetor(v);
	return it;
}

vetor vetorLista(lista l, int *n){
	*n = tamanhoLista(l);
	vetor v = malloc(sizeof(obj) * *n);
	if (v == NULL) semMemoria();
	for (int i = 0 ; l != NULL; i++, l = l->seg){
		v[i] = l->elem;
	}
	return v;
}

// Exercicios

#include "Int.h"

static lista criaIntervalo(int a, int b){
	if (a > b)	// intervalo vazio
		return NULL;
	// cria 1. no' fora do ciclo, com ult a apontar para o 1. no'
	lista l = criaNo(criaInt(a), NULL), ult = l;
	for (int i = a + 1 ; i <= b ; i++){
		// novo no', com o valor correto
		lista novo = criaNo(criaInt(i), NULL);
		ult->seg = novo;	// acrescenta no final (a seguir a ult)
		ult = novo;		// o novo no' passa a ser o ultimo
	}
	return l;
}

#if IGNORE
static lista criaIntervalo_cresce_ah_cabeca(int a, int b){
	lista res = NULL;
	for (int i = b ; i >= a ; i--)
		res = criaNo(criaInt(i), res);
	return res;
}
#endif

static lista eliminaValoresPares(lista l){
	lista ant = NULL;	// ira' apontar para o no' anterior
	for (lista x = l ; x != NULL ; ){
		if (valorInt(x->elem) % 2 == 0){	// valor par (multiplo de 2)
			lista apaga = x;
			if (ant == NULL){	// apaga na cabeca --> l avanca, x avanca, ant continua a NULL
				l = x->seg;
				x = x->seg;
			}
			else{	// apaga no meio --> x avanca, ant nao avanca
				ant->seg = x->seg;
				x = x->seg;
			}
			destroiNo(apaga);
		}
		else {	// nao apaga --> x avanca, ant avanca
			ant = x;
			x = x->seg;
		}
	}
	return l;
}

void testeLista(void){
	printf("Testando Lista:\n");

	lista l = criaIntervalo(1, 20);
	printf("%s\n", debugLista(l));
	acrescentaSegundoLista(l, criaInt(98));
	acrescentaSegundoLista(l, criaInt(99));
	printf("%s\n", debugLista(l));
	obj elem;
	l = removePrimeiroLista(l, &elem);
	printf("%s\n", debugLista(l));
	l = eliminaValoresPares(l);
	printf("%s\n", debugLista(l));
	destroiTudoLista(l);
	printf("acabou\n");
}

/*
Testando Lista:
<1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20>
<1 99 98 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20>
<99 98 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20>
<99 3 5 7 9 11 13 15 17 19>
acabou
*/

/* ENGLISH */

list createNode(obj elem, list next)
			{ return criaNo(elem, next); }
void destroyNode(list l)
			{ destroiNo(l); }
void destroyList(list l)
			{ destroiLista(l); }
void destroyAllList(list l)
			{ destroiTudoLista(l); }
string debugList(list l)
			{ return debugLista(l); }
bool emptyList(list l)
			{ return vaziaLista(l); }
int sizeList(list l)
			{ return tamanhoLista(l); }
list firstNodeList(list l)
			{ return primeiroNoLista(l); }
list secondNodeList(list l)
			{ return segundoNoLista(l); }
list lastNodeList(list l)
			{ return ultimoNoLista(l); }
list nodeList(list l, int idx)
			{ return noLista(l, idx); }
list addFirstList(list l, obj elem)
			{ return acrescentaPrimeiroLista(l, elem); }
void addSecondList(list l, obj elem)
			{ acrescentaSegundoLista(l, elem); }
list removeFirstList(list l, obj *elem)
			{ return removePrimeiroLista(l, elem); }
void removeSecondList(list l, obj *elem)
			{ removeSegundoLista(l, elem); }
Iterator iteratorList(list l)
			{ return iteradorLista(l); }
Iterator sortedIteratorList(list l, comparator comp)
			{ return iteradorOrdenadoLista(l, comp); }
vector vectorList(list l, int *n)
			{ return vetorLista(l, n); }
void testList(void)
			{ testeLista(); }
