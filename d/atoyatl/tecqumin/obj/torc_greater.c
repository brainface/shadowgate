#include <std.h>
#include <clock.h>

inherit ARMOUR;
int uses;
int head1, head2;

void create()
{
    string* heads, head_shorts;
    heads = ({ "a %^BOLD%^%^GREEN%^s%^RESET%^%^GREEN%^e%^BOLD%^rp"
               + "%^RESET%^%^GREEN%^e%^BOLD%^nt%^RESET%^ with a"
               + " %^BOLD%^%^RED%^p%^BLUE%^l%^RED%^u%^BLUE%^m%^RED%^e"
               + " %^RESET%^of %^BOLD%^%^RED%^f%^BLUE%^ea%^RED%^th"
               + "%^BLUE%^e%^RED%^rs%^RESET%^", "a%^BOLD%^%^WHITE%^"
               + " snarling %^BOLD%^%^BLACK%^j%^RESET%^a%^BOLD%^"
               + "%^BLACK%^g%^RESET%^%^BLUE%^u%^BOLD%^%^BLACK%^ar",
               "a hero %^BOLD%^%^YELLOW%^wreathed %^RESET%^in"
               + " %^BOLD%^%^RED%^f%^YELLOW%^l%^RESET%^%^RED%^a"
               + "%^BOLD%^me%^RESET%^", "a %^BOLD%^%^GREEN%^tr"
               + "%^RESET%^%^GREEN%^ee %^BOLD%^sp%^RESET%^%^GREEN%^"
               + "i%^BOLD%^r%^RESET%^%^GREEN%^i%^BOLD%^t%^RESET%^",
               "a %^BOLD%^%^YELLOW%^sun G%^RESET%^%^ORANGE%^o"
               + "%^BOLD%^d%^RESET%^" });
    head_shorts = ({ "%^BOLD%^%^GREEN%^serpent%^RESET%^",
                     "%^BOLD%^%^BLACK%^j%^RESET%^a%^BOLD%^%^BLACK%^g%^RESET%^"
                     + "%^BLUE%^u%^BOLD%^%^BLACK%^ar", "%^ORANGE%^hero%^RESET%^",
                     "%^GREEN%^tree", "%^BOLD%^%^YELLOW%^sun" });
    ::create();
    head1 = random(sizeof(heads));
    head2 = random(sizeof(heads));
    while (head1 == head2) {
        head2 = random(sizeof(heads));
    }
    set_name("Golden torc");
    set_id(({ "torc", "golden torc", "tecqumin torc", "tecqumin golden torc", "golden tecqumin torc" }));
    set_short("%^BOLD%^%^YELLOW%^G%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^ld"
              + "%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^n " + head_shorts[head1]
              + " and " + head_shorts[head2] + " %^BOLD%^%^YELLOW%^T%^RESET%^%^ORANGE%^o"
              + "%^BOLD%^%^YELLOW%^rc %^RESET%^of the %^CYAN%^Tecqumin%^RESET%^");
    set_obvious_short("A %^BOLD%^%^YELLOW%^g%^RESET%^%^ORANGE%^o%^BOLD%^"
                      + "%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^n "
                      + head_shorts[head1] + " and " + head_shorts[head2]
                      + " %^BOLD%^%^YELLOW%^t%^RESET%^%^ORANGE%^o%^BOLD%^%^YELLOW%^rc%^RESET%^");
    set_long("This %^BOLD%^%^YELLOW%^r%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^"
             + "g%^RESET%^%^ORANGE%^i%^BOLD%^%^YELLOW%^d g%^RESET%^%^ORANGE%^o"
             + "%^BOLD%^%^YELLOW%^ld%^RESET%^%^ORANGE%^e%^BOLD%^%^YELLOW%^n"
             + " %^RESET%^neck ring is of fine quality. The two bulbs at the ends"
             + " come close to meeting each other at the front. One is fashioned"
             + " into the head of " + heads[head1] + ", and the other is "
             + heads[head2] + ". They seem to stare into each others' eyes.\n");
    set_lore("The priests of the Tecqumin wore torcs that indicated their"
             + " allegiance to one or another of the gods that they worshipped."
             + " Some of them were blessed with the powers of their particular gods."
             + " The high priests were rumoured to be gifted with torcs carrying"
             + " enchantments relating to more than one god.");
    set_weight(3);
    set_size(-1);
    set_type("clothing");
    set_limbs(({ "neck", }));
    set_ac(0);
    while ((int)TO->query_property("enchantment") != 6) {
        TO->remove_property("enchantment");
        TO->set_property("enchantment", 6);
    }
    switch (head1) {
    case 0:
        //serpent
        set_item_bonus("wisdom", 6);
        break;

    case 1:
        //jaguar
        set_item_bonus("dexterity", 6);
        break;

    case 2:
        //flame hero
        set_item_bonus("fire resistance", 30);
        break;

    case 3:
        //tree spirit
        set_item_bonus("survival", 30);
        break;

    case 4:
        //sun god
        set_item_bonus("caster level", 3);
        break;
    }
    switch (head2) {
    case 0:
        //serpent
        set_item_bonus("wisdom", 6);
        break;

    case 1:
        //jaguar
        set_item_bonus("dexterity", 6);
        break;

    case 2:
        //flame hero
        set_item_bonus("fire resistance", 30);
        break;

    case 3:
        //tree spirit
        set_item_bonus("survival", 30);
        break;

    case 4:
        //sun god
        set_item_bonus("caster level", 3);
        break;
    }
    set_value(0);
    set_wear((: TO, "wear_it" :));
    uses = 2;
    set_overallStatus(220);
}

int wear_it(string str)
{
    tell_object(ETO, "You drag the ends of the torc apart far enough to get it"
                + " round your neck. When you let go, they spring back together. You feel"
                + " a sense of acceptance from the %^CYAN%^Tecqumin%^RESET%^ ancestor"
                + " %^BOLD%^%^CYAN%^spirits%^RESET%^, who recognise your great deeds"
                + " against the %^MAGENTA%^U%^BLUE%^nf%^MAGENTA%^e%^BLUE%^tt%^MAGENTA%^e"
                + "%^BLUE%^r%^MAGENTA%^e%^BLUE%^d");
    tell_room(environment(ETO), ETO->query_cap_name() + " fastens the "
              + query_name() + " around " + ETO->query_possessive() + " neck.", ETO);
    return 1;
}

void init()
{
    ::init();
}
