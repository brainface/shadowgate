// Ring of Greater Magic Protection
// Thorn@ShadowGate
// 970225
// gmr_ring.c

#include <std.h>

int uses, old;
object protect;

int resist_magic();

inherit ARMOUR;

create() {
  ::create();
  set_property("ring of magic protection", 1);
  set_property("magic", 1);
  set_name("ring");
  set_id(({
  "band", "ring of greater magic protection",
  "metal band", "tarnished band",
  "platinum ring", "ring", "glowing platinum ring"
  }));
  set("short","a tarnished band of metal");
  set_long(
@AZHA
  This band of metal looks like it was used for the ring to
a beggar's bed curtains.  It is tarnished and nicked in a 
few places and seems to have a greasy look to it.  This looks
like the sort of thing that mothers warn their children about
bringing in the house.
AZHA
);
  set_lore("This ring is rumored to possess great power "+
     "against those who wield magic.  The battered "+
     "appearance of the ring is a disguise to keep "+
     "some authorities from recognizing the ring for "+
     "what it is.  At one time, such a ring had been "+
     "banned in Azha for its ability to keep the law-"+
     "enforcing magic users from apprehending certain "+
     "criminals.  This particular ring seems able to "+
     "combat more magic than others.");
  set_property("lore difficulty",7);
  set_type("ring");
  set_ac(0);
  set_weight(5);
  set("value", 125);
  set_limbs(({"right hand","left hand"}));
  set_wear((:TO,"do_wear":));
  set_remove((:TO,"takeoff":));
  uses = random(8)+3;
}

int do_wear()
{
        object *stuff, onering;
        int i,j, flag;
        
        stuff = TP->all_armour();
        j = sizeof(stuff);
        for(i=0;i<j;i++){
            if((string)stuff[i]->query_type() == "ring" && 
            stuff[i]->query_property("ring of magic protection")) {
                onering = stuff[i];
                flag = 1;
                break;
            }
        }
        if(flag){
          
            write("The magic of this ring reacts with the one already worn...\n"+
            "and they %^RED%^EXPLODE!!%^RESET%^");
            TP->do_damage(0, (random(uses)+1)*5);
            if(!onering->remove()) destruct(TO);
            if(!TO->remove()) destruct(TO);
            return 0;
        }
        protect = TP;
        old = 70 - (int)protect->query_property("magic resistance");
        protect->remove_property("magic resistance");
        protect->set_property("magic resistance", 70);
        set_heart_beat(30);
        tell_object(TP, "%^BOLD%^The ring flashes brightly for a brief instant "+
        "%^BOLD%^on your finger and then fades to a steady glow.%^RESET%^");
        TO->set_short("a %^BOLD%^%^WHITE%^glowing%^RESET%^ platinum ring");
        TO->set_long(
@AZHA
  On your finger is revealed a glowing platinum ring pulsing with
a field of magic that seems to charge even the air around it.  Runes
of power glow on the surface where you originally saw what you thought
were nicks.
AZHA
        );
        return 1;
}

void heart_beat()
{
  if (!objectp(TO->query_worn())) TO->takeoff();
   if(!objectp(TO) || !objectp(ETO) || !objectp(protect)) return;
        if(uses <= 0) {
	        tell_object(protect, "%^BOLD%^The ring flashes and suddenly "+
	        "%^BOLD%^is no more!%^RESET%^");
	        set_heart_beat(0);
                if(old) protect->set_property("magic resistance",(-1)*old);
                else protect->remove_property("magic resistance");
	        if(!TO->remove()) destruct(TO);
	        return 1;
        }
        uses--;
        tell_object(protect, "%^BOLD%^The ring flashes for a moment.%^RESET%^");
        return 1;
}

int takeoff()
{
	      set_heart_beat(0);
      if (objectp(protect)) {

        if(old) protect->set_property("magic resistance",(-1)*old);
        else protect->remove_property("magic resistance");
      } // to fix a silly bug in the rings when monsters die.
        TO->set("short","a tarnished band of metal");
        TO->set_long(
@AZHA
  This band of metal looks like it was used for the ring to
a beggar's bed curtains.  It is tarnished and nicked in a 
few places and seems to have a greasy look to it.  This looks
like the sort of thing that mothers warn their children about
bringing in the house.
AZHA
        );
        protect = 0;
        return 1;
}


