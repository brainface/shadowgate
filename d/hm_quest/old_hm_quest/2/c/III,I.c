#include "/d/hm_quest/maze.h"

inherit "/d/hm_quest/maze.c";

create()
{
  ::create();
  new_disc(2);
  set_exits( ([
                "east"  : MAZEDIR+"2/c/IV,I",
                "west"  : MAZEDIR+"2/c/II,I"
           ]) );
}

