//Octothorpe (1/8/12)
//Shadow, East Wall Street 1

#include <std.h>
#include "../defs.h"
inherit INH+"eastwall";

void create(){
   ::create();
   set_exits(([
      "northwest" : ROOMS"northcross",
      "southeast" : ROOMS"eastwall2",
   ]));
}