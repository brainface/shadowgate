#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("scourge");
	set_id(({ "scourage", "whip" }));
	set_short("%^BOLD%^%^BLACK%^A%^MAGENTA%^c%^BLACK%^cursed S%^MAGENTA%^c%^BLACK%^ourage of M%^MAGENTA%^i%^BLACK%^sfortune%^RESET%^");
	set_obvious_short("%^BOLD%^%^BLACK%^a duskwood and dark leather scourge%^RESET%^");
	set_long(
@AVATAR
%^RESET%^%^CYAN%^The materials used to make this scourge are of the highest quality %^BLUE%^duskwood %^CYAN%^and %^BOLD%^%^BLACK%^leather%^RESET%^%^CYAN%^.  The braiding of the whip is carefully done so that the serpentine movements seem almost alive.  The braid of the leather whip has been affixed to a %^BLUE%^duskwood %^CYAN%^handle and a metal disk displaying the insignia of a %^RED%^%^BOLD%^red field %^RESET%^%^CYAN%^with a set of %^BOLD%^%^BLACK%^black antlers %^RESET%^%^CYAN%^in the foreground is painted with incredible detail.  At the end of the whip, tiny barbs of steel have been set to make each strike of this whip extra painful. %^RESET%^

AVATAR
	);
	set_weight(2);
	set_value(1700);
	set_lore(
@AVATAR
Made for those who serve as guardians of Beshaba's church, this scourge was clearly designed by a master weaponsmith and would be prized by the one who owned it.  Not only for its exceptional quality but as a symbol of status among the faith.  The loss of such a fine weapon  could likely only come at the death of the original owner or the blessings of Beshaba herself.

AVATAR
	);
	set_property("lore difficulty",21);
	set_type("lash");
	set_prof_type("whip");
	set_size(2);
	set_wc(2,3);
	set_large_wc(2,3);
	set_property("enchantment",2);
	set_wield((:TO,"wield_func":));
	set_unwield((:TO,"unwield_func":));
	set_hit((:TO,"hit_func":));
}
int wield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^The coil of the "+query_short()+" %^BOLD%^%^MAGENTA%^seems to come alive as you let the length out.  It seems almost eager to help spread some %^BLACK%^misfortune%^MAGENTA%^ to others! %^RESET%^");
	ETO->add_attack_bonus(1);
	return 1;
}
int unwield_func(){
	tell_room(environment(ETO),"",ETO);
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^The coils of the "+query_short()+" %^BOLD%^%^MAGENTA%^wind up at your command, the leather bands oozing the %^RED%^blood%^MAGENTA%^ of those who had the unfortunate luck to cross you!%^RESET%^");
	ETO->add_attack_bonus(-1);
	return 1;
}
int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^MAGENTA%^"+ETOQCN+"'s "+query_short()+" %^MAGENTA%^%^BOLD%^cuts through the air, striking into "+targ->QCN+" as a burst of raw power sparks across "+targ->QCN+"'s body!  "+targ->QCN+" staggers and seems dazed by their inability to escape the attack!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^MAGENTA%^Suddenly, you draw your hand back and crack the "+query_short()+" %^MAGENTA%^%^BOLD%^forward!  The %^BLACK%^barbs %^MAGENTA%^gleam as they cut through the air and %^RED%^spark %^MAGENTA%^with a burst of raw power when they strike "+targ->QCN+"!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^MAGENTA%^"+ETOQCN+"'s "+query_short()+" %^MAGENTA%^%^BOLD%^cuts through the air, striking into you with a burst of raw power!  Staggered, you are dazed by your inability to escape the attack!%^RESET%^");
		targ->set_paralyzed(roll_dice(6,0)+0);
return 0;	}
}