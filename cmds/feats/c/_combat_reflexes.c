#include <std.h>
#include <daemons.h>

inherit FEAT;

void create() {
    ::create();
    feat_type("permanent");
    feat_category("MeleeDamage");
    feat_name("combat reflexes");
    feat_prereq("Thief L1");
    feat_desc("Combat reflexes represents the highly trained speed and dexterity of the rogue in combat, allowing them more damaging attacks when they flank an opponent. The character will use this chance to stab a foe, or launch alternative attacks in situations where stab would be ineffective. Success on this attack depends on whether your victim is denied their ac dodge bonus, whether you're flanking them and on a criticall roll. You will gain additional stab multiplier per ten class levels.

%^BOLD%^%^WHITE%^See also: status effects");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob){
    if(!objectp(ob)) return 0;
    if(ob->query_class_level("thief") < 1) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat(){
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob){
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob){
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect(){
    ::dest_effect();
    remove_feat(TO);
    return;
}
