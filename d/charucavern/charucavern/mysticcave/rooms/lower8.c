#include <std.h>
#include "../inherits/area_stuff.h"
inherit LOWER;

void create() 
{
    ::create();    
    set_exits((["southwest" : CRROOMS+"lower9"]));		    
}
