#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  new_disc(4);
  set_exits( ([
 	        "south" : MAZEDIR+"4/d/II,II",
                "east"  : MAZEDIR+"4/d/III,I",
                "west"  : MAZEDIR+"4/d/I,I"
           ]) );
}
