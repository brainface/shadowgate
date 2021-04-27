#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("tall boots");
	set_id(({ "boots", "silk boots", "tall boots", "tall spidersilk boots", "tall spider silk boots", "spidersilk riding boots", "riding boots" }));
	set_short("%^BOLD%^%^BLACK%^Sp%^RESET%^%^BLUE%^i%^BOLD%^d%^BLACK%^er%^RESET%^%^BLUE%^s%^BOLD%^i%^RESET%^%^BLUE%^l%^BOLD%^%^BLACK%^k R%^RESET%^%^BLUE%^i%^BOLD%^d%^BLACK%^i%^RESET%^%^BLUE%^n%^BOLD%^%^BLACK%^g B%^RESET%^%^BLUE%^o%^BOLD%^o%^BLACK%^ts%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a set of tall riding boots%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^BLACK%^Though at first glance these boots look like they might be made from thin, flexible leather, closer inspection shows they are actually crafted from woven strands of dyed %^RESET%^spider silk%^BLACK%^%^BOLD%^.  This causes them to be both lightweight and very resistant to ware.  Able to be laced all the way up to mid-thigh, these tall boots use a series of straps and buckles to keep them tight to the wearer's leg.  The buckles are made from a dark non-reflective %^RESET%^%^CYAN%^metal %^BOLD%^%^BLACK%^and inset with slivers of %^RESET%^%^BLUE%^black sapphire%^BOLD%^%^BLACK%^.  These gems are so dark that they seem almost black, though very close inspection reveals a hint of the %^RESET%^%^BLUE%^deep blue %^BOLD%^%^BLACK%^that is their true color.  Made for riding, one could easily leave the top strap undone and fold the top down to make a stylish fringe over the knee.%^RESET%^

AVATAR
	);
	set_weight(4);
	set_value(3200);
	set_lore(
@AVATAR

Woven from the strands of spider silk harvested by the drow, these boots are sought after by the underground races for their light weight and sturdiness.  Those few surface side dwellers who have somehow managed to bring a set from the darkness likewise report of their exceptional craft and wearability.  Some claim that the enchantments upon these boots are what causes them to be so exceptional, though there are several who are quick to remove the inset gems from the buckles, claiming that these powers are not worth the longevity they offer.

AVATAR
	);
	set_property("lore difficulty",22);
	set_type("clothing");
	set_limbs(({ "left foot", "right foot" }));
	set_size(2);
	set_property("enchantment",2);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^Using the %^RESET%^%^BLUE%^black sapphire %^BOLD%^%^BLACK%^buckles, you synch the %^RESET%^"+query_short()+" %^BOLD%^%^BLACK%^tight around your leg.%^RESET%^");
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^With a series of clicks, you undo the %^RESET%^%^BLUE%^black sapphire %^BOLD%^%^BLACK%^buckles of your "+query_short()+" %^BOLD%^%^BLACK%^and slide them off.%^RESET%^");
	return 1;
}
