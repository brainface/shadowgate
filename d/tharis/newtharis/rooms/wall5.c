#include <std.h>
#include "../tharis.h"

inherit STORAGE"wall.c";

void create(){
   ::create();
   set_exits(([
      "east" : ROOMS"wall6",
      "west" : ROOMS"wall4",
   ]));

}