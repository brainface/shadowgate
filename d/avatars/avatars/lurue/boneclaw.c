#include <std.h>
inherit WEAPON;

void create(){
	::create();
	set_name("bone claw");
	set_id(({ "bone claw", "boneclaw", "claw", "claw of bone" }));
	set_short("%^BOLD%^%^WHITE%^C%^RESET%^l%^ORANGE%^a%^BOLD%^%^WHITE%^w of B%^RESET%^o%^ORANGE%^n%^BOLD%^%^WHITE%^e%^RESET%^");
	set_obvious_short("%^RESET%^a plain looking %^BOLD%^%^WHITE%^c%^RESET%^l%^ORANGE%^a%^BOLD%^%^WHITE%^w%^RESET%^");
	set_long(
@AVATAR

%^BOLD%^%^WHITE%^This claw is fairly simple in design.  A smoothed square of %^RESET%^b%^ORANGE%^o%^RESET%^ne %^BOLD%^%^WHITE%^fits around the hand and is gripped in the palm with the other half of the square resting just above the knuckles.  Extending from the top bar are four long, razor sharp %^RESET%^b%^ORANGE%^o%^RESET%^ne cl%^ORANGE%^a%^RESET%^ws %^BOLD%^%^WHITE%^with small hooked tips that curl down and back.  Though made of bone, supportive %^RESET%^%^ORANGE%^c%^RESET%^o%^ORANGE%^pper w%^RESET%^i%^ORANGE%^re%^BOLD%^%^WHITE%^ has been used to reinforce the joints and strengthen the claw portion of the weapon.%^RESET%^

AVATAR
	);
	set_weight(10);
	set_value(300);
	set_type("slashing");
	set_prof_type("knuckles");
	set_size(1);
	set_wc(1,6);
	set_large_wc(1,6);
	set_property("enchantment",1);
	set_hit((:TO,"hit_func":));
}



int hit_func(object targ){
	if(!objectp(targ)) return 0;
	if(!objectp(ETO)) return 0;
	if(random(1000) < 200){
	tell_room(environment(query_wielded()),"%^BOLD%^%^RED%^"+ETOQCN+" thrusts their %^RESET%^"+query_short()+"%^BOLD%^%^RED%^ forward and tears downward, ripping chunks of flesh from "+targ->QCN+" with the curved tips!%^RESET%^",({ETO,targ}));
	tell_object(ETO,"%^BOLD%^%^RED%^You thrust your %^RESET%^"+query_short()+"%^BOLD%^%^RED%^ forward and tear downward, ripping chunks of flesh from "+targ->QCN+" with the curved tips!%^RESET%^");
	tell_object(targ,"%^BOLD%^%^RED%^"+ETOQCN+" thrusts their %^RESET%^"+query_short()+"%^BOLD%^%^RED%^ forward and tears downward, ripping chunks of flesh from your flesh with the curved tips!%^RESET%^");
		return roll_dice(1,4)+2;	}

}
