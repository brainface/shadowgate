#include <std.h>
#include "../marsh.h"

inherit FINH;

void create()
{
    ::create();
    set_exits(([
                "southwest": RPATH "f34",
      ]));
}
