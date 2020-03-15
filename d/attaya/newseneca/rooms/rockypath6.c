//rockypath6.c - ~Circe~ 6/10/08 for new Seneca
#include <std.h>
#include "../seneca.h"

inherit RPATH;

void create(){
   ::create();
   set_long(::query_long()+"The wall of %^ORANGE%^bedrock %^RESET%^"+
      "rises to the north here, blocking off most of the view of "+
      "the city.  All that is visible in that direction are the "+
      "towering %^BOLD%^co%^MAGENTA%^q%^WHITE%^ui"+
      "%^BLACK%^n%^WHITE%^a walls%^RESET%^ bordering the southern "+
      "edge of Seneca.  In all other directions, however, there is "+
      "a stunning view of the %^BOLD%^%^BLUE%^ocean%^RESET%^.  The "+
      "path winds westward and down, leading to the %^YELLOW%^b"+
      "%^WHITE%^e%^RESET%^a%^YELLOW%^c%^WHITE%^h%^RESET%^.\n");
   set_exits(([
      "east" : ROOMS"rockypath5",
      "west" : ROOMS"rockypath7"
   ]));
}