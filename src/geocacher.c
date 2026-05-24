#include "geocacher.h"
#include <stdlib.h>
#include <Info.h>
#include <Sequencia.h>


struct Geocacher {
	Info	info;
	string	nick;
	// FAZER
	Sequencia	creations;

};


//private functions

static Geocacher	preencherGeocacher(Geocacher gc, Str str_gc, FILE *fp)
{
	return NULL;
}

static Geocacher *str_to_gc(FILE *fp, Str str_gc, Geocacher *geocachers)
{
	if (!strncmp(str_gc, DB_DELIMITER, 6))
		return NULL;
	Geocacher *new_gc = preencherGeocacher(criaGeocacher(), str_gc, fp);
	return new_gc;
}


//public functions

Geocacher criaGeocacher()
{
	Geocacher gc;

	gc = malloc(sizeof(struct Geocacher));
	if (!gc)
		semMemoria();
	return gc;
}
