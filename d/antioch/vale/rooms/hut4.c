#include <std.h>
#include "../vale.h"
inherit HUT_INH;

void create()
{
   ::create();
   set_exits(([
   "west" : ROOMS+"c20",
   ]));
   set_door("door",ROOMS+"c20","west",0);
}

void reset()
{
   ::reset();
   if(!present("druid")) {
      switch(random(2)) {
         case 0:
            new(MONS+"clone_druid")->move(TO);
            break;
         case 1:
            new(MONS+"clone_druid")->move(TO);
            break;
      }
   }
}
