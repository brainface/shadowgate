#include <std.h>

inherit ROOM;

void create() {
    ::create();
    set_property("light", 4);
    set_property("night light", 1);
    set_property("no castle", 1);
    set("short", "Sun Alley near Centre Path");
    set("long",
	"This alley is a bright alley on the north end of the "
	"village.  It intersects Centre Path west of here.  "
	"There is a small thatch house south.");
    set_items(
	(["alley" : "It is bright and cheerful, not like that alley on "
	    "the south end.",
	  "path" : "The main north-south road of Praxis.",
	  "intersection" : "Sun alley meets Centre Path there.",
	  "house" : "It's a small thatch house, nothing special."]) );
    set_exits( 
	      (["east" : "/d/standard/sun2",
		"west" : "/d/standard/n_centre2",
		"south"	 : "/d/standard/house"]) );
}

