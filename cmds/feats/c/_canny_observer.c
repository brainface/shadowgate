#include <std.h>
#include <daemons.h>
#include <dirs.h>

inherit FEAT;

int FLAG;

void create()
{
    ::create();
    feat_type("permanent");
    feat_category("Talent");
    feat_name("canny observer");
    feat_desc("You receive a +4 bonus to perception.");
    permanent(1);
}

int allow_shifted() { return 1; }

int prerequisites(object ob)
{
    if (!objectp(ob)) {
        return 0;
    }
    if ( !ob->is_class("thief") ||
          !ob->query_class_level("bard") ) {
        dest_effect();
        return 0;
    }
    return ::prerequisites(ob);
}

void execute_feat()
{
    ::execute_feat();
    dest_effect();
}

void permanent_effects(object ob)
{
    ::permanent_effects(ob);
    dest_effect();
    return;
}

void reverse_permanent_effects(object ob)
{
    ::reverse_permanent_effects(ob);
    dest_effect();
    return;
}

void dest_effect()
{
    ::dest_effect();
    remove_feat(TO);
    return;
}
