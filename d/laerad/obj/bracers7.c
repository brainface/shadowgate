//changed to common inherit by Circe to help with maintenance and balance.  12/14/03
//added lore - Circe 5/28/04
#include <std.h>
inherit "/d/common/obj/armour/bracers.c";

void create(){
    ::create();
//    set_short("Bracers of Defense");
    set_value(3500);
//    set_ac(3); taken care of in the inherit
    set_property("enchantment",4);
    set_lore("These bracers are known as bracers of defense, as they "+
       "create a magical force around the wearer that makes him "+
       "harder to hit.  They were once called 'Bracers of "+
       "Repelling' by the magi who created them, but since they have "+
       "become more widespread, the common folk have taken to calling "+
       "them bracers of defense after the most obvious benefit they "+
       "have.  The famous magical artificer Karionflindus "+
       "Ficklefingers, a gnome living in the 1st century SG, is "+
       "said to have created the prototype for today's bracers.");
}
