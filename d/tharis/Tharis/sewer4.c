//sewer4.c

#include <std.h>

inherit ROOM;

void create(){
	::create();
    set_terrain(BUILT_TUNNEL);
    set_travel(SLICK_FLOOR);
    set_property("no sticks", 1);
	set_property("light",0);
	set_property("indoors",1);
	set("short","The sewers under Tharis");
	set("long",
@OLI
	%^BOLD%^%^YELLOW%^The sewers under Tharis%^RESET%^
These sewers range under Tharis for miles. You need to find a place
to reach the surface. The dark walls are covered with slime mold from 
the many many years that sewage has flowed through here. The one thing
you do note is that there is remarkably little build up as if the
sewers have been cleaned frequently. You wonder what or who would get 
that task.
OLI
	);
	set_exits(([
		"north":"/d/tharis/Tharis/sewer3",
             "south":"/d/tharis/Tharis/sewer5",
		"east":"/d/tharis/Tharis/sewer9",
		"west":"/d/tharis/Tharis/sewer7"
		]));
	set_listen("default","Your boots splash through the the water."+
				"You also hear murmurs from the town above");
	set_smell("default","The smell of decay and refuse reach your nostrils");
	set_items(([
		"walls":"The walls are dark. They are covered with a surprisingly thin layer of slime."
	]));
}

void init(){
	::init();
	
        do_random_encounters(({"/d/shadow/mon/rat"}),30,11);
}

void reset(){
  int r;
  ::reset();
  if(!present("chest")){
    r = random(2);
    if(r==0) new("/d/hm_quest/chests/chest6")->move(TO);
    else new("/d/hm_quest/chests/chest21")->move(TO);
  }
}
