#include <std.h>

inherit DAEMON;

cmd_offerall()
{
    object* inv, * living;
    int i, s, wt;

    inv = all_inventory(ETP);
    living = all_living(ETP);
    inv = inv - living;
    s = sizeof(inv);

    if (TP->query_bound()) {
        TP->send_paralyzed_message("info", TP);
        return 1;
    }
    for (i = 0; i < s; i++) {
        wt = TP->query_max_internal_encumbrance();
        if (inv[i]->query_property("monsterweapon")) {
            inv[i]->remove();
            continue;
        }
        if (!inv[i]->get()) {
            continue;
        }
        if (inv[i]->query_weight() > wt) {
            tell_object(TP, "You can't lift the " + inv[i]->query_name() + ".");
            continue;
        }
        if (inv[i]->query_property("nosell")) {
            tell_object(TP, "You can't offer " + inv[i]->query_name() + ", as it is kept object.");
            continue;
        }

        if (inv[i]->query_property("no offer") || inv[i]->query("not living")) {
            tell_object(TP, "The gods will not accept that gift.\n");
            continue;
        }

        if (inv[i]->query_property("plot_item")) {
            tell_object(TP, "The gods will not accept that gift.\n");
            continue;
        }

        if ((time() - (int)inv[i]->query_property("died time") < 600) && !TP->query_property("monsteroffer")) {
            tell_object(TP, "That object has recently been through a player death. You can not offer it yet.\n");
            continue;
        }
        if (inv[i]->query_value()) {
            TP->add_hp(random(2) + 1);
        }
        inv[i]->remove();
    }
    tell_object(TP, "You offer everything in the room and bolts of lightning crash down around you.");
    tell_room(ETP, "Lightning crashes down around you as " + TPQCN + " offers everything in the room.", TP);
    return 1;
}

int help()
{
    write(
        "
%^CYAN%^NAME%^RESET%^

offerall - clean the room

%^CYAN%^DESCRIPTION%^RESET%^

This command will offer everything that's on the ground in front of you.

If you wish to protect an object from acciental offering, use <keep> command, or use <bury> command instead.

Using offer command restores 1-2 hp.

%^CYAN%^SEE ALSO%^RESET%^

bury, offer, pkilling, get, drop
");
    return 1;
}
