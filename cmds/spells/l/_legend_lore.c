#include <std.h>
#include <spell.h>
inherit SPELL;

object ob,*ppl;
int i;

void create() {
    ::create();
    set_spell_name("legend lore");
    set_spell_level(([ "bard" : 1, "mage" : 6, "inquisitor" : 6, "oracle":6, "psion" : 6 , "nightblade":4]));
    set_mystery("lore");
    set_discipline("seer");
    set_domains("knowledge");
    set_spell_sphere("divination");
    set_syntax("cast CLASS legend lore on <object>");
    set_description("This spell grants the caster a second's insight into the nature of an item, revealing both magical "
"attributes and its history.  The caster will also reveals the item's true nature to those standing nearby.  Whether the "
"truth of the item can be revealed is dependant upon the caster's strength, and the obscurity of the item.");
    set_verbal_comp();
    set_somatic_comp();
    set_arg_needed();
	set_helpful_spell(1);
}

string query_cast_string() {
    return "%^CYAN%^"+caster->QCN+" mutters under "+caster->QP+" breath, concentrating.";
}

void spell_effect(int prof) {
    int iddiff, lorediff;
    if (!arg)    {
        tell_object(caster,"You don't notice that here.");
        dest_effect();
        return;
    }

    ob = present(arg,environment(caster));
    if (!ob) ob = present(arg,caster);

    if (!ob) {
        tell_object(caster,"You do not see that here.");
        dest_effect();
        return;
    }
    if (living(ob)) {
        tell_object(caster,""+capitalize(arg)+" is a living creature!");
        dest_effect();
        return;
    }
    spell_successful();

    tell_object(caster,"%^CYAN%^The magical nature of the "+arg+" springs to your lips, and you speak its true name "
                "aloud.%^RESET%^");
    tell_room(place,"%^CYAN%^A revelation seems to come over "+caster->QCN+", and "+caster->QS+" speaks the true name "
              "of the "+arg+" aloud.%^RESET%^",caster);
    ppl = all_inventory(environment(caster));
    for (i = 0;i < sizeof(ppl);i++) {
        if (interactive(ppl[i])) ob->add_identified(ppl[i]->query_name());
    }


    tell_object(caster,"%^CYAN%^A flash of insight reveals the origins of the "+arg+" to you:%^RESET%^");
    tell_object(caster,ob->query_lore());
    ob->add_studied(caster->query_name());
    dest_effect();
}

void dest_effect() {
    ::dest_effect();
    if(objectp(TO)) TO->remove();
}
