/*Removing Xeryl and obsidian gem from the game due to its unoriginal copypasta - Octothorpe 1/26/17*/

#include <std.h>

#include "/d/undead/undead.h"
inherit ROOM;

object dragon;

void create(){
   ::create();
   //set_no_clean(1);
   set_name("xeryl's home");
   set_short("Xeryl's Home");
   set_long("This is the underground lair of the dragon, Xeryl.");
   set_smell("default","The smell of melted rock assualts you");
   set_exits((["up":"/d/undead/rooms/mts/room97.c"]));
}
/*void reset(){
   ::reset();
   if(!objectp(dragon)){
       dragon = new("/d/undead/mon/xeryl.c");
      dragon->move(TO);
   }
}*/
