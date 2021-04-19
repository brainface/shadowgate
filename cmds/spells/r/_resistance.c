#include <priest.h>
#include <daemons.h>
inherit SPELL;

int bonus;

void create()
{
    ::create();
    set_spell_name("resistance");
    set_spell_level(([ "bard" : 1, "druid" : 1, "paladin" : 1, "mage" : 1, "cleric" : 1, "psywarrior" : 1, "psion" : 1, "inquisitor" : 1, "magus" : 1 ]));
    set_spell_sphere("alteration");
    set_syntax("cast CLASS resistance");
    set_damage_desc("clevel / 35 + 1 to saving throws");
    set_description("By this spell, the caster imbues themselves with a small amount of resistance to harm.  The spell grants small bonus to will, fortitude and reflex.

%^BOLD%^%^RED%^See also:%^RESET%^ resistance *feats");
    set_verbal_comp();
    set_somatic_comp();
    set_helpful_spell(1);
}

string query_cast_string()
{
    return "%^CYAN%^" + caster->QCN + " hums a few soft notes.%^RESET%^";
}

int preSpell()
{
    if ((int)caster->query_property("morale-boost")) {
        tell_object(CASTER, "That target is already under the influence of heroism or resistance spell.");
        return 0;
    }
    return 1;
}

spell_effect(int prof)
{
    if (!objectp(caster)) {
        dest_effect();
        return;
    }
    if (caster->query_property("morale-boost")) {
        tell_object(caster, "You are already protected by this spell!");
        dest_effect();
        return;
    }
    if (interactive(caster)) {
        tell_object(caster, "%^GREEN%^As the last note fades, you feel a light prickling of protection across your skin.");
        tell_room(place, "%^GREEN%^The last note fades as " + caster->QCN + " glances around.", caster);
    }
    bonus = clevel / 35 + 1;
    bonus = bonus < 1 ? 1 : bonus;
    bonus = bonus > 4 ? 4 : bonus;

    caster->add_saving_bonus("all", bonus);
    caster->set_property("morale-boost", 1);
    spell_successful();
    addSpellToCaster();
}

void dest_effect()
{
    if (objectp(caster) && caster->query_property("morale-boost")) {
        tell_object(caster,"%^CYAN%^An increase of morale you felt washes away as your resistance fades.");
        caster->add_saving_bonus("all", -bonus);
        caster->remove_property("morale-boost");
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
