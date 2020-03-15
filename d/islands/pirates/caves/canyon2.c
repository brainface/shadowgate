#include <std.h>
#include "../piratedefs.h"
inherit ROOM;

void create(){
::create();
   set_property("light",1);
   set_property("indoors",0);
   set_terrain(ROCKY);
   set_travel(FOOT_PATH);
   set_name("Inside the Canyon");
   set_short("Inside the Canyon");
   set_long("%^BOLD%^Deserted Canyon%^RESET%^\n"
"You are just past the entrance of the canyon.  You have left the heat of the desert behind.  It is cool and "
"dark here.  The canyon walls rise up on both sides, closing you in.  North you can see the canyon "
"entrance.  So far your trip to the canyon has been quiet.  But what's around that southeast bend?\n");
   set_smell("default","It smells dank and wet.");
   set_listen("default","You hear the sound of crumbling bits of rock and dirt falling.");

   set_items( ([
     ({"canyon walls","walls"}):"The granite canyon walls are cool to the touch, small streams of "
"%^BOLD%^%^CYAN%^water%^RESET%^ trickle from the canyon walls.",
     "water":"This is %^BOLD%^%^CYAN%^clear water%^RESET%^ running out of the rocks."
   ]));

   set_exits(([
     "southeast":CAVES+"canyon3",
     "north":CAVES+"canyon1"
   ]));
}
