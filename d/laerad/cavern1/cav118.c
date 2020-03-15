//Coded by Bane//
#include <std.h>
inherit "/d/laerad/cavern1/special/croom_cavern.c";

void create() {
    set_monsters( ({"/d/laerad/mon/bulette", "/d/laerad/mon/fungus" }), ({1,1}) );
    ::create();
    set_repop(60);
    set_short("Laerad caverns");
    set_long(
	"You are standing in some underground slave pen.  Wooden stockade "+
	"fencing winds its way around the cave leaving only a few exits into "+
	"other pens.  The ceiling is low, only about 9 feet from the ground.  "+
	"A small stream of water is running along one of the walls.  Atop some "+
	"of the fence poles are small globes of light, keeping the area fully "+
	"illuminated."
    );
    set_property("indoors",1);
    set_property("light",2);
    set_smell("default","The air is surprisingly clean and refreshing.");
    set_listen("default","You can hear the trickling of the stream.");
    set_exits( ([
	"west":"/d/laerad/cavern1/cav120",
	"south":"/d/laerad/cavern1/cav116",
	"east":"/d/laerad/cavern1/cav119"
    ]) );
}
void reset(){
    ::reset();
/* changed to use CROOM
    if(!present("bulette")){
	new("/d/laerad/mon/bulette")->move(this_object());
    }
    if(!present("fungus")){
	new("/d/laerad/mon/fungus")->move(this_object());
    }
*/
}
