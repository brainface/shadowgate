//forest96.c

#include <std.h>
#include "./forest.h"

inherit BFOREST;

void create(){
    ::create();
    set_exits(([
                "south":TFOREST"forest95",
                "northwest":TFOREST"forest97",
                ]));
}

