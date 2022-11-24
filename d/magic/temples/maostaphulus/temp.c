#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(STONE_BUILDING);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(1);
   set_temple("maostaphulus");
   set_name("Temple of Maostaphulus");
   set_short("%^BOLD%^%^ORANGE%^Shrine of the Ever Slumbering One.%^RESET%^");
   set_long("%^RESET%^%^ORANGE%^The stucco walls of the shrine are painted brown and a bit far from square. From the interior it resembles nothing so much as a cardboard box.%^RESET%^");
   set_smell("default","Someone should probably empty that box already.");
   set_listen("default","A low, comforting rumble fills the shrine..");
   set_exits(([
      "out": "/d/shadow/room/pass/pass2"
   ]));
}

void init(){
   ::init();
   add_action("read_charge","read");
}

int read_charge(string str){
   if(!str || str != "charge") return __Read_me(str);
   write(
@CHARGE
%^BOLD%^Maostaphulus charges his followers with this message:%^RESET%^%^ORANGE%^
Feed me.
Pay attention to me.
Go Away.
Take a Nap.
%^RESET%^
CHARGE
   );
   return 1;
}
