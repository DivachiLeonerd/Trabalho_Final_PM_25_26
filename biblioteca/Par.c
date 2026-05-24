/*
 * Par.c
 */

#include "Par.h"

/*------------------------------------------*/
/* Tipo privado */

struct Par {
	Info info;
	obj a;
	obj b;
};

/*------------------------------------------*/
/* Funcoes publicas */

Par criaPar(obj a, obj b){
	Par p = malloc(sizeof(struct Par));
	if (p == NULL) semMemoria();
	p->info = criaInfo("Par", destroiPar, destroiTudoPar,
				comparaPar, NULL, debugPar);
	p->a = a;
	p->b = b;
	return p;
}

void destroiPar(Par p){
	free(p);
}

void destroiTudoPar(Par p){
	destroiTudo(p->a);
	destroiTudo(p->b);
	destroiPar(p);
}

// Compara-se a primeira componente.
// Em caso de empate, compara-se a segunda componente.
int comparaPar(Par p1, Par p2){
	int r1 = compara(p1->a, p2->a);
	return r1 == 0 ? compara(p1->b, p2->b): r1;
}

string debugPar(Par p){
	#include "Vetor.h"
	obj v[2] = {p->a, p->b};
	return debugVetorGeneral(v, 2, "(", ", ", ")");
}

obj valorAPar(Par p){
	return p->a;
}

obj valorBPar(Par p){
	return p->b;
}

#include "Int.h"
#include "Str.h"

void testePar(void){
	printf("Testando Par:\n");

	Par p1 = criaPar(criaInt(23), criaInt(-999));
	printf("%s\n", debugPar(p1));
	Par p2 = criaPar(criaInt(0), criaStr("ola"));
	printf("%s\n", debugPar(p2));
	Par p3 = criaPar(p1, p2);
	printf("%s\n", debugPar(p3));
	destroiTudoPar(p3);
}

/*
Testando Par:
(23, -999)
(23, -999
*/

/* ENGLISH */

Par createPair(obj a, obj b)
			{ return criaPar(a, b); }
void destroyPair(Pair p)
			{ destroiPar(p); }
void destroyAllPair(Pair p)
			{ destroiTudoPar(p); }
int comparePair(Pair p1, Pair p2)
			{ return comparaPar(p1, p2); }
string debugPair(Pair p)
			{ return debugPar(p); }
obj valueAPair(Pair p)
			{ return valorAPar(p); }
obj valueBPair(Pair p)
			{ return valorBPar(p); }
void testPair(void)
			{ testePar(); }
