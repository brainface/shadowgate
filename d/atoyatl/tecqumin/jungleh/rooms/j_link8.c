#include <std.h>
#include <terrain.h>
#include "../../tecqumin.h"
inherit J_MAZE;

void create() {
  ::create();
  base_exits = ([ "southwest": JUNG_ROOM1  + "j_link8a" ]);
  set_basic_exits();
  r_path = JUNG_ROOM8;
}
int is_map_transition(){
  return 1;
}


void on_enter(){
  set_basic_exits();
  update_exits();
}
