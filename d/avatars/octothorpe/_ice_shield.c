//Octothorpe (12/20/08)
//Underdark Mining Caverns, Dragon Scale Cloak Ice Shield Effect
//../obj/dragoncloak.c
//Based upon Fire Shield priest spell
///cmds/priest/_fire_shield.c

#include <std.h>
#include <priest.h>
inherit SPELL;

void create(){
   ::create();
   set_author("ares");
   set_spell_name("fire shield");
   set_spell_type("priest");
   set_spell_level(3);
   set_spell_sphere("combat");
   set_spell_domain("fire");
   set_verbal_comp();
}

void spell_effect(int prof){
    int duration;
    duration = (ROUND_LENGTH * 3) * 21;
    caster->set_property("fire shield",1);
    caster->set_property("spelled", ({TO}) );
    caster->add_ac_bonus(2);
    caster->set_property("added short",({" %^BOLD%^%^RED%^(incased in ice)%^RESET%^"}));
    addSpellToCaster();
    spell_successful();
    execute_attack();
    call_out("dest_effect",duration);
}

void execute_attack(){
   object *attackers,room;
   int i;

   ::execute_attack();
   if(!objectp(caster)){
      dest_effect();
      return;
   }
   room = environment(caster);
   attackers = caster->query_attackers();
   attackers = filter_array(attackers,"is_non_immortal",FILTERS_D);
   if(!sizeof(attackers)){
      room->addObjectToCombatCycle(TO,1);
      return;
   }
   for(i=0;i<sizeof(attackers);i++){
      if(SAVING_D->saving_throw(attackers[i],"spell",0)) { continue; }
      tell_room(room,"%^BOLD%^%^WHITE%^"+attackers[i]->QP+" body heat "+
         "is sapped by the frosty shield of ic%^CYAN%^e %^WHITE%^ "+
         "around "+caster->QCN+" as "+attackers[i]->QS+" strikes "+
         ""+caster->QO+"!%^RESET%^",({caster,target}));
      tell_object(caster,"%^BOLD%^%^WHITE%^"+attackers[i]->QP+" body heat "+
         "is sapped by the shield of ic%^CYAN%^e %^WHITE%^ as "+
         ""+attackers[i]->QS+" strikes you!%^RESET%^");
        tell_object(target,"%^BOLD%^%^WHITE%^Your body heat is sapped "+
            "by the shield of ic%^CYAN%^e %^WHITE%^as you "+
            "strike "+caster->QCN+"!%^RESET%^");
       
attackers[i]->do_damage(attackers[i]->return_target_limb(),roll_dice(1,21));
    }
    room->addObjectToCombatCycle(TO,1);
}

void dest_effect(){
   if(objectp(caster)){
      tell_object(caster,"%^BOLD%^%^WHITE%^The shield of rimy "+
         "ic%^CYAN%^e %^WHITE%^flickers and fades away, leaving you "+
         "vulnerable once again.%^RESET%^");
      tell_room(environment(caster),"%^BOLD%^%^WHITE%^The shield of "+
         "rimy ic%^CYAN%^e %^WHITE%^ flickers and fades away, leaving "+
         ""+caster->QCN+" vulnerable once again.%^RESET%^",caster);
      caster->remove_property("fire shield");
      caster->add_ac_bonus(-2);
      caster->remove_property("added short",({" %^BOLD%^%^RED%^(incased in ice)%^RESET%^"}));
   }
   ::dest_effect();
   TO->remove();
}