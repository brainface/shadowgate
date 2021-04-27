#include <std.h>;
#include "../sorrowsong.h"
inherit ARMOUR;

void create(){
    ::create();
    set_name("shoulder plates");
    set_id(({"shoulderplates","shoulder plates","plates","foehammers gift" "foehammer","gift","shoulders"}));
    set_obvious_short("%^BOLD%^%^BLACK%^Sp%^RED%^i%^BLACK%^%^BLACK%^ked Shoulderplates%^RESET%^");
    set_short("%^RESET%^%^RED%^Foehammer's Gift%^RESET%^");
    set_long("%^RESET%^%^RED%^These shoulder plates are composed of a %^RESET%^darkened steel%^RED%^. They seem to have endured numerous battles as some of the spikes have"
             " been badly damaged, leaving the spikes even more %^BOLD%^%^BLACK%^gruesome%^RESET%^%^RED%^ in appearance. After removing your eyes from the gruesome spikes"
             " and inspecting closer you see small %^BOLD%^%^WHITE%^etchings%^RESET%^%^RED%^ along the two foot length of the shoulder-plates. These etching seem to shift" 
             " when the wearer walks, depicting different scenes of war. No matter the movements of the wearer a %^BOLD%^%^RED%^blazing%^RESET%^%^RED%^ sword can be seen within" 
             " the background of the shoulder-plates.%^RESET%^");
    set_lore("%^RESET%^%^RED%^Little is known about %^BOLD%^%^RED%^Foehammer's Gift%^RESET%^%^RED%^, except"
             ",that they were a gift from Lord Tempus to a highly respected warrior or priest of his."
             " History suggests that they have been lost numerous times in battle and offer praise to Tempus without"
             "a Tempusian even having to don them.");
    set_property("lore difficulty",16);
    set_weight(5);
    set_limbs(({"neck", "left arm", "right arm"}));
    set_type("clothing");
    set_value(4000);
    set_property("enchantment",5);
    set_item_bonus("endurance",1);
    set_item_bonus("craft,armorsmith",1);
    set_item_bonus("damage resistance",1);
    set_item_bonus("wisdom",-2);
    set_wear((:TO, "extra_wear":));
    set_remove("%^BOLD%^%^RED%^The cries of battle recede as you remove the shoulder-plates.");
}
int extra_wear() {

    tell_room(EETO, "%^BOLD%^%^RED%^Drums echo in the distance as "+ETOQCN+" wears his shoulder-plates%^RESET%^.",ETO);
    tell_object(ETO,"%^BOLD%^%^RED%^Cries of battle echo about you%^RESET%^.");
    return 1;
}
