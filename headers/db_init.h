#ifndef DB_INIT_H
#define DB_INIT_H

#include <stdlib.h>
#include <Util.h>
#include <Str.h>

#define MAX_LINE_LEN 200
//private functions


//public functions
FILE	*open_dbfile(Str filepath);


#endif
