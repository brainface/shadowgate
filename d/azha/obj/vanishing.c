// Bag of Vanishing
// Thorn@ShadowGate
// 970309
// Town of Azha
// vanishing.c

#include <std.h>

inherit "/std/bag_logic";

string short;



void create() {
    set_id( ({ "pouch","bag of vanishing","bag","belt pouch" }) );
    set_name("belt pouch");
    set("short", "a small belt pouch");
    set_weight(1);
    set_long(
@AZHA
..This is a rather normal-looking small pouch held closed by some
purse strings.  Besides the fact that it looks almost brand new,
there is nothing special about it.
AZHA
    );
    set_value(1);
    set_cointype("silver");
    set_max_internal_encumbrance(50);
}

init()
{
  add_action("tug", "tug");
  add_action("loosen", "loosen");
}

int tug(string str) 
{
  if(str != "purse strings") return 0;
if(!TP->is_class("thief")) return 0;
  if(random(100) < 5) {
    write("The bag is sucked into another plane with its contents!");
    if(!TO->remove()) destruct(TO);
    return 1;
  }
  write("The bag seems to disappear!");
  short = query_short();
  set_short(0);
  return 1;
}

int loosen(string str) 
{
  if(str != "purse strings") return 0;
if(!TP->is_class("thief")) return 0;
  write("You loosen the strings and the belt pouch is again visible");
  set_short(short);
  return 1;
}

