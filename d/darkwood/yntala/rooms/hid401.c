//hid40
#include <std.h>;
#include "../yntala.h"
inherit IHRMS+"hidin.c";

void create(){
::create();
set_exits(([
"west":INRMS+"hid41",
"northeast":INRMS+"hid21",
]));
}