#include <std.h>
#include "../../newbie.h"

inherit FROAD;

void create()
{
   direction = "east";
   ::create();
   set_long(TO->query_long()+"%^RESET%^%^GREEN%^  The trail opens up to an %^RESET%^%^ORANGE%^overgrown and "+
   "rundown cemetary %^RESET%^%^GREEN%^directly south of here or continues westward.%^RESET%^");
   set_exits(([
    "west":FROAD+"6",
    "south":GRAVEYARD"cemetery1",
   ]));
}

void reset()
{
    ::reset();
    if(!present("sirith")) find_object_or_load(MON"sirith")->move(TO);
}
