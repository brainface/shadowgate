#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_weight(0);
	set_ac(0);
	set_type("ring");
	set_property("death keep",1);
	set_property("no animate",1);
	set_name("tattoo");
	set_value(10000);
	set_id(({ "tattoo", "tat", "ink", "swan", "blackswan", "black swan", "face", "facial tattoo" }));
	set_short("a tiny black swan tattoo under his left-eye");
	set_long(
@MYLONG
This little tattoo sets just under his left-eye.  Its a finely detailed tattoo of a BLACK swan (with one itty-bitty RED feather).

MYLONG
	);
	set_limbs(({"head"}));
}

int get(){ return 1; }

int drop(){ return 1; }

void unwear(){ return;}

int query_mysize(){ return "tiny"; }

int is_tattoo(){ return 1; }

int wear_me(){
	"daemon/hide_d"->hideItem(TO,ETO,1);
return 1;
}

