#include <std.h>
#include "../area_stuff.h"

inherit ELINH;

void create()
{
    ::create();
    set_exits(([
        
        //"north" : ELROOMSD+"150",
        "east" : ELROOMSD+"173",
        //"south" : ELROOMSD+"152",
        "west" : ELROOMSD+"171",
        
    ]));
}
