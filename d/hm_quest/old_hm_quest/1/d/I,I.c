#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze";

create()
{
  ::create();
  set_exits( ([
                "south" : MAZEDIR+"1/d/I,II",
                "east"  : MAZEDIR+"1/d/II,I"
           ]) );
}
