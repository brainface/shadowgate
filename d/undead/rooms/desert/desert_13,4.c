#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_12,4",
        "east"      :DES+"desert_13,5",
        "south"     :DES+"desert_14,4",
        "west"      :DES+"desert_13,3"
             ]));
}