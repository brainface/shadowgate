//hallway
#include <std.h>
#include "elf.h"
inherit INH"hall";


void create(){
    ::create();

   set_exits(([ "west": ROOMS"inn",  
   "north": ROOMS"ident",
   "east": ROOMS"library",   ]));
   set_door("door",ROOMS"ident","north","key");
   set_locked("door",0);
   set_door_description("door","This door is made of metal and quartz.");

}
