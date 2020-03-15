#include <std.h>
inherit WEAPONLESS;
void create() {
    ::create();
    set_name("king scorpion");
    set_id(({"king scorpion","scorpion","insect"}));
    set_short("King scorpion");
    set_long("
    The King Scorpion is a potent killer.  It has deadly venom and a poisoned barb at the end of it's tail.  The King scorpion also has a thick exoskeleton making it damage resistant.
");
    set_race("king scorpion");
    set_hd(20,10);
    set_level(20);
    set_size(3);
    set_overall_ac(-8);
    set_class("fighter");
    set_guild_level("fighter",20);
    set_max_hp(210);
    set_hp(210);
    set_wielding_limbs(({"right claw","left claw"}));
       add_limb("right claw","right claw",96,1,4);
       add_limb("left claw","left claw",96,1,4);
      add_limb("tail","tail",96,1,4);
      add_limb("stinger","stinger",96,1,4);
    set_attacks_num(2);
set_attack_limbs(({"left claw", "tail", "right claw"}));
   set_nat_weapon_type("blunt");
    set_funcs(({"sting"}));
    set_func_chance(35);
    set_damage(2,6);
    set_body_type("arachnid");
    set_property("swarm",1);
    set_property("no bump",1);
    set_stats("strength",18);
    set_stats("dexterity",16);
    set_stats("constitution",17);
    set("aggressive","aggfunc");
    set_property ("magic resistance",35);
    set_exp(10000);
    set_alignment(5);
}
void die(object ob) {
    message("environment",
    "King scorpion's tail drops from its striking position.\n""%^RED%^The scorpion backs away from you."
    ,environment(ob));
    :: die(ob);
}
int aggfunc() {
	TP->kill_ob(TO,0);
      force_me("emote raises its tail above its body in a striking position!");
}
void sting(object targ) {
    string dam;
   if("daemon/saving_d"->saving_throw(targ,"poison")) {
       dam="wounding";
    } else {
       dam="poisoning";
    }
    tell_object(targ,
    "%^RED%^King scorpion pierces you in the torso with its stinger, "+dam+" you!"
  );
    tell_room(environment(targ),
  "%^BLUE%^King scorpion pierces "+targ->query_cap_name()+" in the torso with its stinger, "+dam+" "+targ->query_subjective()+"!"
   ,targ);
    if(dam=="poisoning") {
        targ->do_damage("torso",roll_dice(2,6));
        targ->add_poisoning(50);
        tell_object(targ,
   "You feel a horrible numbness in your body as the poison takes effect.");
        targ->set_paralyzed(random(30)+10,
   "You are paralyzed.");
   } else {
        targ->do_damage("torso",roll_dice(2,6));
    }
return 1;
}
