//Made for Jaedryl
#include <std.h>
inherit ARMOUR;

int OWNED;
string owner;

void create(){
	::create();
	set_name("surcoat");
	set_id(({ "firebath surcoat", "surcoat","red surcoat","flamesilk surcoat"}));
	set_short("%^RESET%^%^RED%^Fl%^BOLD%^am%^RESET%^%^ORANGE%^esi"+
		"%^BOLD%^%^RED%^lk %^RESET%^%^RED%^Surcoat%^RESET%^");
	set_obvious_short("%^BOLD%^%^RED%^A red flamesilk surcoat%^RESET%^");
	set_long("%^RED%^Fashioned from rare flamesilk, this surcoat is an"+
		" impressive display of wealth.  The %^ORANGE%^metallic%^RED%^"+
		" threads woven with the silk thread shimmer as the light falls"+
		" on the fabric, earning its name as it seems as if the silk is "+
		"on fire.  The surcoat is dyed with shifting hues of %^BOLD%^r"+
		"%^RESET%^%^RED%^e%^BOLD%^d%^RESET%^%^RED%^ and %^ORANGE%^orange"+
		"%^RED%^, making it look as if it on fire.  The tailored surcoat "+
		"is crafted to be worn over suits of armor, typically by knights."+
		"  This allows the knight to show all who she swears allegiance to."+
		"  %^YELLOW%^Molten gold%^RESET%^%^RED%^ threads are used to "+
		"embroider the holy symbol of Kossuth into the heavy silk on the"+
		" front and back of this surcoat.%^RESET%^\n");
	set_weight(4);
	set_value(1200);
	set_lore("Flamesilk is prized among the clergy of Kossuth.  "+
		"Crafted first by a Kossuthian artesian the expensive silk"+
		" has been known to cause riots when a flamesilk garment "+
		"comes up for sale. It's rumored that those who have pleased"+
		" Kossuth in some fashion earn the rights to wear flamesilk."+
		"  Those unworthy are consumed by intense flames.");
	set_type("clothing");
	set_limbs(({ "torso" }));
set_property("enchantment",3);
	set_wear((:TO,"wear_func":));
	set_remove((:TO,"remove_func":));
	set_struck((:TO,"strike_func":));
}
int wear_func(){
     if((string)TPQN != owner) {
      tell_object(ETO,"%^RED%^Flames erupt around you and consume the surcoat.");
      tell_room(EETO,"%^RED%^As "+ETOQCN+" tries to put on the surcoat, "+
         "flames erupt and consume it!",ETO);
      TO->remove();
      return 0;
   }
  	tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" smooths out the silk surcoat over "+
         ""+ETO->QP+" armor.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You smooth out the silk surcoat over your armor.");
	return 1;
}
int remove_func(){
	tell_room(EETO,"%^BOLD%^%^RED%^"+ETOQCN+" pulls the surcoat off,"+
		" exposing "+ETO->QP+" armor.",ETO);
	tell_object(ETO,"%^BOLD%^%^RED%^You pull the surcoat off to expose your armor.");
	return 1;
}
int strike_func(int damage, object what, object who){
	if(random(1000) < 175){
	tell_room(environment(query_worn()),"%^BOLD%^%^RED%^Flames "+
         " erupt around "+ETOQCN+" and burn "+
         ""+who->QCN+"!",({ETO,who}));
	tell_object(ETO,"%^BOLD%^%^RED%^Flames erupt around you and"+
		" %^RESET%^%^RED%^burn%^BOLD%^ "+who->QCN+"!");
	tell_object(who,"%^BOLD%^%^RED%^Flames erupt around "+ETOQCN+" "+
         " and %^B_RED%^%^YELLOW%^burn"+
         "%^BOLD%^%^RED%^ you!");
		who->do_damage("torso",random(9)+1);
// return damage;	}
// This line makes the damage count DOUBLE.
// I'm assuming this wasn't really intended...
// Garrett

  return 0;
     }
}

void init()
{
        ::init();
        if(!interactive(ETO)) return;
        if(interactive(TP) && TP == environment(TO) && !OWNED) {
                owner = TPQN;
                OWNED = 1;
                set_size(TP->query_size());
        }
}
