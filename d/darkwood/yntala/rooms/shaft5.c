//shaft5
#include <std.h>
#include <rooms.h>
#include "../yntala.h"
inherit CROOM;

void create(){
   switch(random(13)){
      case 0..5:
      break;
      case 6..10:
         set_monsters(({TMONDIR +"yuan-tip.c"}),({2}));
      break;
      case 11..12:
         set_monsters(({TMONDIR +"yuan-tih.c"}),({1}));
   }
   set_repop(40);

::create();
   set_property("indoors",1);
   set_property("light",-3);
   set_property("no teleport",1);
   set_terrain(VILLAGE);
   set_travel(PAVED_ROAD);
   set_name("%^RESET%^Within a small shaft");
   set_short("%^RESET%^The inside of a pyramid%^RESET%^");
   set_listen("default","Whispers and soft hisses seem to float up from below and mix with the sounds of dripping water.");
   set_long((:TO,"ldesc":));
   set_items(([
   "walls":"The walls here seem to be in better condition than the outside of the pyramid.  They are smooth to the touch and are covered with some sort of slimy substance.  Beneath the substance however, if you look closely, there seems to be pictures or writing of some sort.",
   ({"slime","slimy substance","substance"}):"The substance that covers the walls seems to have no color nor odor.  Here it is quite thick and could even pass for a type of jelly that has been smeared onto the walls.",
   ({"pictures","writing"}):"It is hard to make out exactly what these are, but they appear to be very crude"
" drawings of snake like creatures attacking humanoids.",
]));
   set_exits((["west":INRMS+"shaft6","up":INRMS+"shaft4"]));
}
string ldesc(string str){
   return("%^BOLD%^%^BLACK%^It would appear that you have reached the bottom of the pyramid, or at least"
" the bottom of this shaft.  There is a tunnel that leads off to the west, or you can go into the steep shaft"
" that leads up.  The slime still covers the walls in a thick, jelly-like substance and quivers with each step you"
" take.  Beneath the jelly, it looks like there is writing or pictures of some sort on the walls.%^RESET%^");
} 

