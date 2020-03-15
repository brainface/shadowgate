#include <std.h>
inherit OBJECT;

void create() {
   ::create();
   set_id(({"map","map fragment","fragment of a map","fragment of an old map","old map"}));
   set_name("map");
   set_short("fragment of an old map");
   set_long("%^ORANGE%^This crumpled parchment appears to be a map of something, though it is torn along two "
"edges, as if it is only one part of a whole.  Maybe it leads to pirate treasure!  You should %^WHITE%^read "
"%^ORANGE%^it.%^RESET%^");
   set_weight(0);
   set_value(0);
   set("read","\n%^ORANGE%^   .-------------------------,\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^/\n"
"%^ORANGE%^   |%^BLUE%^00000000000000%^CYAN%^%^BOLD%^~%^RESET%^%^BLUE%^0000000000%^ORANGE%^\\\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^{\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^/\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^)\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^\\\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^/\n"
"%^ORANGE%^   |%^BLUE%^0000000%^YELLOW%^z%^RESET%^%^BLUE%^00000000000000000%^ORANGE%^}\n"
"%^ORANGE%^   |%^BLUE%^0000%^GREEN%^w%^BLUE%^00000000000000000000%^ORANGE%^\\\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^/\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^)\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000%^CYAN%^%^BOLD%^~%^RESET%^%^BLUE%^00000%^ORANGE%^\\\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^}\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^\\\n"
"%^ORANGE%^   |%^BLUE%^0000000000000000000000000%^ORANGE%^/\n"
"%^ORANGE%^   `-\\___.--`\\__/'.__.---'\\/~`\n\n"
" %^YELLOW%^z%^RESET%^%^ORANGE%^  here be many undead\n"
" %^GREEN%^w%^RESET%^%^ORANGE%^  here be the dagger straits\n\n");
}


