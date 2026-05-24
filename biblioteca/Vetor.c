/*
 * Vetor.c
 */

#include "Vetor.h"

/*------------------------------------------*/
/* Funcoes privadas */

static void troca(obj *ob1, obj *ob2){
	obj aux = *ob1;
	*ob1 = *ob2;
	*ob2 = aux;
}

/*------------------------------------------*/
/* Funcoes publicas */

vetor criaVetor()
{
	vetor new_vector = (vetor)malloc(10 * sizeof(char));
	if (!new_vector)
		semMemoria();
	return new_vector;
}

vetor copiaVetor(vetor v, int n){
	vetor original = v;
	vetor copia = malloc(sizeof(obj) * n);
	for (int i = 0 ; i < n ; i++){
		copia[i] = original[i];
	}
	return copia;
}

void destroiVetor(vetor v){
	free(v);
}

void destroiTudoVetor(vetor v, int n){
	for (int i = 0; i < n; i++)
		destroiTudo(v[i]);
	free(v);
}

bool ordenadoVetor(vetor v, int n, comparador comp){
	for (int i = 0; i < n-1; i++){
		if (((comparadorObj)comp)(v[i], v[i+1]) > 0)
			return false;
	}
	return true;
}

// ordenacao por selecao (selection sort)
void ordenaVetor(vetor v, int n, comparador comp){
	for (int i=0; i < n-1; i++){
		int minIdx = i;	// regista indice do minimo ate' ao momento
		for (int j=i+1; j < n; j++){ // procura minimo em [i, n-1]
			if (((comparadorObj)comp)(v[j], v[minIdx]) < 0)
				minIdx = j;
		}
		troca(&v[i], &v[minIdx]);
	}
}

bool homogeneoVetor(vetor v, int n){
	for (int i = 1 ; i < n ; i++){
		if (!mesmoTipo(v[0], v[i]))
			return false;
	}
	return true;
}

string debugVetorGeneral(vetor v, int n, string open, string middle, string close){
	string d[n];
	int len = strlen(open);
	for (int i = 0; i < n; i++){
		d[i] = debug(v[i]);
		len += strlen(d[i]);
		if (i < n-1)
			len += strlen(middle);
	}
	len += strlen(close);

	char str[len+1];
	strcpy(str, open) ;
	for (int i = 0; i < n; i++){
		strcat(str, d[i]);
		if (i < n-1)
			strcat(str, middle);
	}
	strcat(str, close);
	return criaString(str);
}

string debugVetor(vetor v, int n){
	return debugVetorGeneral(v, n, "[", " ", "]");
}

#include "Int.h"

void testeVetor(void){
	printf("Testando Vetor:\n");
	for (int n = 0; n < 10; n++){
		vetor v = malloc(sizeof(Int) * n);
		for (int i = 0; i < n; i++)
			v[i] = criaInt(i);
		printf("%s\n", debugVetor(v, n));
		ordenaVetor(v, n, comparaInverso);
		printf("%s\n", debugVetor(v, n));
		destroiTudoVetor(v, n);
	}
}

/* ENGLISH */

vetor copyVector(vector v, int n)
			{ return copiaVetor(v, n); }
void destroyVetor(vector v)
			{ destroiVetor(v); }
void destroyAllVector(vector v, int n)
			{ destroiTudoVetor(v, n); }
bool sortedVector(vector v, int n, comparator comp)
			{ return ordenadoVetor(v, n, comp); }
void sortVector(vector v, int n, comparator comp)
			{ return ordenaVetor(v, n, comp); }
bool homogeneousVector(vector v, int n)
			{ return homogeneoVetor(v, n); }
string debugVectorGeneral(vector v, int n, string open, string middle, string close)
			{ return debugVetorGeneral(v, n, open, middle, close); }
string debugVector(vector v, int n)
			{ return debugVetor(v, n); }
void testVector(void)
			{ testeVetor(); }
