#include <std.h>
#include "../defs.h"
inherit INH+"lower";

void create(){
   ::create();
   set_long("%^BOLD%^%^BLACK%^An underground mining tunnel%^RESET%^\n"+ ::query_long() +"%^BLUE%^  The tunnel "
"leads away to the east and southwest into darkness.%^RESET%^\n");
   set_exits(([
     "southwest":MINES"lower1c",
     "east":MINES"lower1e",
   ]));
}
