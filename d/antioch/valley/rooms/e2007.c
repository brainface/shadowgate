#include <std.h>
#include "../valley.h"
inherit EDGE;

void create()
{
	::create();
	set_exits( ([
	"southeast" : ROOMS+"e1908",
	"east" : ROOMS+"v28",
	"west" : ROOMS+"e2006",
	]) );
	set_invis_exits(({"southeast","east","west"}));
}

