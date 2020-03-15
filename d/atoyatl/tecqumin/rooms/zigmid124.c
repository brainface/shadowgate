#include <std.h>
#include <terrain.h>
#include "../tecqumin.h"
inherit ZIG_MID;

void create() {
  ::create();
  set_exits( ([ "west" : ROOMS + "zigmid123" ,
	          "east" : ROOMS + "step3"]) );

  set_climb_exits(([
       "climb":({ROOMS + "zigmid217",5,6,20}),
       "descend":({ROOMS + "ziglow232",5,6,20}),
  ]));
}
