#include "cache.h"
#include "Vetor.h"
#include "Dicionario.h"
#include "Str.h"

struct Cache {
	Info info;
	string code;		// "GCK1JY"
	string name;		// "Atlantis [Pico]"
	string state;		// "ARQUIPELAGO DOS ACORES"
	string owner;		// "pcardoso adopted by JPOliveira"
	double latitude;	// 38.468917
	double longitude;	// -28.3994
	string kind;		// "TRADITIONAL"  opcoes: "MULTI", "PUZZLE", etc.
	string size;		// "REGULAR"  opcoes: "MICRO", "SMALL", "LARGE", etc.
	double difficulty;	// 2.0  opcoes: 1.0, 1.5, 2.0, ..., 4.5, 5.0
	double terrain;		// 4.5  opcoes: 1.0, 1.5, 2.0, ..., 4.5, 5.0
	string status;		// "AVAILABLE" opcoes: "AVAILABLE", "DISABLED"
	string hiddenDate;	// "2004/07/20"
	int founds;		// 552
	int notFounds;		// 37
	int favourites;		// 145
	int altitude;		// 2286  (-9999999 significa "altitude desconhecida")
};

//private functions

static void preencherCache(Cache cache, FILE *fp)
{
	Str	line;
	int n = 0;
	Str		copy;

	while (n < 16)
	{
		fgets(line, BUFFER_SIZE, fp);
		strcpy(line, copy);
		switch (n)
		{
			case 0: cache->code = copy; break;
			case 1: cache->name = copy; break;
			case 2: cache->state = copy; break;
			case 3: cache->owner = copy; break;
			case 4: cache->latitude = atol(copy); break;
			case 5: cache->longitude = atol(copy); break;
			case 6: cache->kind = copy; break;
			case 7: cache->size = copy; break;
			case 8: cache->difficulty = atol(copy); break;
			case 9: cache->terrain = atol(copy); break;
			case 10: cache->status = copy; break;
			case 11: cache->hiddenDate = copy; break;
			case 12: cache->founds = atoi(copy); break;
			case 13: cache->notFounds = atoi(copy); break;
			case 14: cache->favourites= atoi(copy); break;
			case 15: cache->altitude = atoi(copy); break;
			default: printf("erro no preenchimento da cache\n");
		}
		n++;
	}
	return;
}

	//re-factor
static Cache *str_to_cache(FILE *fp)
{
	//to do: deixo com 200 ou ha forma de ser dinamico?
	vector		line;
	Dicionario	geocachers;
	vetor		caches;
	Cache		new_cache;

	line = criaVetor();
	if (!line)
		return NULL;
	do
	{
		fgets(line, BUFFER_SIZE, fp);
		if (!line)
			return geocachers;
		preencherCache(criaCache(), fp);
		acrescentaSequencia(caches, new_cache);
	}
	while (line != NULL);
}

//public functions

Cache criaCache()
{
	Cache	cache;

	cache = malloc(sizeof(struct Cache));
	if (!cache)
		semMemoria();
	return cache;
}
