#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,13",
        "east"      :DES+"desert_13,14",
        "south"     :DES+"desert_14,13",
        "west"      :DES+"desert_13,12"
             ]));
}