#include <std.h>
inherit "/std/temple";

void create() {
   ::create();
   set_terrain(CEMETERY);
   set_travel(PAVED_ROAD);
   set_light(2);
   set_indoors(0);
   set_temple("the many headed mongrel");
   set_name("The Temple of the Many Headed Mongrel.");
   set_short("%^BOLD%^%^BLACK%^A Cemetery of the Constantly Watching Cur.%^RESET%^");
   set_long("%^BOLD%^%^WHITE%^An old cemetery lies here, the iron fence surrounding it in ill repair. Several black-robed figures bustle about, tending cookfires, hanging laundry, and other oddly mundane tasks, dodging stray dogs at constant risk of being underfoot.%^RESET%^");
   set_smell("default","The smell of frying meat fills the air.");
   set_listen("default","The silence is broken by the occasional bark of an excited dog.");
   set_exits(([
      "west": "/d/shadow/room/pass/pass2"
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
%^BOLD%^The Many Headed Mongrel demands of its followers with this message:%^RESET%^
Guide the Dead,
Tend the Mad,
Watch the Gates.
%^RESET%^
CHARGE
   );
   return 1;
}
