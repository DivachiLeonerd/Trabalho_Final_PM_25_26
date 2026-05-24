/*
 * Str.h
 */

#ifndef STR_H
#define STR_H

#include "Util.h"

/***********************************************
	TAD String - Objetos que representam str
***********************************************/

/*------------------------------------------*/
/* Tipo publico */

typedef struct Str *Str;

/*------------------------------------------*/
/* Prototipos das funcoes publicas */

/***********************************************
criaStr - Cria um objeto que representa uma string.
Parametros: valor - a string a representar
Retorno: o objeto criado
Precondicao: valor != NULL
***********************************************/
Str criaStr(string valor);
Str createStr(string value);

/***********************************************
destroiStr - Elimina um objeto de tipo Str.
Parametros: str - objeto str
Retorno: nada
Precondicao: str != NULL
***********************************************/
void destroiStr(Str str);
void destroyStr(Str str);

/***********************************************
comparaStr - Compara duas strs.
Parametros: str1, str2 - objetos str
Retorno: negativo, zero ou positivo
Precondicao: str1 != NULL && str2 != NULL
***********************************************/
int comparaStr(Str str1, Str str2);
int compareStr(Str str1, Str str2);

/***********************************************
dispersaoStr - Funcao de dispersao das strs.
Parametros: str - objeto str; dim - dimensao da tabela
Retorno: valor de dispersao
Precondicao: str != NULL && dim > 0
***********************************************/
int dispersaoStr(Str str, int dim);
int hashStr(Str str, int dim);

/***********************************************
debugStr - Converte em string, para mostrar em situacoes de debug.
Parametros: str - objeto str
Retorno: a string criada
Precondicao: str != NULL
***********************************************/
string debugStr(Str str);
// string debugStr(Str str);

/***********************************************
valorStr - Extrai a string guardada num objeto str.
Parametros: str - objeto str
Retorno: a string guardada no objeto
Precondicao: str != NULL
**********************************************/
string valorStr(Str str);
string valueStr(Str str);

/***********************************************
testeStr - Alguns testes simples.
***********************************************/
void testeStr(void);
void testStr(void);

#endif /* STR_H */
