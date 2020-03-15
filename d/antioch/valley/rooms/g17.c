#include <std.h>
#include "../valley.h"
inherit GRASS;

void create()
{
	::create();
	set_long(::query_long()+"%^GREEN%^There is a large tree to the north.\n"
	);
	set("night long",query("night long")+"%^GREEN%^There is a large tree to the north.\n"
	);
	set_exits( ([
	"north" : ROOMS+"dryad5",
	"south" : ROOMS+"g6",
	"west" : ROOMS+"g18",
	"east" : ROOMS+"g16",
	]) );
}

