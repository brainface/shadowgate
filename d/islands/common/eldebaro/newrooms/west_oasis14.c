#include <std.h>
#include "../area_stuff.h"

inherit WESTOASIS;

void create()
{
    ::create();
    set_exits(([
        "south" : ELROOMSW+"15",
        //"east" : ELROOMSW+"13",
        "north" : ELROOMSW+"13",
        "west" : ELROOMSW+"11",
    ]));
}
