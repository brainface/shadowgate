#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        "north" : ELROOMSD+"151",
        "east" : ELROOMSD+"137",
        //"south" : ELROOMSD+"22",
        "west" : ELROOMSD+"135",
        
    ]));
}
