/*
 * IteradorVetor.c
 */

#include "Iterador.h"

/*------------------------------------------*/
/* Tipo privado */

struct Iterador{
	Info info;
	vetor elems;	// usa uma copia
	int numElems;
	int corrente;
};

/*------------------------------------------*/
/* Funcoes publicas */

Iterador criaIterador(vetor v, int n){
	Iterador it = malloc(sizeof(struct Iterador));
	if (it == NULL) semMemoria();
	it->info = criaInfo("Iterador", destroiIterador, destroiIterador,
					NULL, NULL, debugIterador);
	it->elems = copiaVetor(v, n);	// faz uma copia porque o original podera'
	it->numElems = n;				// ser alterado depois do iterador ser criado
	it->corrente = 0;
	return it;
}

Iterador criaOrdenadoIterador(vetor v, int n, comparador comp){
	vetor temp = copiaVetor(v, n);	// faz uma copia nao estragar o original
	ordenaVetor(temp, n, comp);
	Iterador it = criaIterador(temp, n);
	destroiVetor(temp);
	return it;
}

void destroiIterador(Iterador it){
	free(it->elems);	// destroi a copia
	free(it);
}

string debugIterador(Iterador it){
	return debugVetor(it->elems, it->numElems);
}

bool temSeguinteIterador(Iterador it){
	return it->corrente < it->numElems;
}

/* Precondicao: it != NULL && temSeguinteIterador(it) */
obj seguinteIterador(Iterador it){
	return it->elems[it->corrente++];
}

#include "Int.h"

void testeIterador(void){
	printf("Testando Iterador:\n");

	int cap = 17;
	vetor v = malloc(sizeof(obj) * cap);
	if (v == NULL) semMemoria();
	for (int valor = 0; valor < cap; valor++)
		v[valor] = criaInt(valor);
	Iterador it = criaIterador(v, cap);
	printf("\t%s\n", debugIterador(it));
	destroiIterador(it);
}

/*
Testando Iterador:
        [0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16]
*/

/* ENGLISH */

Iterador createIterator(vetor v, int n)
			{ return criaIterador(v, n); }
Iterator createSortedIterator(vetor v, int n, comparator comp)
			{ return criaOrdenadoIterador(v, n, comp); }
void destroyIterator(Iterator it)
			{ destroiIterador(it); }
string debugIterator(Iterator it)
			{ return debugIterador(it); }
bool hasNextIterator(Iterator it)
			{ return temSeguinteIterador(it); }
obj nextIterator(Iterator it)
			{ return seguinteIterador(it); }
void testIterator(void)
			{ testeIterador(); }
