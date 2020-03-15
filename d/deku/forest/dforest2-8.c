#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit SHORETRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"3-8",
       "north" : F_ROOMS"2-9",
       "south" : F_ROOMS"2-7",
       "southwest" : F_ROOMS"3-7",
       "northwest" : F_ROOMS"3-9",
    ] ));
}
