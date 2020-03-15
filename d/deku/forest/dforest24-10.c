#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"25-10",
       "east" : F_ROOMS"23-10",
       "north" : F_ROOMS"24-11",
       "south" : F_ROOMS"24-9",
       "southeast" : F_ROOMS"23-9",
       "southwest" : F_ROOMS"25-9",
       "northeast" : F_ROOMS"23-11",
       "northwest" : F_ROOMS"25-11",
    ] ));
}
