#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "north"     :DES+"desert_13,10",
        "east"      :DES+"desert_14,11",
        "west"      :DES+"desert_14,9"
             ]));
}