//k_road05.c - Road to the new Koenig - coded by Circe 10/3/03
#include <std.h>
#include "../koenig.h"
inherit KROAD;

void create() {
   ::create();
   set_exits(([
      "southwest" : VILROOMS"k_road04",
      "east" : VILROOMS"k_road06"
   ]));
}