#include <std.h>
#include <daemons.h>
#include "lair.h"
inherit ROOMS"tunnel";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^A narrow, winding tunnel%^RESET%^\n"
"%^BLUE%^This tunnel is particularly narrow, barely large enough for a human-sized figure to move through, though it "
"seems to be widening just to the northwest.  The walls and floor are %^ORANGE%^rou%^BOLD%^%^BLACK%^g%^RESET%^%^ORANGE%^h"
"%^BLUE%^, and the occasional outcropping forces you to duck or walk sideways for a few paces.  It is difficult to see "
"more than a few feet down the corridor in the complete %^BOLD%^%^BLACK%^darkness%^RESET%^%^BLUE%^.  An odd few %^YELLOW%^"
"c%^WHITE%^oi%^YELLOW%^n%^WHITE%^s %^RESET%^%^BLUE%^are scattered across the stone floor underfoot.\n%^RESET%^");
   set_exits(([
     "northwest":ROOMS"tunnel1",
     "south":ROOMS"tunnel3",
   ]));
   set_pre_exit_functions(({"northwest"}),({"GoThroughDoor"}));
}

int GoThroughDoor() {
   if(TP->query_true_invis()) return 1;
   if((int)TP->query_level() < 35) tell_object(TP,"%^BOLD%^%^BLACK%^A whiff of bitter, %^GREEN%^acrid %^BLACK%^gas "
"carries on the air and tickles your nose.  You get the feeling you shouldn't be here.%^RESET%^");
   else tell_object(TP,"%^BOLD%^%^BLACK%^A whiff of bitter, %^GREEN%^acrid %^BLACK%^gas carries on the air and tickles "
"your nose.%^RESET%^");
   return 1;
}