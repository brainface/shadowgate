#include "../../undead.h"

inherit INH+"swamp_one.c";

void create() 
{
   ::create();

    set_exits(([
        "southeast" :SWMP+"swamp37",
        "south"     :SWMP+"swamp36"
             ]));

}
