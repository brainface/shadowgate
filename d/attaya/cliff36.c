#include <std.h>

inherit "/d/attaya/spec/ledge3";

void create(){
	::create();
       set_exits(([
          "west":"/d/attaya/cliff35",
         "east":"/d/attaya/cliff37"
]));
}

