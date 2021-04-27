#include <std.h>
inherit PARMOUR;

void create(){
	::create();
	set_name("%^BOLD%^%^CYAN%^Spl%^BLUE%^e%^CYAN%^nd%^BLUE%^i%^CYAN%^d S%^BLUE%^a%^CYAN%^sh %^BLUE%^o%^CYAN%^f th%^BLUE%^e %^CYAN%^W%^BLUE%^o%^CYAN%^rlds%^RESET%^");
	set_id(({ "sash", "sash of the worlds", "worlds sash", "world sash", "storage sash", "extradimensional sash" }));
	set_short("%^BOLD%^%^CYAN%^Spl%^BLUE%^e%^CYAN%^nd%^BLUE%^i%^CYAN%^d S%^BLUE%^a%^CYAN%^sh %^BLUE%^o%^CYAN%^f th%^BLUE%^e %^CYAN%^W%^BLUE%^o%^CYAN%^rlds%^RESET%^");
	set_obvious_short("%^BOLD%^%^CYAN%^fl%^BLUE%^o%^CYAN%^w%^BLUE%^i%^CYAN%^ng gl%^BLUE%^i%^CYAN%^tt%^BLUE%^e%^CYAN%^r%^BLUE%^i%^CYAN%^ng s%^BLUE%^a%^CYAN%^sh %^BLUE%^o%^CYAN%^f br%^BLUE%^i%^CYAN%^ght %^BLUE%^a%^CYAN%^z%^BLUE%^u%^CYAN%^r%^BLUE%^e%^RESET%^");
	set_long(
@AVATAR
%^BOLD%^%^CYAN%^This sash appears to be moving as if a soft glowing wind were within. The everflowing folds and twists of the sash give a voluminous impression. There certainly appears to be something within...

AVATAR
	);
	set_weight(5);
	set_value(5000);
	set_lore(
@AVATAR
%^BOLD%^%^BLUE%^The Splendid Sash of the Worlds is a rare and most sought after treasure. Only those of great merit or fortune could ever acquire such as this. Rumors speak of perhaps a half dozen such sashes in existence. Rumors of course tend to exaggerate.

%^BOLD%^%^BLUE%^The mystical properties of the sash have been deeply examined by those of great power. In the tome entitled "Grymoire of Artyfects in Powre" by the ancient Tsarveni Vizier Verriliu the Sighted is perhaps the most detailed such examination. The sash is a gateway to a pocket reality that resembles the Elemental Plane of Air. Anything placed within the sash hangs within this pocket reality by an azure string that disappears into forever. A wearer can reach within and feel many strings. Instinctively the wear knows which strings attach to which items. Tugging a string is quickly followed by a small gust of air that drops the item into the wearers hands.

%^BOLD%^%^BLUE%^The creation of these wondrous sashes is a mystery for all time. A rare few stories hint at a grand wizard of the Old Elven Realm. Perhaps the elves know and will not share their knowledge...

AVATAR
	);
	set_property("lore difficulty",25);
	set_max_internal_encumbrance(10);
	set_type("clothing");
	set_limbs(({ "waist" }));
	set_size(2);
	set_property("enchantment",1);
}


