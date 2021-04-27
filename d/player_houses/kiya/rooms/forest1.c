#include <std.h>
#include "../defs.h"
inherit INH+"forest";

void create() {
   ::create();
   set_long((:TO,"long_desc":));
   set("night long",(:TO,"night_desc":));
   add_item(({"mountains","walls","stone walls","mountainside"}),(:TO,"mountain_desc":));
   add_item(({"rocks","stones","rubble"}),(:TO,"stones_desc":));
   add_item(({"black stone","dark stone","dark black stone"}),"%^GREEN%^This stone seems oddly out of "
"place amongst the rubble at the base of the mountainside.  It is a %^BLACK%^%^BOLD%^dark black "
"shade%^RESET%^%^GREEN%^, with a precise shape that is almost unnatural, like it was formed by mortal "
"hands.  Your fingertips suddenly itch to tap upon the dark stone.%^RESET%^");
   set_exits(([
     "southeast" : ROOMS+"forest2",
     "southwest" : ROOMS+"forest3"
   ]));
}

string mountain_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^The %^WHITE%^snowcapped%^GREEN%^ peaks of the mountains rise again to the north, "
"barring any further passage that way.  Just at the base of the mountainside, you can see a rather large "
"pile of %^BLACK%^%^BOLD%^rocks%^RESET%^%^GREEN%^, perhaps from a landslide.%^RESET%^");
   }
   return ("%^GREEN%^The %^BLUE%^tall peaks%^GREEN%^ of the mountains rise again to the north, barring "
"any further passage that way.  Just at the base of the mountainside, you can see a rather large pile of "
"%^BLACK%^%^BOLD%^rocks%^RESET%^%^GREEN%^, perhaps from a landslide%^RESET%^");
}

string stones_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^At the base of the mountainside is a rather large pile of rocks and rubble.  "
"Amongst the %^WHITE%^snow-covered%^GREEN%^ rocks, one in particular stands out, a dark stone that looks "
"almost %^BLACK%^%^BOLD%^black%^RESET%^%^GREEN%^.%^RESET%^");
   }
   return("%^GREEN%^At the base of the mountainside is a rather large pile of rocks and rubble.  "
"Amongst the rocks, one in particular stands out, a dark stone that looks almost "
"%^BLACK%^%^BOLD%^black%^RESET%^%^GREEN%^.%^RESET%^");
}

string long_desc() {
   if (season(time()) == "winter") {
     return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the "
"surrounding mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  "
"Their %^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  The forest floor is coated in a thick layer of "
"%^WHITE%^snow%^GREEN%^, leaving it very hard to find a path through the trees.  Directly before you to "
"the north, a sheer wall of %^BLACK%^%^BOLD%^ro%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^%^GREEN%^ "
"blocks any further passage, and the forest continues to the south.%^RESET%^\n");
   }
   if (season(time()) == "autumn") {
     return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the "
"surrounding mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  "
"Their %^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  All sorts of small shrubs thrive upon the leaf-covered "
"ground, leaving it very hard to find a path through the trees.  Directly before you to the north, a "
"sheer wall of %^BLACK%^%^BOLD%^ro%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^%^GREEN%^ blocks any "
"further passage, and the forest continues to the south.%^RESET%^\n");
   }
   return("%^GREEN%^Within the %^BLACK%^%^BOLD%^high stone walls%^RESET%^%^GREEN%^ of the "
"surrounding mountains, has grown this dense forest of ancient trees, towering hundreds of feet above.  "
"Their %^ORANGE%^branches%^GREEN%^ and "
"%^BOLD%^le%^YELLOW%^a%^RED%^v%^RESET%^%^GREEN%^e%^BOLD%^s%^RESET%^%^GREEN%^ are intertwined with a "
"myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that at times it is hard to "
"see the sky clearly through the thick foliage.  All sorts of small shrubs thrive upon the forest floor, "
"leaving it very hard to find a path through the trees.  Directly before you to the north, a "
"sheer wall of %^BLACK%^%^BOLD%^ro%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^%^GREEN%^ blocks any "
"further passage, and the forest continues to the south.%^RESET%^\n");
}

string night_desc() {
   if (season(time()) == "winter") {
     return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the "
"trees in this dense, ancient forest, which has grown hidden within this small clearing in the "
"surrounding mountains.  The trees stretch hundreds of feet above, with their branches and leaves "
"intertwined by a myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even "
"the %^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above "
"are hard to see at times.  The forest floor is coated in a thick layer of %^WHITE%^snow%^GREEN%^, "
"leaving it very hard to find a path through the darkened forest.  Directly before you to the north, a "
"sheer wall of %^BLACK%^%^BOLD%^ro%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^%^GREEN%^ blocks any "
"further passage, and the forest continues to the south.%^RESET%^\n");
   }
   if (season(time()) == "autumn") {
     return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the "
"trees in this dense, ancient forest, which has grown hidden within this small clearing in the "
"surrounding mountains.  The trees stretch hundreds of feet above, with their branches and leaves "
"intertwined by a myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even "
"the %^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above "
"are hard to see at times.  All sorts of small shrubs thrive upon the leaf-covered ground, leaving it "
"very hard to find a path through the darkened forest.  Directly before you to the north, a sheer wall of "
"%^BLACK%^%^BOLD%^ro%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^%^GREEN%^ blocks any further passage, "
"and the forest continues to the south.%^RESET%^\n");
   }
   return("%^BLACK%^%^BOLD%^Shadows%^RESET%^%^GREEN%^ flicker between the trunks of the "
"trees in this dense, ancient forest, which has grown hidden within this small clearing in the "
"surrounding mountains.  The trees stretch hundreds of feet above, with their branches and leaves "
"intertwined by a myriad of %^CYAN%^fl%^WHITE%^o%^CYAN%^wer%^RESET%^%^GREEN%^-draped vines, so that even "
"the %^WHITE%^bri%^BOLD%^g%^RESET%^%^WHITE%^ht s%^BOLD%^t%^RESET%^%^WHITE%^ars%^GREEN%^ in the sky above "
"are hard to see at times.  All sorts of small shrubs thrive upon the forest floor, leaving it "
"very hard to find a path through the darkened forest.  Directly before you to the north, a sheer wall of "
"%^BLACK%^%^BOLD%^ro%^RESET%^%^WHITE%^c%^BLACK%^%^BOLD%^k%^RESET%^%^GREEN%^ blocks any further passage, "
"and the forest continues to the south.%^RESET%^\n");
}

void init() {
   ::init();
   add_action("tap_fun","tap");
}

int tap_fun(string str) {
   if(!str) {
     notify_fail("What do you want to tap?\n");
     return 0;
   }
   if(str != "dark stone" && str != "black stone") {
     notify_fail("Nothing happens.\n");
     return 0;
   }
   if(member_array("north",ETP->query_exits()) != -1) {
     tell_object(TP,"%^BLACK%^%^BOLD%^You tap on the black stone, and hear a rumble as a portion of the "
"wall before you moves, closing the pathway out of the forest!");
     tell_room(ETP,"%^BLACK%^%^BOLD%^"+TP->QCN+" taps on a stone, and you hear a rumble as a portion of "
"the wall before you moves, closing the pathway out of the forest!",TP);
     remove_exit("north");
     tell_room(ROOMS+"path1","%^BLACK%^%^BOLD%^You hear a rumble, as a portion of the stone wall before "
"you moves, closing the entrance to the forest!");
     (ROOMS+"path1")->remove_exit("south");
   }
   else{
     tell_object(TP,"%^BLACK%^%^BOLD%^You tap on the black stone, and hear a rumble as a portion of the "
"wall before you moves aside to reveal a rocky path leading out of the forest!");
     tell_room(ETP,"%^BLACK%^%^BOLD%^"+TP->QCN+" taps on a stone, and you hear a rumble as a portion of "
"the wall before you moves aside to reveal a rocky path leading out of the forest!",TP);
     add_exit(ROOMS+"path1","north");
     tell_room(ROOMS+"path1","%^BLACK%^%^BOLD%^You hear a rumble as a portion of the stone wall before "
"you moves aside, to reveal a hidden forest within the mountains!");
     (ROOMS+"path1")->add_exit(ROOMS+"forest1","south");
   }
   return 1;
}

void reset() {
   ::reset();
   switch(random(11)) {
     case 0..1:
     tell_room(TO,"%^CYAN%^A small, "
"%^MAGENTA%^br%^BLUE%^ig%^BOLD%^ht%^CYAN%^-f%^GREEN%^ea%^YELLOW%^th%^RESET%^%^ORANGE%^er%^RED%^%^BOLD%^ed "
"%^RESET%^%^CYAN%^bird alights on a branch overhead, filling the air with its cheerful song.%^RESET%^");
     break;
     case 2..3:
     tell_room(TO,"%^CYAN%^A light mountain breeze brushes through the trees, filling the air with the "
"%^MAGENTA%^soft%^CYAN%^ scent of flowers.%^RESET%^");
     break;
     case 4:
     tell_room(TO,"%^CYAN%^For a few seconds you can catch glimpses of a %^WHITE%^translucent%^CYAN%^ "
"woman's figure, with %^WHITE%^%^BOLD%^shi%^CYAN%^m%^WHITE%^mer%^YELLOW%^i%^WHITE%^ng%^RESET%^%^CYAN%^ "
"wings and %^BOLD%^w%^WHITE%^in%^CYAN%^ds%^WHITE%^we%^CYAN%^pt%^RESET%^%^CYAN%^ hair, fluttering in among "
"the trees, before she disappears from sight.%^RESET%^");
     break;
     case 5:
     tell_room(TO,"%^CYAN%^The wind brushes past your face, almost like the %^ORANGE%^caress%^CYAN%^ of "
"a soft hand, as you catch a second's glimpse out of the corner of your eye, of a winged feminine "
"figure.%^RESET%^");
     break;
     case 6..7:
     tell_room(TO,"%^CYAN%^Tiny butterflies flutter through the "
"%^ORANGE%^br%^GREEN%^a%^ORANGE%^nc%^GREEN%^%^BOLD%^h%^RESET%^%^ORANGE%^es%^CYAN%^ above, in an elaborate "
"dance among the %^MAGENTA%^pale flowers%^CYAN%^.%^RESET%^");
     break;
     case 8:
     tell_room(TO,"%^CYAN%^The sound of "
"%^GREEN%^l%^ORANGE%^e%^GREEN%^av%^BOLD%^e%^RESET%^%^GREEN%^s%^CYAN%^ rustling comes from above, in the "
"wake of some small, unseen forest creature.%^RESET%^");
     break;
     case 9..10:
     if (season(time()) == "winter") {
       tell_room(TO,"%^CYAN%^The branches overhead sway in the breeze, as a few %^WHITE%^snowflakes "
"%^CYAN%^drift down to join the ground's %^WHITE%^snowy%^CYAN%^ carpet.%^RESET%^");
     }
     else {
       tell_room(TO,"%^CYAN%^The branches overhead sway in the breeze, dropping "
"%^GREEN%^l%^ORANGE%^e%^GREEN%^av%^BOLD%^e%^RESET%^%^GREEN%^s%^CYAN%^ to flutter down through the air "
"around you, and rest upon the forest floor.%^RESET%^");
     }
     break;
   }
}
