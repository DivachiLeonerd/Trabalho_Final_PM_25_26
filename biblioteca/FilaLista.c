/*
 * FilaLista.c
 */

#include "Fila.h"
#include "Lista.h"

/*------------------------------------------*/
/* Tipo privado */

struct Fila{
	Info info;
	lista elems;
	lista ultimo;
};

/*	Os elementos entram pelo final da lista e saem pela
	cabeca da lista.
	Entrar pelo final da lista sera' ineficiente
	`a partida, por obrigar a percorrer toda a lista
	sempre que se acrescenta um novo elemento.
	Por isso, foi adicionado um apontador direto para
	o ultimo no' da lista. Assim ja' ficou eficiente.
*/

/*------------------------------------------*/
/* Funcoes publicas */

Fila criaFila(void){
	Fila f = malloc(sizeof(struct Fila));
	if (f == NULL) semMemoria();
	f->info = criaInfo("Fila", destroiFila, destroiTudoFila,
					NULL, NULL, debugFila);
	f->elems = criaLista();	// lista vazia
	f->ultimo = NULL;	// inicialmente, nao ha ultimo
	return f;
}

void destroiFila(Fila f){
	destroiLista(f->elems);
	free(f);
}

void destroiTudoFila(Fila f){
	destroiTudoLista(f->elems);
	free(f);
}

string debugFila(Fila f){
	return debugLista(f->elems);
}

bool vaziaFila(Fila f){
	return vaziaLista(f->elems);
}

int tamanhoFila(Fila f){
	return tamanhoLista(f->elems);
}

/* Precondicao: f != NULL && !vaziaFila(f) */
obj primeiroFila(Fila f){
	lista primeiro = primeiroNoLista(f->elems);
	return primeiro->elem;
}

void acrescentaFila(Fila f, obj elem){
	if (vaziaFila(f)){
		f->ultimo = f->elems = acrescentaPrimeiroLista(NULL, elem);
	}
	else {
		acrescentaSegundoLista(f->ultimo, elem);
		f->ultimo = segundoNoLista(f->ultimo);
	}
}

/* Precondicao: f != NULL && !vaziaFila(f) */
obj removeFila(Fila f){
	obj res;
	f->elems = removePrimeiroLista(f->elems, &res);
	if (vaziaFila(f))
		f->ultimo = NULL;
	return res;
}

Iterador iteradorFila(Fila f){
	return iteradorLista(f->elems);
}

Iterador iteradorOrdenadoFila(Fila f, comparador comp){
	return iteradorOrdenadoLista(f->elems, comp);
}

#include "Int.h"

void testeFila(void){
	printf("Testando Fila:\n");

	Fila f = criaFila();
	acrescentaFila(f, criaInt(0));
	acrescentaFila(f, criaInt(1));
	acrescentaFila(f, criaInt(2));
	acrescentaFila(f, criaInt(3));
	printf("%s\n", debugFila(f));

	Iterador it = iteradorFila(f);
	while (temSeguinteIterador(it))
		printf("%s\n", debug(seguinteIterador(it)));
	destroiIterador(it);

	printf("primeiro = %s\n", debug(primeiroFila(f)));
	printf("remove = %s\n", debug(removeFila(f)));
	printf("%s\n", debug(f));
	printf("remove = %s\n", debug(removeFila(f)));
	printf("%s\n", debug(f));
	printf("remove = %s\n", debug(removeFila(f)));
	printf("%s\n", debug(f));
	printf("remove = %s\n", debug(removeFila(f)));
	printf("%s\n", debug(f));
	acrescentaFila(f, criaInt(9));
	printf("%s\n", debugFila(f));
}

/*
Testando Fila:
<0 1 2 3>
0
1
2
3
primeiro = 0
remove = 0
<1 2 3>
remove = 1
<2 3>
remove = 2
<3>
remove = 3
<>
<9>
*/

/* ENGLISH */

Queue createQueue(void)
			{ return criaFila(); }
void destroyQueue(Queue q)
			{ destroiFila(q); }
void destroyAllQueue(Queue q)
			{ destroiTudoFila(q); }
string debugQueue(Queue q)
			{ return debugFila(q); }
bool emptyQueue(Queue q)
			{ return vaziaFila(q); }
int sizeQueue(Queue q)
			{ return tamanhoFila(q); }
obj firstQueue(Queue q)
			{ return primeiroFila(q); }
void addQueue(Queue q, obj elem)
			{ acrescentaFila(q, elem); }
obj removeQueue(Queue q)
			{ return removeFila(q); }
Iterador iteradorQueue(Queue q)
			{ return iteradorFila(q); }
Iterador sortedIteradorQueue(Queue q, comparator comp)
			{ return iteradorOrdenadoFila(q, comp); }
void testeQueue(void)
			{ testeFila(); }
