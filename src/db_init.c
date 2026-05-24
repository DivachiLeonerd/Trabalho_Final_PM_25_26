#include "db_init.h"

//private functions





//public functions
FILE *open_dbfile(Str filepath)
{
	FILE	*fp = NULL;

	fp = fopen(filepath, 'r');
	return fp;
}

char	*get_next_line(Str filepath, FILE *fp)
{
	Str	next_line;

	if (!fp)
		return NULL;
	fgets(next_line, BUFFER_SIZE, fp);
	return next_line;
};
