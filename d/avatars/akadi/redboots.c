#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^%^RED%^Red %^BOLD%^s%^RESET%^%^RED%^ued%^BOLD%^e%^RESET%^%^RED%^ boots%^RESET%^");
	set_id(({ "boots", "suede boots" }));
	set_short("%^RESET%^%^RED%^Red %^BOLD%^s%^RESET%^%^RED%^ued%^BOLD%^e%^RESET%^%^RED%^ boots%^RESET%^");
	set_obvious_short("%^RESET%^%^RED%^Red %^BOLD%^s%^RESET%^%^RED%^ued%^BOLD%^e%^RESET%^%^RED%^ boots%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Crafted from suede dyed %^RED%^r%^BOLD%^%^RED%^e%^RESET%^%^RED%^d%^RESET%^, these boots are practical while maintaining a sense of style. %^BOLD%^Si%^RESET%^lv%^BOLD%^er bu%^RESET%^t%^BOLD%^t%^RESET%^o%^BOLD%^ns%^RESET%^ allow the boots to be fastened at the side, and each button is adorned with a single, small %^BOLD%^%^RED%^r%^RESET%^%^RED%^u%^BOLD%^%^RED%^b%^RESET%^%^RED%^y%^RESET%^ in the shape of a %^ORANGE%^m%^RED%^u%^ORANGE%^sic%^RED%^a%^ORANGE%^l%^RESET%^ note. For added comfort, silk dyed a deep shade of %^RED%^cr%^BOLD%^ims%^RESET%^%^RED%^on%^RESET%^ lines the inside of the attractive boots. Thick soles keep the wearers feet well protected from the road, and the soft suede does not compromise movement. %^RESET%^

AVATAR
	);
	set_weight(3);
	set_value(245);
	set_type("clothing");
	set_limbs(({ "right foot", "left foot" }));
	set_size(2);
	set_property("enchantment",1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
}
int wear_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You feel handsome as you slip on the fine boots.%^RESET%^");
	ETO->add_stat_bonus("charisma",1);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^With a hint of regret, you slip off the boots.%^RESET%^");
	ETO->add_stat_bonus("charisma",-1);
	return 1;
}
