#ifndef CACHE_H
#define CACHE_H

#include <Sequencia.h>
#include <Dicionario.h>
//Macros
#define MAX_CACHES_PER_CACHER 100

//structs
typedef struct Cache * Cache;

//public functions

Cache criaCache(void);
void destroiCache(Cache cache);
void destroiTudoCache(Cache cache);

#endif
