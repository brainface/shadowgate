#include <std.h>
#include "../inherits/area_stuff.h"
inherit INNER;

void create() 
{
    ::create();
    set_long(TO->query_long()+"%^BOLD%^%^WHITE%^ Openings in the eastern and western walls lead "+
    "to other sections of the cavern.%^RESET%^");
    set_exits((["east" : CRROOMS+"inner18", "west" : CRROOMS+"inner6"]));		

}
