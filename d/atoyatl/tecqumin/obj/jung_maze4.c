#include <std.h>
#include "/realms/lujke/tecqumin/tecqumin.h"
#define WEMIC "/realms/lujke/wemic/rooms/"
inherit OBJ + "maze_builder3.c";

void create(){
  ::create();
  roompath = JUNG_ROOM4;
  start_x = 5; 
  start_y = 5;
  mazename = "j_maze";
  gridsize = 50;
  set_special_rooms( ({ }) );
  door_chance = 0;
  set_southroom(ROOMS + "step1.c");
  set_westroom(ROOMS + "j_link3a.c");
  set_eastroom(ROOMS + "j_link4.c");
}

void init(){
  ::init();
  add_action("make_maze", "create");
  add_action("clear_maze", "clear");
  add_action("place", "place");

}

int make_maze(string str){
  init_maze(start_x, start_y, mazename, gridsize);
  tell_object(TP,"Okay, you built a maze");
  return 1;
}