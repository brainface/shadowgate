#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("ruby");
    set_id(({"gem","jewel","large ruby"}));
    set_short("%^BOLD%^%^RED%^"
	"Large Ruby"
	"%^RESET%^"
    );
    set_long("%^BOLD%^%^RED%^"
	"The large ruby is a excellent rough specimen. It is "
	"likely quite valuable even in its rough state, and priceless "
	"when finished by a gem cutter. You marvel at its beauty and "
	"are torn between keeping it for your own collection, or selling it "
	"for the unfinished gold value."
        "%^RESET%^"
    );
    set_weight(1);
    set_value(325);

}
void save_me(string file) { return 1; }			
