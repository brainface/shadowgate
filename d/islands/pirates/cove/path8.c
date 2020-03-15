#include <std.h>
#include "../piratedefs.h"
inherit CROOM;

void create(){ 
   set_monsters(({MON"citizen"}),({1}));
   ::create();
   set_property("light",2);
   set_property("indoors",0);
   set_terrain(VILLAGE);
   set_travel(DIRT_ROAD);
   set_name("Road through the village");
   set_short("Road through the village");
   set_long("%^BOLD%^Road through the village%^RESET%^\n"
"Little wooden shacks and rough buildings are scattered along either side of the road as you pass by here, "
"some in better repair than others.  Pathways run between the buildings, leading in several directions.  All "
"sorts of shady figures brush past you as they carry on their way.  The %^BLACK%^%^BOLD%^cobblestone road "
"%^RESET%^beneath your feet leads northeast, further into the village itself, and west to a small crossroads."
"  To the southeast is a small, grubby store.\n");
   set("night long","%^BOLD%^Road through the village%^RESET%^\n"
"Little wooden shacks and rough buildings are scattered along either side of the road as you pass by here, "
"some in better repair than others.  Pathways run between the buildings, leading in several directions into "
"%^BLUE%^darkness%^RESET%^.  All sorts of shady figures brush past you as they slip through the %^BLACK%^"
"%^BOLD%^night's shadows%^RESET%^.  The %^BLACK%^%^BOLD%^cobblestone road %^RESET%^beneath your feet leads "
"northeast, further into the village itself, and west to a small crossroads.  To the southeast is a small, "
"grubby store.\n");
   set_smell("default","The salty smell of the ocean fills the air.");
   set_listen("default","The murmur and bustle of the village surrounds you.");

   set_items(([
     ({"village","settlement","shacks","buildings"}):"All around you on each side, little wooden shacks and "
"rough buildings are scattered, with small paths running between them.",
     ({"road","cobblestones","cobblestone road"}):"Beneath your feet is a simple road of %^BLACK%^%^BOLD%^"
"cobblestones%^RESET%^, leading eastward into the village itself.",
     ({"store","grubby store","shop"}):"To the southeast is a single small, grubby store, stocking what "
"appears to be herbs and vials.  A sign over the doorway reads, %^WHITE%^%^BOLD%^'Loreman's Leachery'"
"%^RESET%^.",
    ]));

   set_exits(([
     "west":COVE"path7",
     "northeast":COVE"path9",
     "southeast":COVE"healer"
   ]));
}
