#include "../../undead.h"

inherit INH+"desert_one.c";

void create() 
{
    ::create();

    set_exits(([
        "east"      :DES+"desert_0,5",
        "south"     :DES+"desert_1,4",
        "west"      :DES+"desert_0,3"
             ]));
}