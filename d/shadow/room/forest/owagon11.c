
#include <std.h>
#include "../shadow.h"

inherit "/d/shadow/room/inherits/owagon.c";

void create(){
    ::create();
    set_exits(([
               "east":FORESTDIR+"owagon12",
               "west":FORESTDIR+"owagon10",
               ]));

}

