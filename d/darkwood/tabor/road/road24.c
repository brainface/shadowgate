#include <std.h>
#include "road.h"
inherit ROAD;

void create()
{
   ::create();
   set_exits(([
   "north" : PATH+"road23",
   "southeast" : PATH+"road25",
   ]));
}
