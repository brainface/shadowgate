#include <std.h>
#include "../../elfisland1.h"

inherit BCPATH;

void create() {
   ::create();
   set_exits( ([
      "northeast" : CPATH+"cpath02",
      "south" : CAMP+"croad06",
   ]) );
}
