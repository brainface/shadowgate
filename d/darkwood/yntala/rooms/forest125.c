//forest125
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest1.c";

void create(){
::create();
set_exits(([
"northwest":INRMS+"forest124",
"east":INRMS+"forest126"
]));
}