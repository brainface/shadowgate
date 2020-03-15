#include <std.h>
#include "/d/islands/dinosaur/lake/lake.h"

inherit MAIN;

void create(){
    ::create();
    set_short("Underwater Cave");
    set_long(
      "You are in a great underwater cavern.  All around you there is nothing but water and more water."
    );
    set_light(-1);
    set_property("indoors", 1);
    set_items( ([
      "water" : "water water everywhere AND YOU'RE GONNA DROWN IN IT!",
    ]) );
    set_exits( ([
      "down" : CAVEONE "cave54-3.c",
      "east" : CAVEONE "cave43-3.c",
      "south" : CAVEONE "cave44-3.c",
      "north" : CAVEONE "cave44-4.c",
    ]) );
}
