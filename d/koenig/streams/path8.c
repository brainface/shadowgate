//path8.c - Path from Koenig to Tabor.  Updated by Circe 11/28/03
#include <std.h>
#include "../koenig.h"
inherit PATH;

void create()
{
	::create();
	set_exits(([
	"northwest" : VILSTREAM"path7",
	"southeast" : VILSTREAM"path9",
	]));
}
