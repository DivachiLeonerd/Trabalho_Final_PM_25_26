/*
 * Int.c
 */

#include "Int.h"
#include "Info.h"

/*------------------------------------------*/
/* Tipo privado */

struct Int {
	Info info;
	int valor;
};

/*------------------------------------------*/
/* Funcoes publicas */

Int criaInt(int valor){
	Int i = malloc(sizeof(struct Int));
	if (i == NULL) semMemoria();
	i->info = criaInfo("Int", destroiInt, destroiInt,
				comparaInt, dispersaoInt, debugInt);
	i->valor = valor;
	return i;
}

void destroiInt(Int i){
	free(i);
}

int comparaInt(Int i1, Int i2){
	int v1 = valorInt(i1);
	int v2 = valorInt(i2);
	return comparaInteiros(v1, v2);
}

int dispersaoInt(Int i, int dim){
	return valorInt(i) % dim;
}

string debugInt(Int i){
	char txt[100];
	sprintf(txt, "%d", valorInt(i));
	return criaString(txt);
}

int valorInt(Int i){
	return i->valor;
}

void testeInt(void){
	printf("Testando Int:\n");

	Int x = criaInt(3);
	for (int valor = 0 ; valor < 10 ; valor++){
		Int i = criaInt(valor);
		printf("(%s,%d,%d)\n",
			debugInt(i),
			comparaInt(i, x),
			dispersaoInt(i, 4));
		destroiInt(i);
	}
}

/*
Testando Int:
(0,-1,0)
(1,-1,1)
(2,-1,2)
(3,0,3)
(4,1,0)
(5,1,1)
(6,1,2)
(7,1,3)
(8,1,0)
(9,1,1)
*/


/* ENGLISH */

Int createInt(int valor)
			{ return criaInt(valor); }
void destroyInt(Int i)
			{ destroiInt(i); }
int compareInt(Int i1, Int i2)
			{ return comparaInt(i1, i2); }
int hashInt(Int i, int dim)
			{ return dispersaoInt(i, dim); }
// string debugInt(Int i)
//			{ return debugInt(i); }
int valueInt(Int i)
			{ return valorInt(i); }
void testInt(void)
			{ testeInt(); }
