#include <std.h>
#include <daemons.h>
inherit MONSTER;

int dlevel;

create() {
    	::create();
	set_name("hobgoblin");
	set_id( ({ "hobgoblin" }) );
	set_race("hobgoblin");
	set_gender("male");
	set_short("A smelly hobgoblin");
	set_long("A very smelly and ugly hobgoblin.\n");
	dlevel = random(3) + 6;
	set_level(dlevel);
	set_body_type("human");
  	set("aggressive",20);
  	set_alignment(3);
  	set_size(2);
   	set_stats("intelligence",7 + dlevel);
   	set_stats("wisdom",4);
   	set_stats("strength",13 + dlevel);
   	set_stats("charisma",3);
   	set_stats("dexterity",8);
   	set_stats("constitution",7);
	set_hd(dlevel, 8);
   	set_max_hp(17+(dlevel * (random(10) + 1)));
    	set_hp(query_max_hp());
   	set_max_level(7);
	set_wielding_limbs( ({ "right hand", "left hand" }) );
        	new("/d/common/obj/weapon/shortsword")->move(TO);
      	command("wield sword");
        	new("/d/common/obj/armour/leather")->move(TO);
      	command("wear leather");
	add_money("silver",random(5) * dlevel);
	add_money("copper",random(10) * dlevel);
	//set_exp(dlevel * 25);
   	set_exp(dlevel * 100);
    	set_emotes(2,({
		"Hobgoblin looks around alertly.\n",
		"Hobgoblin scratches himself absentmindedly.\n",
		"Hobgoblin eyes you warily.\n",
		"Hobgoblin growls.\n"
    	}),0);
}
