
// Rooms by the house of Svaha

#include <std.h>
inherit ROOM;

void create() {
::create();

set_property("light", 2);
set_property("indoors", 0);

set_short("%^ORANGE%^The Cicatrice Desert");
set_long("%^ORANGE%^Finally, a breath of ocean air, a glimpse of green.  Ahead of you lies
Licorne Beach.  Palm trees sway in the distance, long grasses bend in the
breeze, you made it. You hope to find more hospitable treatment in the 
near future.");

set_smell("default", "%^CYAN%^The smell of brine catches the breeze and 
makes your mouth water.");
set_listen("default", "%^CYAN%^Birds cry, waves crash, wind whistles, 
these are the sounds that make up your sanity.");


set_exits
(([
"north" : "/d/khalian/stresa/cicatrice/room99",
"south" : "/d/khalian/stresa/licorne/18",
"east" : "/d/khalian/stresa/licorne/16",
"west" : "/d/khalian/stresa/cicatrice/room108"
]));


set_items
(([
"ocean" : "Clean aqua waves crash upon the shore.  The ocean gives life if
only you can get to it.",
"trees" : "Tall, twenty foot palm trees sway in the breeze, the large
canopy like leaves provide a welcome respite from the unending glare.",
"grasses" : "Long two foot grasses bend in the breeze like ocean waves of
emerald green"
]));

}
