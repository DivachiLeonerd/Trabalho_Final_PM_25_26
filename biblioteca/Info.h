/*
 * Info.h
 */

#ifndef INFO_H
#define INFO_H

#include "Util.h"

/***********************************************
	TAD Info - Blocos informativos para objetos

Este TAD oferece algumas definicoes que
suportam a definicao de tipos de objetos
usaveis em colecoes genericas.

Esses objetos tem de ter um campo de tipo Info
colocado na PRIMEIRA POSICAO da sua struct.

Uma colecao generica guarda objetos de tipo
indeterminado, e precisa de conseguir
aplicar aos seus objetos algumas das seis
operacoes seguintes:
	tipo,
	destroi,
	destroiTudo,
	compara,
	dispersao,
	debug.
***********************************************/

/*------------------------------------------*/
/* Tipos publicos */

typedef struct Info *Info;
typedef void *obj;	// tipo generico dos objetos

typedef void *comparador; // tipo genérico dos comparadores
typedef comparador comparator;
typedef int (*comparadorObj)(obj, obj);

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaInfo - Cria um bloco de informacao para um objeto.
Parametros:
	tipo - tipo pretendido para o objeto (e' uma string)
	destroi - funcao de destruicao
	destroiTudo - funcao de destruicao completa (para colecoes)
	compara - funcao de comparacao
	dispersao - funcao de dispersao
	debug - gerador de representacao textual para debug
Retorno: se ja' existe um blobo informativo para o tipo
	indicado, devolve o bloco informativo existente.
	Caso contrário, cria e retorna um bloco informativo novo.
Precondicao: tipo != NULL && destroi != NULL
	(os restantes argumentos podem ser NULL, para indicar ausencia)
***********************************************/
Info criaInfo(string tipo, void *destroi, void *destroiTudo,
		void *compara, void *dispersao, void *debug);
Info createInfo(string type, void *destroy, void *destroyAll,
		void *compare, void *hash, void *debug);

/***********************************************
registaInfo - Simplesmente, outro nome para a funcao criaInfo.
***********************************************/
Info registaInfo(string tipo, void *destroi, void *destroiTudo,
		void *compara, void *dispersao, void *debug);
Info registerInfo(string type, void *destroy, void *destroyAll,
		void *compare, void *hash, void *debug);

/***********************************************
mostraInfos - Mostra os tipo que estao registados.
Parametros: nada
Retorno: nada
Precondicao: nada
***********************************************/
void mostraInfos(void);
void showInfos(void);

/***********************************************
mesmoTipo - Testa se dois objetos sao do mesmo tipo.
Parametros: ob1, ob2 - objetos para comparar o seu tipo
Retorno: true - se mesmo tipo; false - caso contrario
Precondicao: ob1 != NULL && ob2 != NULL
***********************************************/
bool mesmoTipo(obj ob1, obj ob2);
bool sameType(obj ob1, obj ob2);

/***********************************************
tipo - Obtem o tipo dum objeto.
Parametros: ob - objeto
Retorno: o tipo e' uma string
Precondicao: ob != NULL
***********************************************/
string tipo(obj ob);
string type(obj ob);

/***********************************************
destroi - Destroi um objeto generico.
Parametros: ob - objeto generico
Retorno: nada
Precondicao: ob != NULL
***********************************************/
void destroi(obj ob);
void destroy(obj ob);

/***********************************************
destroiTudo - Destroi um objeto generico completamente,
	que sera' provavelmente uma colecao.
Parametros: ob - objeto generico
Retorno: nada
Precondicao: ob != NULL
***********************************************/
void destroiTudo(obj ob);
void destroyAll(obj ob);

/***********************************************
compara - Compara dois objetos genericos.
Parametros: ob1, ob2 - objetos genericos
Retorno: 0 se ob1 = ob2; -1 se ob1 < ob2; 1 se ob1 > ob2
Precondicao: ob1 != NULL && ob2 != NULL
***********************************************/
int compara(obj ob1, obj ob2);
int compare(obj ob1, obj ob2);

/***********************************************
compara - Compara dois objetos genericos pela ordem inversa.
Parametros: ob1, ob2 - objetos genericos
Retorno: 0 se ob1 = ob2; 1 se ob1 < ob2; -1 se ob1 > ob2
Precondicao: ob1 != NULL && ob2 != NULL
***********************************************/
int comparaInverso(obj ob1, obj ob2);
int compareReverse(obj ob1, obj ob2);

/***********************************************
dispersao - Funcao de dispersao.
Parametros:
	ob - objeto generico
	dim - dimensao da tabela
Retorno: valor de dispersao
Precondicao: ob != NULL && dim > 0
***********************************************/
int dispersao(obj ob, int dim);
int hash(obj ob, int dim);

/***********************************************
debug - Converte ob em string, para mostrar em situacoes de debug.
Parametros: ob - objeto generico
Retorno: a string criada
Precondicao: ob != NULL
***********************************************/
string debug(obj ob);

/***********************************************
mostraObj - Mostra no ecra dados sobre o ob
Parametros: ob - objeto generico
Retorno: nada
Precondicao: ob != NULL
***********************************************/
void mostraObj(obj ob);
void showObj(obj ob);

#endif /* INFO_H */
