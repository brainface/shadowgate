// Pargin Ferry East on the Wadi
// al-Emir, Verhedin Province
// Thorn@ShadowGate
// 14 June 2000
// pargineast.dock.c

#include <std.h>

inherit "/d/verhedin/virtual/wadi/dock.c";

int is_virtual() { return 1; }
int is_water() { return 1; }
int is_dock() { return 1; }

void create() {
  set_indoors(0);
  ::create();
  set_light(2);
  set_short("Pargin Ferry East, Verhedin Province");
  set_long(
@THORN
%^BOLD%^Pargin Ferry East, Verhedin Province%^RESET%^
  Pargin Ferry is a set of two docks that allows a ferry
boat service to transport goods and passengers across the
Wadi al-Emir at a narrow bend.  Pargin Ferry is very
important to the Empire as it connects the Bay Highway on
the east side to the Ninor Road on the west side.  Because
of this, Pargin Ferry is as busy as any city dock, and the
ferries run constantly.
  To the east, you can see some buildings that make up the
small village of Pargin Ferry and in the distance, you see
the Bay Highway that leads to Elbarin Province.
THORN
);
  set_exits(([
        "east" : "/d/verhedin/pargin/street1"
  ]));
  set_smell("default","Various scents assault your nose from the exotic cargoes.");
  set_listen("default","You hear constant loading and unloading of boats around you.");
}
