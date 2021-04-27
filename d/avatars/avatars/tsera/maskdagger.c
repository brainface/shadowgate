#include <std.h>
inherit "/d/common/obj/weapon/dagger.c";
object ob;

void create() {
    ::create();
   set_id(({"dagger","black dagger","shadow dagger","dagger of shadows"}));
   set_name("%^BOLD%^%^BLACK%^Dagger of Sh%^RESET%^a%^BOLD%^%^BLACK%^do%^RESET%^w%^BOLD%^%^BLACK%^s%^RESET%^");
   set_obvious_short("%^BOLD%^%^BLACK%^A small black dagger%^RESET%^");
   set_short("%^BOLD%^%^BLACK%^Dagger of Sh%^RESET%^a%^BOLD%^%^BLACK%^do%^RESET%^w%^BOLD%^%^BLACK%^s%^RESET%^");
   set_long("%^RESET%^This %^BOLD%^%^BLACK%^dark d%^RESET%^a%^BOLD%^%^BLACK%^gg%^RESET%^e%^BOLD%^%^BLACK%^r"
" %^RESET%^is completely %^BOLD%^%^BLACK%^black.  %^RESET%^It's"
" %^BOLD%^%^BLACK%^ob%^RESET%^s%^BOLD%^%^BLACK%^id%^RESET%^i%^BOLD%^%^BLACK%^an hilt %^RESET%^is %^BOLD%^%^BLACK%^dark %^RESET%^as the %^BOLD%^%^BLACK%^m%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^dn%^RESET%^%^BLUE%^i%^BOLD%^%^BLACK%^ght"
" sun %^RESET%^and is encrusted with pure %^BOLD%^%^BLACK%^black on%^RESET%^y%^BOLD%^%^BLACK%^x %^RESET%^around"
" its %^BOLD%^%^BLACK%^pommel.  %^RESET%^The %^BOLD%^%^BLACK%^blade %^RESET%^itself is even more unusual.  No"
" light seems to escape nor reflect from it, except perhaps along the leading edge of the blade.  Along this edge,"
" a strange %^BOLD%^g%^RESET%^l%^BOLD%^%^BLACK%^e%^RESET%^a%^BOLD%^m %^RESET%^manages to catch your eye."
"  It's as if the %^BOLD%^%^BLACK%^bl%^RESET%^a%^BOLD%^%^BLACK%^de %^RESET%^is just waiting to slice its way through something.%^RESET%^");
   set_lore("%^BOLD%^%^BLACK%^Little is known about this blade or its type.  Some say it is truly a gift from the Lord of the Shadows himself.%^RESET%^");
   set_weapon_prof("exotic");
  set("value",10000);
   set_cointype("gold");
   set_wield((:this_object(),"wield_func":));
   set_unwield((:this_object(),"unwield_func":));
   set_hit((:TO,"hit_func":));
}
int wield_func(){
      int enchantnum; 
      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^A quiet hush falls over the room as "+ETOQCN+" wraps "+ETO->query_possessive()+" fingers around the beautiful dagger.%^RESET%^",ETO);
      tell_object(ETO,"%^BOLD%^%^BLACK%^You are overcome by a strange sense of calm as you wrap your fingers around the dagger.%^RESET%^");
 enchantnum = (int)ETO->query_highest_level()/5;
      set_property("enchantment",enchantnum);
      while(TO->query_property("enchantment")< enchantnum){
      set_property("enchantment",enchantnum);
      }
      ETO->add_attack_bonus(1);
      ETO->add_damage_bonus(1);
      return 1;
}
int unwield_func(){
      remove_property("enchantment");
      ETO->add_attack_bonus(-1);
      ETO->add_damage_bonus(-1);
      return 1;
}
int hit_func(object target) {
   if(!objectp(target)) return 0;
   if(random(600) < 50){
      switch(random(10)){
         case 0..1:
  	      tell_room(environment(ETO),"%^BOLD%^%^WHITE%^"+ETO->query_cap_name()+" quickly spins around and slashes deeply into "+target->query_cap_name()+"!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^WHITE%^With amazing quickness and agility, you spin around and slash deeply into  "+target->query_cap_name()+"'s flesh with the dagger!%^RESET%^",target);
            tell_object(target,"%^BOLD%^%^WHITE%^With quickness and agility rarely seen, "+ETO->query_cap_name()+" spins around and slashes deeply into your flesh with the dagger!%^RESET%^");
            target->do_damage("torso",random(4)+1);
         break ;
 	   case 2..3:
            if(ETO->query_highest_level()<5) return 0;
  	      tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The leading edge of the dagger "+ETO->query_cap_name()+" holds %^WHITE%^glows brightly %^BLACK%^as "+ETO->query_subjective()+" slices it cleanly through "+target->query_cap_name()+"'s flesh!%^RESET%^",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^The leading edge of the dagger %^WHITE%^glows brightly %^BLACK%^as you slice it cleanly through "+target->query_cap_name()+"'s flesh, leaving "+target->query_objective()+" looking completely subdued!%^RESET%^");
            tell_object(target,"%^BOLD%^%^BLACK%^The leading edge of the dagger in "+ETO->query_cap_name()+"'s hand %^WHITE%^glows brightly %^BLACK%^as "+ETO->query_subjective()+" slices it cleanly through your flesh, making you feel strangely subdued!%^RESET%^");
            target->set_paralyzed(15,"%^BOLD%^%^BLACK%^You simply cannot move yet.. strange%^RESET%^");
            target->do_damage("torso",random(5)+1);
            break;
         case 4..5:
            if(ETO->query_highest_level()<10) return 0;
            ETO->execute_attack();
  	      tell_room(environment(ETO),"%^RESET%^%^MAGENTA%^"+ETO->query_cap_name()+" dances deftly around "+target->query_cap_name()+", making use of the shadows for an extra attack!",({target,ETO}));
            tell_object(ETO,"%^RESET%^%^MAGENTA%^You dance with agility around "+target->query_cap_name()+" as you suddenly become one with the shadows and make use of them for another attack!%^RESET%^");
            tell_object(target,"%^RESET%^%^MAGENTA%^"+ETO->query_cap_name()+" dances with ease around you as "+ETO->query_subjective()+" makes use of the shadows for another attack!%^RESET%^");
              target->do_damage("torso",roll_dice(2,8)+1);
              break;
         case 6..7:
            if(ETO->query_highest_level()<20) return 0;
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The blade in "+ETO->query_cap_name()+"'s hand suddenly darkens as the shadows begin to swirl and take on a humanoid form!");
            ob=new("/d/avatars/tsera/smon.c");
            ob->move(environment(ETO));
            ob->force_me("protect "+ETO->query_name());
            ETO->add_follower(ob);
            break;
         case 8..9:
            if(ETO->query_highest_level()<25) return 0;
            tell_room(environment(ETO),"%^BOLD%^%^BLACK%^The dagger sucks in the darkness from around it and hurtles it at "+target->query_cap_name()+"!",({target,ETO}));
            tell_object(ETO,"%^BOLD%^%^BLACK%^The dagger sucks in the darkness from around it and hurtles it at "+target->query_cap_name()+"!%^RESET%^");
            tell_object(target,"%^BOLD%^%^BLACK%^The dagger in "+ETO->query_cap_name()+" hand sucks up the darkness from around it and hurtles it at you!");
            target->set_paralyzed(20,"You are trying to get to your feet.");
            if(!random(5)) target->set_blind(1);
            else target->set_paralyzed(3+random(4),"%^BOLD%^%^BLACK%^You are trying to remove the orb of darkness from around you!");
            break;   

      }
   }
}
int save_me(string fname) {
  int enchanted_to;
  int ret;
  if (enchanted_to = query_property("enchantment")) {
  remove_property("enchantment");
  ret= ::save_me(fname);
  set_property("enchantment",enchanted_to);
  while(query_property("enchantment") != enchanted_to )
  set_property("enchantment",enchanted_to);
  return ret;
 } else {
  return ::save_me(fname);
  }
}

