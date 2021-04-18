#include <std.h>
#include <magic.h>
#include <daemons.h>

inherit SPELL;

object marked,rune;
int counter;

void create(){
    ::create();
    set_author("ares");
    set_spell_name("vicarious view");
    set_spell_level(([ "cleric" : 4, "paladin" : 4, "bard":4, "mage":4, "psion":4]));
    set_spell_sphere("divination");
    set_domains(({"vigilance"}));
    set_syntax("cast CLASS vicarious view on TARGET");
    set_description("This spell allows the caster to attempt to plant a mark of justice on the target.  This mark is mostly inconspicuous, being more an outpouring of the caster's energy than a physical mark.  It will allow the caster to <observe mark> once while the spell is in effect, giving the caster a means to scry the target.  It is often used in investigations of suspicious persons, and as such, it has been developed to be somewhat quietly cast.");
    set_verbal_comp();
    set_somatic_comp();
    set_target_required(1);
    set_silent_casting(1);
    set_save("will");
}

int preSpell(){
    if(!objectp(target)){
        tell_object(caster,"This spell requires a target.");
        return 0;
    }
    if(target->query_property("justice marked")){
        tell_object(caster,"That target already wears the mark of justice!");
        return 0;
    }
    if(caster->query_property("justice marker")){
        tell_object(caster,"You may not mark more than one person for justice at a time!");
        return 0;
    }
    return 1;
}

string query_cast_string(){
    tell_object(caster,"%^ORANGE%^Running your finger along your "+
       "holy symbol, you begin to pray for guidance.%^RESET%^");
    tell_room(place,"%^ORANGE%^"+caster->QCN+" whispers a prayer "+
       "for guidance and runs "+caster->QP+" finger along "+
       ""+caster->QP+" holy symbol.%^RESET%^",caster);
	return "display";
}

void spell_effect(int prof)
{
    int duration;
    duration = 3600;

    if (!present(target, place)) {
        tell_object(caster, "Your target has left the area.");
        dest_effect();
        return;
    }

    if (!do_save(target, -8)) {
        //if(!SAVING_D->saving_throw(target,"spell",-5)){
        tell_object(caster, "%^BOLD%^%^BLUE%^Feeling the assurance of " +
                    "your deity, you close your eyes and transfer a bit of " +
                    "your energy to " + target->QCN + ", marking " + target->QO + " " +
                    "for justice.%^RESET%^");
        tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + " closes " +
                  "" + caster->QP + " eyes briefly before opening them again.%^RESET%^", caster);
        rune = new("/cmds/priest/obj/justice_mark.c");
        rune->move(caster);
        rune->set_caster(caster);
        rune->set_target(target);
        rune->set_casting_spell(TO);
        rune->set_clevel(clevel);
        target->set_property("justice marked", 1);
        target->set_property("spelled", ({ TO }));
        caster->set_property("justice marker", 1);
        addSpellToCaster();
        spell_successful();
        marked = target;
        spell_duration = duration;
        set_end_time();
        call_out("dest_effect",spell_duration);
        return;
    }else {
        tell_object(caster, "%^CYAN%^You close your eyes and attempt " +
                    "to transfer a bit of your energy to " + target->QCN + ", but " +
                    "your mark is resisted.%^RESET%^");
        tell_room(place, "%^BOLD%^%^BLUE%^" + caster->QCN + " closes " +
                  "" + caster->QP + " eyes briefly before opening them again.%^RESET%^", caster);
        dest_effect();
    }
}

void dest_effect()
{
    if (objectp(marked)) {
        tell_object(marked, "%^YELLOW%^A strange, oppressive weight " +
                    "you hardly noticed is suddenly lifted from you!%^RESET%^");
        tell_room(environment(marked), "%^YELLOW%^" + marked->QCN + " " +
                  "suddenly seems relieved for some reason.%^RESET%^", marked);
        marked->remove_property("justice marked");
        caster->remove_property("justice marker");
        rune->remove();
    }
    ::dest_effect();
    if (objectp(TO)) {
        TO->remove();
    }
}
