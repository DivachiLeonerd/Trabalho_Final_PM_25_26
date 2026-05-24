#include "cache.h"
#include "geocacher.h"
#include <stdlib.h>
#include <coordinator.h>
#include <assert.h>

static void assert_int(int real, int expected)
{
	assert(real == expected);
}
static	void assert_NotEquals_int(int real, int expected)
{
	assert(real == expected);
}

static void assert_nstring(string real, string expected, int n)
{
	assert(!strncmp(real, expected, n));
}

static void assert_NotEquals_nstring(string real, string expected, int n)
{
	assert(strncmp(real, expected, n));
}
