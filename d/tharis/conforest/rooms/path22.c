#include <std.h>
#include "../defs.h"
inherit INC+"pathwe";

void create()
{
  ::create();
  set_exits(
    ([
    "east" : ROOMS+"path23",
    "west" : ROOMS+"path21"
    ]) );
}