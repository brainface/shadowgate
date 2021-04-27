#include <std.h>
inherit ARMOUR;

void create(){
	::create();
	set_name("%^RESET%^en%^BOLD%^gr%^RESET%^a%^BOLD%^%^BLACK%^v%^RESET%^ed %^BOLD%^moonstone %^BLACK%^greaves%^RESET%^");
	set_id(({ "greaves", "wolf", "wolf greaves", "moonstone greaves", "moonstone" }));
	set_short("%^RESET%^%^BOLD%^H%^RESET%^e%^BOLD%^%^BLACK%^a%^WHITE%^r%^RESET%^t of the %^ORANGE%^Pa%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^k%^RESET%^");
	set_long(
@AVATAR
%^RESET%^Carved from two single pieces of %^BOLD%^mo%^CYAN%^o%^WHITE%^n%^RESET%^%^CYAN%^st%^BOLD%^%^WHITE%^one%^RESET%^, these greaves should be very heavy. However, they seem as light as feathers. They have been carved with a relief of a %^BOLD%^%^BLACK%^wolf%^RESET%^ leaping, it's jaws open to %^RED%^attack%^RESET%^. The detail in the carving is so lifelike you swear you can see the ears twitch and the jaw move. The eyes of the wolf are spots of pure %^BOLD%^silver%^RESET%^. The greaves attach to the legs with %^ORANGE%^fine leather straps%^RESET%^ and %^BOLD%^silver buckles%^RESET%^. A sense of power emanates from the greaves .

AVATAR
	);
	set_weight(5);
	set_value(5000);
	set_lore(
@AVATAR
%^BOLD%^%^CYAN%^The %^RESET%^%^BOLD%^H%^RESET%^e%^BOLD%^%^BLACK%^a%^WHITE%^r%^RESET%^t of the %^ORANGE%^Pa%^BOLD%^%^BLACK%^c%^RESET%^%^ORANGE%^k%^BOLD%^%^CYAN%^ greaves first appeared in these lands being worn by Jerlekt Softstrider, known to some as the %^BLACK%^Shadowed Wolf%^CYAN%^. He was a devoted ranger of Selune and battled the minions of Selune's enemies whenever he could, always striking from the shadows only to slide back into them after slaying them cleanly. Selune purportedly gifted him with these greaves to assist him with his constant battles. His disappearance was never recorded, so it is speculated that perhaps he has just retired, or perhaps his %^BLACK%^shadow%^CYAN%^ finally caught up to him. %^WHITE%^- "Chronicles of the %^BLACK%^Wolf%^WHITE%^", Saelmion Dukanish

AVATAR
	);
	set_property("lore difficulty",15);
	set_type("leather");
	set_limbs(({ "right leg", "left leg" }));
	set_size(2);
	set_property("enchantment",1);
	set_ac(1);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" growls softly as he buckles on the greaves, his voice low and %^RESET%^%^RED%^feral%^BOLD%^%^BLACK%^.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You buckle on the greaves and feel your blood %^RED%^boil%^RESET%^.");
	ETO->add_stat_bonus("dexterity",1);
	ETO->add_stat_bonus("charisma",-1);
	ETO->set_property("magic resistance",5);
	return 1;
}
int remove_func(){
	tell_room(environment(ETO),"%^BOLD%^%^BLACK%^"+ETOQCN+" calms down visibly as he removes the greaves, shaking his head to clear some unknown sound.%^RESET%^",ETO);
	tell_object(ETO,"%^BOLD%^%^BLACK%^You unbuckle the greaves slowly, the howls of a pack of feral wolves ringing in your head.%^RESET%^");
	ETO->add_stat_bonus("dexterity",-1);
	ETO->add_stat_bonus("charisma",1);
	ETO->set_property("magic resistance",-5);
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 400){
	tell_room(environment(query_worn()),"%^RESET%^%^BOLD%^Just as "+who->QCN+" is about to strike "+ETOQCN+", he rushes forward, his form becoming that of a %^BLACK%^shadowy wolf%^WHITE%^ as he avoids the blow.",({ETO,who}));
	tell_object(ETO,"%^RESET%^%^BOLD%^Just as "+who->QCN+" is about to strike you, there is a low snap and growl as you leap forward, avoiding the blow..%^RESET%^");
	tell_object(who,"%^RESET%^%^BOLD%^As you strike "+ETOQCN+", he transforms into a %^BLACK%^shadowy wolf%^WHITE%^ and your blow passes right through him!%^RESET%^");
return (damage*100)/100;	}
}