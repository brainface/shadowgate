//~Circe~ fixed a typo where "immersed" was repeated 4/27/11
#include <std.h>

inherit "/d/token_hunt/obj/high/shifterrobes.c";

/*
inherit PARMOUR;



void create(){
   ::create();
   set_name("%^BOLD%^%^BLUE%^St%^WHITE%^a%^BLUE%^r r%^RESET%^%^CYAN%^o%^BOLD%^%^BLUE%^bes%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLUE%^A long blue silk coat%^RESET%^");
   set_short("%^BOLD%^%^BLUE%^St%^WHITE%^a%^BLUE%^r robes%^RESET%^");
 set_id(({"robe","robes","shifter robes","mage robes","jacket","mage jacket","mage coat","coat","shifter coat","shifter robes","shifter jacket","starrobes","star robes"}));
   set_long("%^BLUE%^An awe inspiring sight to behold.  This long coat looks like it holds the very %^BOLD%^%^WHITE%^s%^BLUE%^t%^WHITE%^a%^BLUE%^r%^WHITE%^s %^RESET%^%^BLUE%^within.  When wearing the coat, you can feel yourself immersed in the endless sea that is the cosmos.  Shades of midnight ebb with the %^RESET%^tw%^BOLD%^i%^RESET%^nkling %^BLUE%^of the shifting %^BOLD%^%^WHITE%^silver dots %^RESET%^%^BLUE%^around you."
"%^RESET%^%^BLUE%^The odd thing is, they seem to move around as the world turns each day and you swear you can make out certain constellations.  The straightline coat is made of soft, pleated %^CYAN%^s%^BLUE%^i%^RESET%^l%^CYAN%^k %^BLUE%^and you imagine it would be quite comfortable, even %^BOLD%^%^CYAN%^dreamy %^RESET%^%^BLUE%^to wear.%^RESET%^");
   set_lore("%^BOLD%^%^WHITE%^The silk coat you hold in your eyes was once worn by the mighty King Erricson from the land of Geurron.  The king was very much into astrology that he had his castle rebuilt to take on the shape of his favorite constellation... Orion.  The kings fanaticism for the stars was well known by all within the realm.  As a token of peace talks with Erricson, the neighboring king Oswald commissioned his mages to fashion this coat that could map out the stars in the sky"
"for the current date, thus letting the wearer study the stars at his whim, not just on clear nights.%^RESET%^");
    set_weight(4);
   set_value(20000);
   set_ac(0);
   set("intbonus",1);
   set_property("enchantment",3);
   set_type("clothing");
   set_limbs(({"torso"}));
   set_wear((:this_object(),"wearme":));
   set_remove((:this_object(),"removeme":));
   set_max_internal_encumbrance(30);
   set_struck((:TO,"strike_func":));
}

int wearme()
{
    if(!ETO->is_class("bard") && !ETO->is_class("psion")&& !ETO->is_class("mage")&& !ETO->is_class("cleric")&& !ETO->is_class("sorcerer")) {
      tell_room(environment(ETO),"%^BOLD%^%^BLUE%^As if alive, the magic within it simply refuses the coat to allow "+ETOQCN+" to open and wear it.%^RESET%^",ETO);              
       tell_object(ETO,"%^BOLD%^%^BLUE%^The magic of the coat simply refuses to allow the coat to be open and worn by you.%^RESET%^");
      return 0;
   }
   tell_room(environment(ETO),"%^BOLD%^%^BLUE%^As "+ETOQCN+" slips on the coat, a magical energy radiates from it, causing the %^WHITE%^shifting images %^BLUE%^to soldify!%^RESET%^",ETO);              
   tell_object(ETO,"%^BOLD%^%^BLUE%^As you slip on the coat, a magical energy seems to radiate from within it, causing the %^WHITE%^shifting images %^BLUE%^to solidify!%^RESET%^");
   ETO->set_property("bonus_spell_slots",1);
return 1;
}

int removeme()
{
   ETO->set_property("bonus_spell_slots",-1);
   return 1;
}

int strike_func(int damage, object what, object who){
    if(random(1000) < 200){
    //thanks to Cythera for the code to follow and the describes.  Super cool and needs to be recognized
      tell_room(environment(query_worn()),"%^BOLD%^%^BLUE%^"+ETOQCN+" tears"+
        " off a %^RESET%^star %^BOLD%^%^BLUE%^from "+ETO->QP+" robe that forms into a "+
        "%^WHITE%^silver shuriken,%^BLUE%^"+
         " which is hurled at "+who->QCN+"!",({ETO,who}));
      tell_object(ETO,"%^BOLD%^%^BLUE%^Reaching for one of the images"+
         " on the %^WHITE%^stars %^BLUE%^on the robe, you tear it off.  The"+
        " %^RESET%^star %^BOLD%^%^BLUE%^takes the shape of a %^WHITE%^s%^RESET%^i%^BOLD%^lver%^BLUE%^"+
        " %^WHITE%^shuriken %^BLUE%^that you hurl at "+who->QCN+"");
        tell_object(who,"%^BOLD%^%^BLUE%^"+ETOQCN+" rips a %^WHITE%^star %^BLUE%^off "+ETO->QP+""+
        " robe that takes the shape of a %^WHITE%^s%^RESET%^i%^BOLD%^lver"+
         " shuriken %^BLUE%^which they hurl at you!");
         who->do_damage("torso",random(8)+6);
   }
}
*/