// Chain Mail Armor for an Imperial Soldier of Tsarven
// Thorn@ShadowGate
// 11/24/95
// Tsarvani Imperial Army
// iarmor.c

#include <std.h>

inherit "/std/armour.c";

void create() {
    ::create();
    set_name("armor");
    set("id", ({ "armor", "chain mail armor", "chain mail", "chain" }) );
    set("short", "a suit of chain mail armor");
		set_long(
@TSARVEN
	This is a suit of chain mail armor.  The crest of the cresent moon
on the breastplate identifies this is as armor worn by a member of the 
Tsarvani Imperial Army.
TSARVEN
	);
    set_weight(50);
    set("value", 75);
    set_type("chain");
    set_limbs( ({ "torso" }) );
    set_ac(5);
}
