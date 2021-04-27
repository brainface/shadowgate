//Modded & paid shoulderplates for alzar, from attaya's set and the collar from intruder.
#include <std.h>;
inherit ARMOUR;

void create(){
    ::create();
    set_name("shoulder plates");
    set_id(({"shoulderplates","shoulder plates","plates","silver shoulder plates"}));
    set_obvious_short("silver shoulderplates");
    set_short("%^BOLD%^%^WHITE%^Silver Shoulderplates of the Kinnesaruda%^RESET%^");
    set_long("%^BOLD%^%^WHITE%^These shoulderplates are made of heavy metal "
"with a silvered finish.  Each shoulderplate is about two feet long, extending "
"well over the wearer's shoulder and ending in a curving point.  "
"%^BOLD%^%^BLACK%^Bl%^RESET%^%^MAGENTA%^a%^BOLD%^%^BLACK%^ck and "
"%^RESET%^%^MAGENTA%^p%^BOLD%^%^BLACK%^u%^RESET%^%^MAGENTA%^r%^BOLD%^%^BLACK%^p"
"%^RESET%^%^MAGENTA%^le%^BOLD%^%^WHITE%^ accents have been worked into the metal, "
"adding to their dazzling appearance.  The shoulderplates are attached to a center "
"breastplate which may be worn over other armor, though the rising neck guard "
"would probably make wearing other neck ornamentation such as a cloak or necklace "
"impossible.%^RESET%^");
    set_lore("Despite their pristine appearance that makes these "+
       "shoulderplates seem somewhat angelic, they actually "+
       "stem from a rather evil source.  They match the description "+
       "of shoulderplates worn by Intruder, who is known to "+
       "rule over the Crystalline Tower of the Black Dawn.  "+
       "Intruder commands the powerful forces of the undead "+
       "including the fallen god Ashtar and his follower Bishimon.  "+
       "Some claim the breastplates house part of Intruder's "+
       "power, while others say that's impossible.");
    set_property("lore difficulty",26);
    set_weight(5);
    set_limbs(({"neck"}));
    set_type("clothing");
    set_value(14000);
    set_ac(0);
    set_size(-1);
    set_property("enchantment",4);
    set_property("magic resistance",10);
    set_wear((:TO,"extra_wear":));
    set_remove((:TO,"extra_remove":));
	set_armor_prof("heavy");
}

int extra_wear() {
   if(base_name(ETO) == "/d/attaya/mon/intruder") return 1;
   if(base_name(ETO) != "/d/attaya/mon/intruder"){
      if((int)ETO->query_lowest_level() < 25 || member_array("Life force of the Kinnesaruda has faded, Intruder and Autarkis are defeated",ETO->query_mini_quests()) == -1) {
         tell_object(ETO,"%^BOLD%^This is the armor of an experienced "+
            "warrior...you are not ready.%^RESET%^");
   return 0;
      }
   }
   tell_object(ETO,"%^BOLD%^You slip the cast silver shoulderplates "+
      "onto over your shoulders and attach them to your armor.%^RESET%^");
   tell_object(EETO,"%^BOLD%^"+ETOQCN+" slips the shoulderplates onto "+
	  ""+ETO->QP+" shoulders.%^RESET%^");
   return 1;
}

int extra_remove(){
   tell_object(ETO,"%^BOLD%^You unlatch the shoulderplates and slip "+
      "them off.%^RESET%^");
   tell_room(EETO,"%^BOLD%^"+ETOQCN+" unlatches the shoulderplates "+
      "and slips them off.%^RESET%^");
   return 1;
}