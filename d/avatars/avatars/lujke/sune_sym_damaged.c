// /d/magic/symbols/sune_symbol.c

#include <std.h>

inherit "/d/magic/symbols/holy_symbol.c";

#define GEMS ({"%^RESET%^%^RED%^ruby%^RESET%^","%^BOLD%^%^RED%^carnelian%^RESET%^","%^BOLD%^%^RED%^fire opal%^RESET%^"})
#define METALS ({"%^BOLD%^%^WHITE%^silver","%^YELLOW%^gold","%^ORANGE%^copper","%^YELLOW%^bronze","%^CYAN%^steel","%^BOLD%^%^WHITE%^platinum","%^BOLD%^%^WHITE%^titanium","%^BOLD%^%^CYAN%^mithril","%^BOLD%^%^BLUE%^electrum"})
#define TYPES ({"bracelet","ring","amulet"})

string gem;
string jewelry;
string metal;
string GOD = "%^RESET%^%^RED%^Sune%^RESET%^";

void create(){
   ::create();
   if(!gem)
      gem = GEMS[random(sizeof(GEMS))];
   if(!jewelry)
      jewelry = TYPES[random(sizeof(TYPES))];
   if(!metal)
      metal = METALS[random(sizeof(METALS))];
   set_id(({"holy symbol","symbol","helm_holy_symbol",jewelry,gem+" "+jewelry}));
   set_name(gem+" "+jewelry);
   set_short("holy symbol");
   set_long("This is a holy symbol.");
}

void init(){
   string ldesc,tmp;
   ::init();
   switch(jewelry){
      case "ring": ldesc = "Fashioned from "+metal+"%^RESET%^, this "+
         "ring looks solid and strong.  The band is polished smooth, "+
         "a simple but effective design.  A well-cut "+gem+" is mounted into "+
         "the center of the band.  Within the "+gem+" the holy symbol of "+
         ""+GOD+" has been carved.  A sacred aura almost seems to "+
         "radiate around the ring.\n";
         set_short(""+metal+" ring%^RESET%^");
         add_id("ring");
         set_limbs(({"right hand"}));
         break;
      case "bracelet": ldesc = "Fashioned from "+metal+"%^RESET%^, "+
         "this bracelet looks solid and strong.  The cuff bracelet "+
         "is polished smooth, a simple but effective design.  A "+
         "well-cut "+gem+" is mounted into the center of the bracelet.  "+
         "Within the "+gem+" the holy symbol of "+GOD+" has been "+
         "carved.  A sacred aura almost seems to radiate around "+
         "the bracelet.\n";
         set_short(""+metal+" bracelet%^RESET%^");
         add_id("bracelet");
         set_limbs(({"right arm"}));
         break;
      case "amulet": ldesc = "Fashioned from "+metal+"%^RESET%^, "+
         "this amulet hangs from a chain and looks solid and "+
         "strong.  The amulet is polished smooth, a simple but "+
         "effective design.  A well-cut "+gem+" is mounted into the center "+
         "of the amulet.  Within the "+gem+" the holy symbol of "+
         ""+GOD+" has been carved.  A sacred aura almost seems "+
         "to radiate around the amulet.\n";
         set_short(""+metal+" amulet%^RESET%^");
         add_id("amulet");
         set_limbs(({"neck"}));
         break;
      default: break;
   }
   tmp = "%^RESET%^%^RED%^                          R@   @    @R  @@    @@@@@\n"+
"                @     B@         @B        @@@@     @\n"+
"              @     R@@@B     @B @@#@@@     @   @    @\n"+
"              @    @    @    @   @@        R^        @\n"+
"       @R  #@@     @    @    @        R    @    @    @@     BB\n"+
"     R     @B@      @    @    R   ^ @    B   @B     @R  @     B\n"+
"     @   @    @       @B@@B@    B@@     @ B@       @     #    @\n"+
"    R    @     @         B@@     @@@@@@@BR@      @\n"+
"          @      B@    @                    B@@@        R@    @\n"+
"     B     @@B @@BB@@@           @             @B@B@@B@@      @@B\n"+
"   @ @@             @            @               @           @@@ @B\n"+
" @  @  @@          @             @               @         B    @  R\n"+
" @   @   @R@@@@@@@@@            @ @              @@@@@@@B@         B\n"+
" @    @@@@@B       R           R   @            @#        @@@@@@   @\n"+
" @B@            @R  @        @@     @@    @  @  @ @@@             @\n"+
"@B  @R@@@  @@@B@@  @    @RBB          @R@ @  @  @   @  @         @@\n"+
"             @@   @      @   %^RESET%^        %^RESET%^%^RED%^    @@  ^B  @   @@  B@   @BR  @\n"+
"@ @@      B@B    @   B %^RESET%^ | %^GREEN%^ @@@       @@@       %^RESET%^%^RED%^@  @     B@B    R@  @\n"+
"@    @@@@      @    @  %^RESET%^ | %^GREEN%^  @@@     @@@   %^RESET%^|%^RED%^@    @   @              B\n"+
" @           @    BR  @%^RESET%^ |                    %^RED%^ @  B     @@         @\n"+
" @@@@@^ @@B@     @   @  %^RESET%^        ^ ^       |%^RED%^B   B  @B       @@R  @@ @\n"+
"     @B       @@     @  @%^RESET%^\\               / %^RED%^ R    @   @@B         B   @\n"+
"@  R       @@ @     R   @  %^RESET%^\\ %^BOLD%^%^RED%^  @@@@@  %^RESET%^  /%^RED%^    B     R   B   R@       @\n"+
"  @      @@   @     @   @  @%^RESET%^\\  %^BOLD%^%^RED%^ @@@ %^RESET%^  / %^RED%^    @    B   @      @      @\n"+
" @     @@   @@      @   @    B%^RESET%^\\      /  %^RED%^    B    @    @       @     R\n"+
"R    @  @  @ @      @   @    @  %^RESET%^\\__/%^RED%^        B    @    @B@@    @@@   @\n"+
"@   @  @  @  @      @   @    @              @    B     @  @    @ @  @\n"+
"@   @ R      B                @       @          @     R   B   @ R  B\n"+
"R   B @  @   @       @   @            R    @    B     @    R     @  B\n"+
" @  @ R  @                B    B     @    @     B     @    B     @  @\n"+
"  @@ @@  @    @       @    @    @              @     R         @B  B\n"+
"      @   B    B       @    R    @  B    @     @          @   @@  @\n"+
"       B   @    @       @    B   #  @   @     @     @   @@    @ @\n"+
"           @ @R  @       @    @        @     B     @   @     @\n"+
"            @   @@B@       B   @  @   @    @R     @@@B     @\n"+
"               @@   @@      @@  B @B  @   @     B       @@\n"+
"               @@@@@   @@     @  @B@ @  @@    R@RR@#@@@B\n"+
"                          R@   R  B@@  R    @\n"+
"                             @  B @   @  B@\n"+
"                               B @@@ @@@\n"+
"                                RR@@@R\n"+
"                                 @@@\n%^RESET%^";
   set_long(""+ldesc+""+tmp+"");
}
