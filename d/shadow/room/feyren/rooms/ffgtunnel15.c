#include <std.h>
#include "../inherits/area_stuff.h"
inherit FFTTE;

void create() 
{
    ::create();
    set_long(TO->query_long()+" %^BOLD%^%^WHITE%^The tunnel comes to an "+
    "end. An opening leads out to the northwest.%^RESET%^");
    set_exits( ([ "northwest" : FFGTR"14"]) ); 
}
