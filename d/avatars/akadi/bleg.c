#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^BLACK%^Dark s%^RESET%^u%^BOLD%^%^BLACK%^e%^RESET%^d%^BOLD%^%^BLACK%^e pants%^RESET%^");
	set_id(({ "pants", "leggings" }));
	set_short("%^BOLD%^%^BLACK%^Dark s%^RESET%^u%^BOLD%^%^BLACK%^e%^RESET%^d%^BOLD%^%^BLACK%^e pants%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^Dark s%^RESET%^u%^BOLD%^%^BLACK%^e%^RESET%^d%^BOLD%^%^BLACK%^e pants%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^The only adornment on these pants is jet buttons that fasten together the top. The pants are made to fit loosely, the bottom flaring out enough so that boots may be worn beneath. Finely crafted from soft suede, the pants look comfortable and very resilient to the elements.%^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(550);
	set_lore(
@AVATAR
%^BOLD%^%^BLACK%^Often sought after by rogues, these pants are said to make the wearer quick and light-footed.%^RESET%^

AVATAR
	);
	set_property("lore difficulty",7);
	set_type("clothing");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" slips into the "+query_short()+"%^BOLD%^%^BLACK%^.",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You slip on the pants and feel nimble.%^RESET%^");
	ETO->add_stat_bonus("dexterity",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" looks tired and sluggish.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You feel sluggish as you remove the pants.%^RESET%^");
	ETO->add_stat_bonus("dexterity",-1);
	return 1;
}
