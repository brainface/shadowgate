// Inside Market Square, Azha
// Thorn@ShadowGate
// 4/8/95
// Town of Azha

#include <std.h>
#include "/d/azha/azha.h"
#include "/d/tsarven/include/southern.h"

inherit ROOM;

void create() {
  room::create();
   set_terrain(CITY);
   set_travel(PAVED_ROAD);
	set_light(2);
	set_indoors(0);  
	set_short("Inside Market Square, Azha");
  set_long(
@AZHA
%^BOLD%^Inside Market Square%^RESET%^
  All around you are people haggling, trading and just admiring some 
of the things in the colorful booths sprawed all around you. 
Merchants are shouting to you and whoever else will listen, about the
quality or the exquisiteness of their particular works.  Its a
miracle that you can hear yourself think in this strange place.
  The market wall prevents movement to the south.
AZHA
    );
	set_exits(([
	"north" : "/d/azha/town/market5",     
	"east" : "/d/azha/town/market3",
	"west" : "/d/azha/town/market1",
	"northeast" : "/d/azha/town/market6",
	"northwest" : "/d/azha/town/market4",
  ] ));     
	set_smell("default","The smells here are so strong and varied that they overwhelm you.");
	set_items(([
		"booths" : "The booths are of many shapes: tents, wooden stalls, or sometimes just piles of goods, marked by a sign.\n",
	] ));
}

void init(){
      ::init();
      if(!present("ginaratha",TO))
         find_object_or_load("/d/npc/ginaratha")->move(TO);
}
