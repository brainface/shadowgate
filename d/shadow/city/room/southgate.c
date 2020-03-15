#include <std.h>
#include <daemons.h>
inherit CVAULT;

void create() {
    set_monsters( ({ "/d/shadow/city/mon/city_guard" }), ({roll_dice(1,4)+2}) );
    ::create();
    set_property("light",2);
    set_property("indoors",1);
    set_terrain(STONE_BUILDING);
    set_travel(PAVED_ROAD);
    set_short("South Gates of Shadow.");
    set_long(
"%^BOLD%^%^GREEN%^You are at the South Gates of Shadow.%^RESET%^
%^RESET%^%^GREEN%^You stand by a Portcullis. It is a stone structure, with strong steel-bound %^CYAN%^gates,%^GREEN%^ and %^CYAN%^tower%^GREEN%^ on each side. There are several guard posts here, and they seems to be busy patroling the area. The city of shadow lies north of you, through the %^CYAN%^arch%^MAGENTA%^w%^CYAN%^ay.%^RESET%^
"
        );
    set_exits( ([
                    "south":"/d/darkwood/room/road1",
                    "north":"/d/shadow/city/room/southcross"
                    ]) );
    set_items(([
                   "gate" : "Tall wooden gates standing open to visitors.",
                   "archway":"High archways lead into the walls around the city.",
                   "tower":"The towers loom high above the walls.",
                   "north":"The road heads north into the city."
                   ]));
    set_smell("default","You smell a brisk odor of oak from the gates.");
    set_listen("default","You hear the sounds of bustling people.");
    set_door("gate", "/d/darkwood/room/road1","south",0);
    set_lock_description("gate","lock","This is a huge bar across the giant door.");
    set_door_description("gate","These are two huge solid wooden doors that come together in the middle. They are bound together with giant dwarven forged iron bands.");

    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
}

void reset() {
    ::reset();
    set_open("gate",((string)EVENTS_D->query_time_of_day() != "night"));
    set_locked("gate", 0);
}


