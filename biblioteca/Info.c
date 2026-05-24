/*
 * Info.c
 */

#include "Info.h"

/* Entender este ficheiro nao faz parte dos objetivos de AED.
   Mas se voce tiver curiosidade de o estudar, isso e' positivo. */

/*------------------------------------------*/
/* Tipo privado */

struct Info {
	string tipo;
	void (*destroi)(obj ob);
	void (*destroiTudo)(obj ob);
	int (*compara)(obj ob1, obj ob2);
	int (*dispersao)(obj ob, int dim);
	string (*debug)(obj ob);
};

/*------------------------------------------*/
/* Tabela de infos privada */

#define FATOR_DE_CAPACIDADE	1
#define INTERVALO	('Z' - 'A' + 1)
#define CAPACIDADE	(INTERVALO * FATOR_DE_CAPACIDADE)

static Info tabelaInfos[CAPACIDADE] = {NULL}; // inicializa tudo a NULL

static int dispersaoInfo(string tipo){
	char c = tipo[0];
	if (!isupper(c))
		erroFatal("O tipo dum objeto tem de comecar por maiuscula");
	return (c - 'A') * FATOR_DE_CAPACIDADE;
}

static int slotInfo(string tipo){ // usa dispersao fechada
	int d = dispersaoInfo(tipo);
	int cap = CAPACIDADE;
	for (int i = d; i < cap; i++){
		if (tabelaInfos[i] == NULL
		|| strcmp(tabelaInfos[i]->tipo, tipo) == 0)
			return i;
	}
	for (int i = 0; i < d; i++){
		if (tabelaInfos[i] == NULL
		|| strcmp(tabelaInfos[i]->tipo, tipo) == 0)
			return i;
	}
	erroFatal("A tabela de Infos ficou cheia");
	return -1; // para evitar warning
}

static Info procuraInfo(string tipo){
	return tabelaInfos[slotInfo(tipo)];
}

static void acrescentaInfo(Info info){
	tabelaInfos[slotInfo(info->tipo)] = info;
}

static bool validaInfo(Info info){ // verifica se info existe na tabela
	int cap = CAPACIDADE;   // precisa de otimização
	for (int i = 0; i < cap; i++)
		if (tabelaInfos[i] == info)
			return true;
	return false;
}

static void mostraInfosPriv(void){
	int cap = CAPACIDADE;   // precisa de otimização
	int n = 0;
	mensagem("\n*** INFOS INSTALADOS ***");
	for (int i = 0; i < cap; i++)
		if (tabelaInfos[i] != NULL){
			mensagem(tabelaInfos[i]->tipo);
			n++;
		}
	if (n == 0)
		mensagem("nenhum");
	mensagem("*****************\n");
}


/*------------------------------------------*/
/* Funcoes privadas */

static int compara0(obj ob1, obj ob2){
	(void)ob2;
	aviso("Chamou a funcao indefinida 'compara%s'", tipo(ob1));
	return 0;
}

static int dispersao0(obj ob, int dim){
	(void)dim;
	aviso("Chamou a funcao indefinida 'dispersao%s'", tipo(ob));
	return 0;
}

static string debug0(obj ob){
	aviso("Chamou a funcao indefinida 'debug%s'", tipo(ob));
	return "";
}

static void preencheTipo(Info info, string tipo){
	if (tipo == NULL || strcmp(tipo, "") == 0)
		erroFatal("Na criacao dum bloco informativo, e' "
			"obrigatorio indicar um tipo");
	info->tipo = criaString(tipo);
}

static void preencheDestroi(Info info, void (*destroi)(obj ob)){
	if (destroi == NULL)
		erroFatal("Na criacao dum bloco informativo, e' "
			"obrigatorio indicar uma funcao 'destroi'");
	info->destroi = destroi;
}

static void preencheDestroiTudo(Info info, void (*destroiTudo)(obj ob)){
	if (destroiTudo == NULL)
		info->destroiTudo = info->destroi;
	else
		info->destroiTudo = destroiTudo;
}

static void preencheCompara(Info info, int (*compara)(obj ob1, obj ob2)){
	if (compara == NULL)
		info->compara = compara0;
	else
		info->compara = compara;
}

static void preencheDispersao(Info info, int (*dispersao)(obj ob, int dim)){
	if (dispersao == NULL)
		info->dispersao = dispersao0;
	else
		info->dispersao = dispersao;
}

static void preencheDebug(Info info, string (*debug)(obj ob)){
	if (debug == NULL)
		info->debug = debug0;
	else
		info->debug = debug;
}

static Info info(obj ob, string where){
	if (ob == NULL)
		erroFatal("NULL não é um objeto válido");
	Info i = *((Info *)ob);
	if (validaInfo(i)){
#if 0
		mensagem("%s(<%s-%p>)", where, i->tipo, ob);
#endif
		return i;
	}
	else {
		erroFatal("%s(<###-%p>) falta bloco informativo no inicio", where, ob);
		return NULL;  // evita warning
	}
}


/*------------------------------------------*/
/* Funcoes publicas */

Info criaInfo(string tipo, void *destroi, void *destroiTudo,
			void *compara, void *dispersao, void *debug){
	Info info = procuraInfo(tipo);
	if (info != NULL)	// ja' existe
		return info;
	info = malloc(sizeof(struct Info));	// cria novo
	if (info == NULL) semMemoria();
	preencheTipo(info, tipo);
	preencheDestroi(info, destroi);
	preencheDestroiTudo(info, destroiTudo);
	preencheCompara(info, compara);
	preencheDispersao(info, dispersao);
	preencheDebug(info, debug);
	acrescentaInfo(info);	// instala novo
	return info;
}

Info registaInfo(string tipo, void *destroi, void *destroiTudo,
			void *compara, void *dispersao, void *debug){
	return criaInfo( tipo, destroi, destroiTudo, compara, dispersao, debug);
}

void mostraInfos(void){
	mostraInfosPriv();
}

bool mesmoTipo(obj ob1, obj ob2){
	return strcmp(tipo(ob1), tipo(ob2)) == 0;
}

string tipo(obj ob){
	return info(ob, "tipo")->tipo;
}

void destroi(obj ob){
	info(ob, "destroi")->destroi(ob);
}

void destroiTudo(obj ob){
	info(ob, "destroiTudo")->destroiTudo(ob);
}

int compara(obj ob1, obj ob2){
	return info(ob1, "compara")->compara(ob1, ob2);
}

int comparaInverso(obj ob1, obj ob2){
	return compara(ob2, ob1);
}

int dispersao(obj ob, int dim){
	return info(ob, "dispersao")->dispersao(ob, dim);
}

string debug(obj ob){
	return info(ob, "debug")->debug(ob);
}

void mostraObj(obj ob){
	printf("<%s-%p>\n", tipo(ob), ob);
}

/* ENGLISH */

Info createInfo(string type, void *destroy, void *destroyAll,
				void *compare, void *hash, void *debug)
			{ return criaInfo(type, destroy, destroyAll, compare, hash, debug); }
Info registerInfo(string tipo, void *destroi, void *destroiTudo,
				void *compara, void *dispersao, void *debug)
			{ return registaInfo( tipo, destroi, destroiTudo, compara, dispersao, debug); }
void showInfos(void)
			{ mostraInfos(); }
bool sameType(obj ob1, obj ob2)
			{ return mesmoTipo(ob1, ob2); }
string type(obj ob)
			{ return tipo(ob); }
void destroy(obj ob)
			{ destroi(ob); }
void destroyAll(obj ob)
			{ destroiTudo(ob); }
int compare(obj ob1, obj ob2)
			{ return compara(ob1, ob2); }
int compareReverse(obj ob1, obj ob2)
			{ return comparaInverso(ob1, ob2); }
int hash(obj ob, int dim)
			{ return dispersao(ob, dim); }
// string debug(obj ob)
//			{ return debug(ob); }
void showObj(obj ob)
			{ mostraObj(ob); }
