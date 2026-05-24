#include "coordinator.h"

struct Coordinator
{
	Info		info;
	Sequencia	caches;
	Dicionario	geocachers;
	Sequencia	logs;
};



//private functions
static	Sequencia get_caches(FILE *fp)
{
	Sequencia	caches;

	return caches;
}

static	Dicionario get_geocachers()
{

}

static	Sequencia get_logs()
{

}

//public functions
Coordinator create_coordinator(Str filepath)
{
	Coordinator c;
	FILE	*fp;

	c = (Coordinator)malloc(sizeof(struct Coordinator));
	if (!c)
		semMemoria();
	fp = open_dbfile(filepath);
	c->caches = get_caches(fp);
	c->geocachers = get_geocachers(fp);
	c->logs = get_logs(fp);
	return c;
}

int interpreter(Coordinator c)
{
	return 0;
}
