#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^CYAN%^A pair of sky blue boots%^RESET%^");
	set_id(({ "boots", "boots of wanderlust", "norews boots of wanderlust", "norew's boots of wanderlust" }));
	set_short("%^BOLD%^%^CYAN%^N%^BLACK%^o%^CYAN%^r%^BLUE%^e%^CYAN%^w%^BLACK%^'%^CYAN%^s Bo%^BLACK%^o%^CYAN%^t%^BLUE%^s%^CYAN%^ of W%^BLUE%^a%^CYAN%^n%^BLACK%^d%^CYAN%^e%^BLACK%^r%^CYAN%^l%^BLUE%^u%^BLACK%^s%^CYAN%^t%^RESET%^");
	set_obvious_short("%^CYAN%^A pair of sky blue boots%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This is a pair of sky blue %^RESET%^%^ORANGE%^leather%^BOLD%^%^CYAN%^ boots with a series of %^WHITE%^silver buckles%^CYAN%^ running up the inside of each. The leather has been reinforced to stand up to all elements of %^RESET%^%^GREEN%^nature%^BOLD%^%^CYAN%^ one may come across in their %^RED%^travels%^CYAN%^. They reach up to just below the knee in an attempt to protect against thorny undergrowth and similar threats.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(3000);
	set_lore(
@AVATAR
%^BOLD%^%^CYAN%^The entrepid explorer Norew travelled the realms for a great many years. A ranger of little reknown, he often found himself lost in some new place. He didn't care in the slightest though, for he often found the will and vigor in his trusty pair of boots to continue on in his wanderings.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" pulls the boots on and %^WHITE%^buckles%^CYAN%^ the straps.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You pull on the boots and %^WHITE%^buckle%^CYAN%^ the straps, feeling the urge to travel.%^RESET%^");
	ETO->add_stat_bonus("constitution",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^CYAN%^"+ETOQCN+" %^WHITE%^unbuckles%^CYAN%^ the straps then pulls off the boots.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^CYAN%^You %^WHITE%^unbuckle%^CYAN%^ the straps then pull off the boots and the urge to wander fades.%^RESET%^");
	ETO->add_stat_bonus("constitution",-1);
	return 1;
}
