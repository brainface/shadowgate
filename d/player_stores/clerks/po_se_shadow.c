#include <std.h>

#define POFF "/d/player_stores/poffices/"

inherit "/std/vendor_pstore";
// inherit "/realms/styx/vendor_pstore";
void make_me();

#define MAX_ITEMS 50

object imp;

void create() {
  ::create();
   make_me();

   set_hd(18,2);
   set("aggressive", 0);
   set_level(18);
   set_class("mage");
   set_mlevel("mage", 18);
   set_guild_level("mage",18);
   set_alignment(5);
   add_money("gold", random(500));
   set_body_type("human");
   set_mob_magic_resistance("average");
   set_overall_ac(5);
   set_stats("strength",18);
   set_max_hp(150+random(50));
   set_hp(query_max_hp());
   set_exp(300);
   set_spell_chance(95);
   set_spells(({"lightning bolt", "lightning bolt", "hold person", "powerword stun", "magic missile", "magic missile", "wall of fire", "phantom guardians", "prismatic spray" }));
   set_shop(POFF+"shadow_sewer");

}

void heart_beat() {
    object *killers;
    int i;
    ::heart_beat();
    if(!objectp(TO) || !objectp(ETO)) return;
    if(query_hp() < 80) {
       command("yell This attack will be reported!  Help!!!");
       tell_room(ETO, TOQCN+" shouts a command and an %^BOLD%^%^BLACK%^acrid smoke fills the room.");
       killers = query_attackers();
       for(i=0;i<sizeof(killers);i++) {
		  killers[i]->cause_typed_damage(killers[i], "head", roll_dice(1, 5), "untyped");
       }
    tell_room(ETO, "%^ORANGE%^When the smoke clears, you find the clerk is gone.");
    TO->move("/d/Shadowgate/void");
    TO->remove();
    }
}

void notify_messages(object ob)
{
    tell_object(ob,"\n%^BOLD%^%^BLUE%^The %^RED%^imp%^BLUE%^ appears in front of you, it turns and smirks at you, %^BOLD%^%^BLACK%^'Greetings. You have a letter in Shadow Message Service. Pick it up!'%^BLUE%^ it then vanishes in a smoke.\n");
    tell_room(ENV(ob),"\n%^BOLD%^%^BLUE%^The %^RED%^imp%^BLUE%^ appears in front of you, it turns and smirks at " +ob->QCN+", %^BOLD%^%^BLACK%^'Greetings. You have a letter in Shadow Message Service. Pick it up!'%^BLUE%^ it then vanishes in a smoke.\n", ob);
    return;
}

void make_me() {
   switch(random(2)) {
     case 0:
	set_name("Ruthe");
	set_id(({ "shop clerk","mail clerk","clerk", "ruthe", "Ruthe"}));
	set_short("Ruthe Barrard, mail clerk");
	set_long("Ruthe is a muscular human female in her thirties.  "
	   "Her auburn hair is tied in a knot, and she has pulled up "
	   "the sleeves of her formal tunic. She wears comfortable looking "
	   "brown pants underneath.  Her %^BOLD%^%^GREEN%^sharp green eyes %^RESET%^%^CYAN%^are "
	   "keen and analytical.");
	set_emotes(1, ({ "Ruthe reads a ledger and puts it away.",
	   "Ruthe taps her fingers restlessly on the counter.",
	   "Ruthe writes a quick note on a piece of paper.",
	   "Ruthe polishes the sign.",
	   "Ruthe opens the flap on the back wall and gives a bite of dried meat to the imp."
	}), 0 );
	set_gender("female");
 	set_race("human");
	break;
     case 1:
	set_name("Sarankan");
	set_id(({ "shop clerk","mail clerk","clerk", "sarankan", "Sarankan"}));
	set_short("Sarankan Sharalon, mail clerk");
 	set_long("Sarankan is an active young man in his early twenties. " 
     "He has %^BOLD%^%^BLACK%^long brown hair in a pony tail "
     "%^RESET%^%^CYAN%^and %^ORANGE%^dark eyes%^CYAN%^. He moves restlessly behind the counter, barely sitting still. "
     "He wears a loose tunic and linen pants.");
	set_gender("male");
	set_race("human");
	set_emotes(5, ({ "Sarankan takes five quick pushups, smiling wryly when he's done.",
	   "Sarankan straightens his back, squats down, holds for a few moments, and comes back to his starting position.",
	   "Sarankan picks up a thick tome and lifts it a few times above his head.",
	   "Sarankan walks restlessly back and forth behind the counter.",
	   "Sarankan throws himself into his chair, looks around the office, then just as quickly bounces back up on his feet.",
	}), 0 );
	break;
   }
}

void leave_letter(object cust, int step) {
   switch(step) {
	case 0:
	   tell_room(ETO, cust->query_cap_name()+" hands the clerk a letter.", cust);
	   tell_room(ETO, "%^GREEN%^"+TOQCN+" smiles and takes the money and "
	      	"paper at the same time. The money disappears into a small safe "
		"under the desk.  The message is put carefully into a small "
		"cylinder from one of the desk drawers before "
		+TO->query_subjective()+" raps smartly on the side of the desk.\n");
	   call_out("leave_letter", 5, cust, 1);
	   break;
	case 1:
	   tell_room(ETO, "%^BOLD%^%^BLUE%^A door in the side of the desk "
		"%^RESET%^%^ORANGE%^creaks%^BOLD%^%^BLUE%^ open and a small "
		"%^BOLD%^%^RED%^red skinned figure%^BOLD%^%^BLUE%^ hops up "
		"onto the desk with a flap of %^BOLD%^%^BLACK%^leathery wings"
		"%^BOLD%^%^BLUE%^.\n");
	   imp = new("/d/player_stores/mons/po_imp");
	   imp->move(ETO);
	   call_out("leave_letter", 3, cust, 2);
	   break;
	case 2:
	   if(!objectp(imp)) {
		tell_room(ETO, "The imp seems to have been killed or disappeared.");
	    	return;
           }
	   tell_room(ETO, "%^BOLD%^%^BLUE%^The %^BOLD%^%^RED%^imp%^BOLD%^%^BLUE%^ "
		"takes the message obediently from "+TOQCN+"'s hand, flapping "
		"its %^BOLD%^%^BLACK%^wings%^BOLD%^%^BLUE%^ occasionally for "
		"balance.  It turns and leers at you. %^BOLD%^%^BLACK%^'Don't "
		"worry,'%^BOLD%^%^BLUE%^ it smirks, %^BOLD%^%^BLACK%^'I'm tame.'\n");
	   call_out("leave_letter", 3, cust, 3);
	   break;
	case 3:
	   if(!objectp(imp)) {
		tell_room(ETO, "The imp seems to have been killed or disappeared.");
	    	return;
           }
	   tell_room(ETO, "%^BOLD%^%^BLUE%^With a sudden movement the %^RED%^"
		"imp %^BLUE%^stretches its%^BLACK%^ wings %^BOLD%^%^BLUE%^wide "
		"and leaps off the desk, flying straight towards your %^RED%^"
		"face%^BOLD%^%^BLUE%^.  Then it veers off to fly a couple of "
		"circuits round the clerk's head before it disappears through "
		"a%^RESET%^%^GREEN%^ small flap %^BOLD%^%^BLUE%^set in the "
		"back wall.%^RESET%^");
           if(objectp(imp))      imp->remove();
	   delivering = 0;
	   break;
	default:  break;
   }
}

void pickup_actions(object cust, object *what, int step) {
   int num;
   switch(step) {
      case 0:
	tell_room(ETO, "%^GREEN%^"+TOQCN+" smiles and nods at "
	   +cust->query_cap_name()+" signing the log book.", cust);
	tell_object(cust, "%^GREEN%^"+TOQCN+" smiles and nods when you sign your name.");
	tell_room(ETO, "%^GREEN%^"+capitalize(TO->query_subjective())+" knocks "
	   "twice on the side of the desk and leans forward to speak into the "
	   "small trumpet on the top of the desk.\n");
	call_out("pickup_actions", 2, cust, what, 1);
	break;
     case 1:
        imp = new("/d/player_stores/mons/po_imp");
        imp->move(ETO);
	tell_room(ETO, "%^BOLD%^%^BLUE%^A door in the side of the desk "
	   "%^RESET%^%^ORANGE%^creaks%^BOLD%^%^BLUE%^ open and a %^BOLD%^%^RED%^"
	   "small imp%^BOLD%^%^BLUE%^ emerges.  The imp spreads its %^BOLD%^"
	   "%^BLACK%^black leathery wings%^BOLD%^%^BLUE%^ and flies up to a small "
	   "flap high up on the back wall.  It disappears into the flap and you "
	   "hear a lot of muttering and mumbling before it reappears.\n");
	call_out("pickup_actions", 4, cust, what, 2);
	break;
     case 2:
        if(!objectp(imp)) {
	    tell_room(ETO, "The imp seems to have been killed or disappeared.");
	    return;
        }
	tell_room(ETO, "%^BOLD%^%^BLUE%^The %^BOLD%^%^RED%^imp%^BOLD%^%^BLUE%^ "
	   "jumps from the wall and %^BOLD%^%^CYAN%^glides%^BOLD%^%^BLUE%^ down "
	   "to land on the desk in front of the clerk to hand over an odd "
	   "looking cylinder.  It shoots you a dirty look before hopping back "
	   "into the side of the desk.\n");
	call_out("pickup_actions", 3, cust, what, 3);
        if(objectp(imp)) {
	   imp->move("/d/shadowgate/void");
	   imp->remove();
	}
	break;
     case 3:
    	num = sizeof(what);
    	if(num == 1) {
          tell_room(ETO, TOQCN+" takes the cylinder, retrieves a rolled-up paper from "
	    "it and hands it to "+cust->query_cap_name()+".", cust);
	  tell_object(cust, "%^BOLD%^%^BLUE%^"+TOQCN+" takes the cylinder, retrieves "
	    "a rolled-up paper from it, and hands it across to you.");
    	} else {
      	  tell_room(ETO, TOQCN+" takes the cylinder, retrieves %^BOLD%^"+num+
	    "%^RESET%^ pieces of paper from it, and hands them across to "
	    +cust->query_cap_name()+".", cust);
	  tell_object(cust, TOQCN+" takes the cylinder, retrieves %^BOLD%^"+num+
	    "%^RESET%^ pieces of paper from it, and hands them over to you.");
    	}
        del_letter(cust, what);
	break;
     default:  break;
   }
}
