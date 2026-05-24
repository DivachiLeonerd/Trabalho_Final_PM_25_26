/*
 * Str.c
 */

#include "Str.h"
#include "Info.h"

/*------------------------------------------*/
/* Tipo privado */

struct Str {
	Info info;
	string valor;
};

/*------------------------------------------*/
/* Funcoes publicas */

Str criaStr(string valor){
	Str str = malloc(sizeof(struct Str));
	if (str == NULL) semMemoria();
	str->info = criaInfo("Str", destroiStr, destroiStr,
				comparaStr, dispersaoStr, debugStr);
	str->valor = criaString(valor);
	return str;
}

void destroiStr(Str str){
	destroiString(str->valor);
	free(str);
}

int comparaStr(Str str1, Str str2){
	string s1 = valorStr(str1);
	string s2 = valorStr(str2);
	return strcmp(s1, s2);
}

/* djb2 function by dan bernstein */
int dispersaoStr(Str str, int dim){
	string s = valorStr(str);
	unsigned long hash = 5381;
	int c;
	while ((c = (unsigned int)*s++) != '\0')
		hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
	return hash % dim;
}

string debugStr(Str str){
	string s = valorStr(str);
	char s2[strlen(s) + 2 + 1];
	sprintf(s2, "\"%s\"", s);
	return criaString(s2);
}

string valorStr(Str str){
	return str->valor;
}

void testeStr(void){
	printf("Testando Str:\n");

	Str str0 = criaStr("05");
	for (int i = 0 ; i < 10 ; i++){
		char a[100];
		sprintf(a, "%02d", i);
		Str str = criaStr(a);
		printf("(%s,%d,%d)\n",
			debugStr(str),
			comparaStr(str, str0),
			dispersaoStr(str, 100)
		);
		destroiStr(str);
	}
	destroiStr(str0);
	printf("\n");
}

/*
Testando Str:
(00,-5,41)
(01,-4,42)
(02,-3,43)
(03,-2,44)
(04,-1,45)
(05,0,46)
(06,1,47)
(07,2,48)
(08,3,49)
(09,4,50)
*/

/* ENGLISH */

Str createStr(string value)
			{ return criaStr(value); }
void destroyStr(Str str)
			{ destroiStr(str); }
int compareStr(Str str1, Str str2)
			{ return comparaStr(str1, str2); }
int hashStr(Str str, int dim)
			{ return dispersaoStr(str, dim); }
// string debugStr(Str str)
//			{ return debugStr(str); }
string valueStr(Str str)
			{ return valorStr(str); }
void testStr(void)
			{ testeStr(); }
