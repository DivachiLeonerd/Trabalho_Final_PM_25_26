#ifndef COORDINATOR_H
#define COORDINATOR_H

#include <stdlib.h>
#include "cache.h"
#include "geocacher.h"
#include "Str.h"
#include "db_init.h"

struct Coordinator;
typedef struct Coordinator *Coordinator;


//public functions
Coordinator create_coordinator(Str filepath);

#endif
