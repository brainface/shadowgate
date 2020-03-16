#include <std.h>
#include "../vale.h"
inherit BORDER;

void create()
{
   ::create();
   set_long(
   "The grass is taller here and some scrub brushes have grown along the edges"+
   " of the vale and the forest. The forest rings this little vale, and almost"+
   " seems to be protecting it and keeping it safe from the rest of the world."+
   " The trees are growing tall into the sky and the sun makes the leaves look"+
   " like brilliant emeralds as the light passes through them. The branches"+
   " sway gently in the slight breeze. The entire forest seems to be filled with"+
   " a sense of new life. You can't see too deeply into it, however, because"+
   " the trees are growing so close together. Directly to the west is one of the"+
   " huts that are scattered about the vale."
   );
   set("night long",
   "You've come to the edge of the vale, which is marked by the forest that rings"+
   " it. You hear strange rustling sounds coming from within it as the animals"+
   " move through the brushes. You notice that the grass is taller here and some"+
   " scrub brushes are growing up along the border. The trees are dark and almost"+
   " forboding, but you don't sense any evil coming from them. Directly west of you"+
   " is one of the huts that are scattered about the vale."
   );
   set_exits(([
   "north" : ROOMS+"v50",
   "south" : ROOMS+"c40",
   "east" : ROOMS+"v48",
   ]));
}