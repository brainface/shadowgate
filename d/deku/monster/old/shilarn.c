inherit "/std/barkeep";

create() {
    ::create();
    set_name("waitress");
    set_id(({"waitress","shilarn","restaurant waitress"}));
    set_short("Shilarn, restaurant waitress");
    set("aggressive", 0);
    set_level(10);
    set_long("She is ready to take your order.\n");
    set_gender("female");
    set_alignment(4);
    set("race", "human");
    set_hd(10,0);
   set_exp(10);
    set_max_hp(query_hp());
    set_max_sp(query_hp());
    set_sp(query_max_sp());
    set_mp(random(250));
    set_max_mp(query_mp());
    add_money("copper", random(200));
    set_skill("melee",90);
    set_body_type("human");
    set_currency("gold");

   set_menu(
        ({"mutton", "stew", "gruel", "hardroll", "water"}),
        ({ "food", "food", "food", "food", "water" }),
        ({ 10, 7, 5, 3, 1})
   );
   set_my_mess(
       ({
       "Best meal in the house!\n",
       "A common meal for foreigners.\n",
         "A poor man's meal.\n",
       "Some of a native hardroll.  Very dry!\n",
         "What refreshing water.\n"
       })
   );
   set_your_mess(
       ({
         "savors an excellent meal.\n",
       "slurps down a pot of stew.\n",
       "gags on the pasty mass.\n",
       "crunches down on a hardroll.\n",
         "chugs some refreshing water.\n"
        })
    );
    set_menu_short(
        ({
        "Mutton",
        "Stew",
        "Gruel",
        "Hardroll",
        "Water"
        })
    );
    set_menu_long(
        ({
        "A tasty looking plate of some really good food.\n",
        "An appetizing pot of stew.\n",
        "A plate of what looks like slop.\n",
        "A loaf of some really hardroll.\n",
          "A glass of refreshing water.\n"
   	})
    );
}
