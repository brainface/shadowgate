#include <std.h>
#include "../inherits/area_stuff.h"
inherit RA_MR_CHAM;

void create() 
{
    	::create();
	wwall = "southern";
	sexit = "south";
	hidden_room = MRS"21";	
	new(RA_MON+"gimpy")->move(TO);
}
