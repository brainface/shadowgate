//hid26
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"north":INRMS+"hid25",
"southeast":INRMS+"hid27",
]));
}