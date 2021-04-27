#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("%^BOLD%^%^GREEN%^Sphere of the Cosmos%^RESET%^");
    set_id(({"sphere","sphere of the cosmos","cosmos sphere"}));
    set_short("%^BOLD%^%^GREEN%^Sphere of the Cosmos%^RESET%^");
      set_obvious_short("glass sphere");
    set_long("This is a perfectly smooth glass like material sphere. It appears "
   "to contain a purplish smokey substance. Although "
	"it is made of a very strong substance, it may be possible to smash "
        "it against a hard enough surface."
);
    set_weight(1);
}
void init() {
    ::init();
    add_action("break_func","smash");
}
int break_func(string str) {
    if( !str || str != "sphere") {
	notify_fail ("Smash what?\n");
        return 0;
    }
    if (TP->query_bound() || TP->query_unconscious()) {
       TP->send_paralyzed_message("info",TP);
       return 1;
    }
//
   if(TP->query_paralyzed())
	   return notify_fail(TP->query_paralyze_message()+"\n");
if(ETP->query_property("no teleport")) {
notify_fail("You fail to complete the action successfully!\n");
return 0;
}
    message ( "my_action",
	"%^BOLD%^%^CYAN%^You smash the sphere and become "
      "enveloped into an alluring fog!\n"
      "%^YELLOW%^As the fog dissipates you find you haven't moved!  "
      "What poor luck to have only ended up with a faulty one!%^RESET%^"
    ,TP);
    message ( "other_action",
	"%^BOLD%^%^CYAN%^"+TPQCN+" smashes a sphere on the ground and "
	"is briefly enveloped in smoke, before reappearing!%^RESET%^"
    ,environment(TP),TP);
    TO->remove();
    return 1;
}
