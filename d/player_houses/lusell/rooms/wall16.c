//Coded by Diego//

#include <std.h>
#include "../lusell.h"
inherit LWALL;

void create(){
   ::create();
   set_name("wall16");
  	set_exits(([
   	"north" : LROOMS+"tower7",
		"south" : LROOMS+"wall17"
	]));
}
