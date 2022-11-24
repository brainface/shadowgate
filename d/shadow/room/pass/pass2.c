#include <std.h>
#include "../pass.h"
inherit "/d/shadow/room/inherits/pass_parent";

void create(){
    ::create();
    set_long(desc_start + desc_road_easy + desc_plain_fade + desc_trees);

    set_exits(([
	"west" : "/d/magic/temples/maostaphulus/temp",
	"east" : "/d/magic/temples/manyheadedmongrel/temp",	
	"south" : PASSDIR+"pass1",
	"north" : PASSDIR+"passn11"
   	]));
}
