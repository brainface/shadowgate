//forest231
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"forest2.c";

void create(){
::create();
set_exits(([
"west":INRMS+"forest25",
"southeast":INRMS+"forest230"
]));
}