//Octothorpe (3/26/10)
//Attaya Jungle Path 19
//Original by Thundercracker

#include <std.h>
#include "../defs.h"

inherit JUNGPATH;

void create(){
   ::create();
   set_exits(([
     "west":JGL"jun18",
     "east":JGL"jun20",
   ]));	 
}