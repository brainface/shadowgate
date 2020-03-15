#include <std.h>

inherit OBJECT;

int duration, isLit;

#define SCOLS (["deep purple" : ({"%^BOLD%^%^MAGENTA%^", "%^MAGENTA%^"}),\
"deep blue" : ({"%^BLUE%^", "%^BOLD%^%^BLUE%^"}),\
"emerald green" : ({"%^GREEN%^", "%^BOLD%^%^GREEN%^"}),\
"flaming red" : ({"%^RED%^", "%^BOLD%^%^RED%^"}),\
"brilliant yellow" : ({"%^YELLOW%^", "%^BOLD%^%^YELLOW%^"}),\
"midnight black" : ({"%^BOLD%^%^BLACK%^"}),\
"snow white" : ({"%^BOLD%^%^WHITE%^"}),\
"powder blue" : ({"%^CYAN%^", "%^BOLD%^%^CYAN%^"}), ])

string SCOL, StoneColor;


void create() 
{
    string *Cols;
    int x;
    ::create();
    Cols = keys(SCOLS);
    StoneColor = Cols[random(sizeof(Cols))];
    
    x = random(sizeof(SCOLS[StoneColor]));
    SCOL = "%^RESET%^" + SCOLS[StoneColor][x];
    
    set_id( ({ "stone", "lightstone", "light stone", 
    StoneColor+" stone"}) );
    set_name("a "+StoneColor+ " stone");

    set_obvious_short(SCOL+"A "+StoneColor+" stone%^RESET%^");

    set_short(SCOL +" A "+StoneColor+" l%^BOLD%^%^YELLOW%^i"+SCOL+
    "ghtst%^BOLD%^%^YELLOW%^o"+SCOL+"n%^BOLD%^%^YELLOW%^e%^RESET%^");
    
    set_long((:TO, "mylong":));
    set_weight(0);

    set_lore("%^BOLD%^%^WHITE%^This small stone "+
    "is known as a lightstone. They are found often among "+
    "magi who find them to be much easier to carry "+
    "than a bulky lantern. Some of them "+
    "have been known to last forever, but most of them "+
    "will eventually fade out permenantly.%^RESET%^");

    set_property("lore difficulty", 15);
    //somewhere between 5 - 10 hrs of use - heartbeats are approximately every 2 seconds - Saide
    duration = 9000 + random(9001);
    if(!random(25)) duration = -1;
    isLit;
}

void make_greater() { duration = -1; }

string mylong()
{
    string desc;
    desc = SCOL+"This "+StoneColor+" stone is "+
    "tiny and almost perfectly smooth. It weighs nothing and "+
    "feels almost as if it is hollow inside. Strangely it also "+
    "feels quite strong and durable. It is slightly "+
    "warm to the touch and gazing at it you find "+
    "it to be oddly capitivating, almost entrancing.%^RESET%^";
    if(!isLit)
    {
        desc += SCOL+" You are able to sense "+
        "that you can %^BOLD%^%^WHITE%^light"+SCOL+
        " it at will, to use the magic "+
        "contained within.%^RESET%^";
    }
    if(isLit) 
    {
        desc += SCOL+" You are able to sense "+
        "that you can %^BOLD%^%^BLACK%^darken%^BOLD%^"+
        SCOL+" it at will";
        if(duration == -1) desc += ".";
        if(duration != -1) 
        {
            desc += SCOL+", to preserve "+
            "the magic contained within.%^RESET%^";
        }
        desc += SCOL+" It is "+
        "%^BOLD%^%^YELLOW%^glowing "+SCOL+
        "softly.%^RESET%^";
    }
    return desc;
}

void init()
{
    ::init();
    if(living(ETO)) 
    {
        add_action("douse","darken");
        add_action("light", "light");
    }
}

void darken()
{
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    TO->set_heart_beat(0);
    TO->remove_property("added short");
    tell_object(ETO, TO->query_short()+"%^BOLD%^%^YELLOW%^ "+
    "darkens suddenly!%^RESET%^");
    if(EETO->is_room())
    {
        if(ETO->query_invis()) 
        {
            tell_room(EETO, "%^BOLD%^%^BLACK%^A light source "+
            "suddenly goes out!%^RESET%^", ETO);
        }
        else 
        {
            tell_room(EETO, TO->query_short()+"%^BOLD%^%^BLACK%^ "+
            "carried by "+ETOQCN+"%^BOLD%^%^BLACK%^ darkens "+
            "suddenly!%^RESET%^", ETO);
        }
    }	
    ETO->set_property("light", -3);	
    isLit = 0;
}


int move(mixed dest) 
{
    int x;

    if (objectp(ETO))
    {
        if(living(ETO) || ETO->is_room())
        if(isLit) 
        {
            darken();
        }
    }
    x = ::move(dest);
    if (objectp(ETO))
    {
        if(living(ETO) || ETO->is_room())
        if(isLit) ETO->set_property("light", 2);
    }
    return x;
}


void remove() 
{
    if (objectp(ETO))
    {
        if(isLit) 
        {
            darken();
        }
    }
    return ::remove();
}

int light(string str)
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!stringp(str)) return 0;
    if(TO != present(str, ETO)) return 0;
    if(isLit) 
    {
        tell_object(ETO, TO->query_short()+"%^BOLD%^%^YELLOW%^ is already "+
        "lit, you should %^BOLD%^%^BLACK%^darken%^BOLD%^%^YELLOW%^"+
        " it first.%^RESET%^");
        return 1;
    }
    if(duration < 1 && duration != -1) 
    {
        tell_object(ETO, TO->query_short()+"%^BOLD%^%^YELLOW%^ fails to "+
        "respond to your touch, as if its magic has been exhausted.%^RESET%^");
        return 1;
    }
    else
    {
        tell_object(ETO, TO->query_short()+"%^BOLD%^%^YELLOW%^ flares to life, "+
        "offering a soft glow!%^RESET%^");
        if(EETO->is_room()) 
        {
            if(ETO->query_invis())
            {
                tell_room(EETO, "%^BOLD%^%^YELLOW%^A light source "+
                "suddenly flares to life!%^RESET%^", ETO);
            }	
            else 
            {
                tell_room(EETO, TO->query_short()+"%^BOLD%^%^YELLOW%^ "+
                "carried by "+ETOQCN+"%^BOLD%^%^YELLOW%^ suddenly "+
                "flares to life, offering a soft "+
                "glow!%^RESET%^", ETO);
            }
        }
        TO->set_property("added short", ({ "%^BOLD%^%^WHITE%^ ("+SCOL+
        " Glowing %^BOLD%^%^WHITE%^)"}));
        ETO->set_property("light", 3);
        isLit = 1;
        set_heart_beat(1);  
        return 1;
    }
}

void heart_beat()
{	
    if(!objectp(TO)) return;
    if(!objectp(ETO)) return;
    if(duration == -1) return;
    if(isLit) 
    {
        duration--;
        if(duration < 1) darken();	
    }
    return;
}

	
int douse(string str) 
{
    if(!objectp(TO)) return 0;
    if(!objectp(ETO)) return 0;
    if(!stringp(str)) return 0;
    if(TO != present(str, ETO)) return 0;
    if(!isLit)
    {
        tell_object(ETO, TO->query_short()+"%^BOLD%^%^YELLOW%^ "+
        "is not "+SCOL+"lit%^BOLD%^%^YELLOW%^.%^RESET%^");
        return 1;
    }
    darken();	
    return 1;
}

int save_me(string file) 
{
    return 1;
}
// Hack to get around imperfect implementation of detect magic in /std/Object.c
int isMagic() { return 2;}
