#include <std.h>
#include "/d/deku/inherits/forest.h"
inherit FTRAIL;

void create() {
    ::create();

    set_exits(([
       "west" : F_ROOMS"36-9",
       "east" : F_ROOMS"34-9",
       "north" : F_ROOMS"35-10",
       "south" : F_ROOMS"35-8",
       "southeast" : F_ROOMS"34-8",
       "southwest" : F_ROOMS"36-8",
       "northeast" : F_ROOMS"34-10",
       "northwest" : F_ROOMS"36-10",
    ] ));
}
