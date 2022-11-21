[1mdiff --git a/std/class/inquisitor.c b/std/class/inquisitor.c[m
[1mindex 8b2cf435b..13be92995 100644[m
[1m--- a/std/class/inquisitor.c[m
[1m+++ b/std/class/inquisitor.c[m
[36m@@ -41,7 +41,18 @@[m [mstring *class_feats(string myspec)[m
 }[m
 [m
 mapping class_featmap(string myspec) {[m
[31m-    return ([ 1 : class_feats()+({"judgement","monster lore", }), 2 : ({ "track" }), 3:({"force of personality"}), 5: ({"bane"}), 6: ({"leadership"}), 8: ({"second judgement"}), 11: ({"stalwart"}), 14: ({"exploit weakness"}),16 : ({"third judgement"}), 17 : ({"slayer"}), 20 : ({"true judgement"})]);[m
[32m+[m[32m    return ([[m[41m[m
[32m+[m	[32m     1 : class_feats()+({"judgement","monster lore", "divine domain"}),[m[41m[m
[32m+[m	[32m     2 : ({ "track" }),[m[41m[m
[32m+[m	[32m     3 : ({"force of personality"}),[m[41m[m
[32m+[m	[32m     5 : ({"bane"}),[m[41m[m
[32m+[m	[32m     6 : ({"leadership"}),[m[41m[m
[32m+[m	[32m     8 : ({"second judgement"}),[m[41m[m
[32m+[m	[32m     11: ({"stalwart"}),[m[41m[m
[32m+[m	[32m     14: ({"exploit weakness"}),[m[41m[m
[32m+[m	[32m     16: ({"third judgement"}),[m[41m[m
[32m+[m	[32m     17: ({"slayer"}),[m[41m[m
[32m+[m	[32m     20: ({"true judgement"})]);[m[41m[m
 }[m
 [m
 string *class_skills()[m
[1mdiff --git a/std/magic/spell.c b/std/magic/spell.c[m
[1mindex a4f4ad6dc..c1076a9c8 100644[m
[1m--- a/std/magic/spell.c[m
[1m+++ b/std/magic/spell.c[m
[36m@@ -806,7 +806,6 @@[m [mvoid wizard_interface(object user, string type, string targ)[m
         break;[m
     }[m
 [m
[31m-[m
     if (spell_type == "psion") {[m
         psyclass = "psion"; altclass = "psywarrior";[m
     }[m
[36m@@ -845,9 +844,11 @@[m [mvoid wizard_interface(object user, string type, string targ)[m
     casting_level = query_spell_level(spell_type);[m
 [m
     if (!casting_level) {[m
[31m-        tell_object(user, "The " + spell_type + " class cannot cast such a spell!\n");[m
[31m-        TO->remove();[m
[31m-        return;[m
[32m+[m[32m      casting_level = 1;[m
[32m+[m[32m      // quick hack[m
[32m+[m[32m      // tell_object(user, "The " + spell_type + " class cannot cast such a spell!\n");[m
[32m+[m[32m      //  TO->remove();[m
[32m+[m[32m      //  return;[m
     }[m
 [m
     if (!user) {[m
[36m@@ -1758,7 +1759,7 @@[m [mint query_spell_level(string classtype)[m
         return spell_levels["bard"];[m
     }[m
     if (classtype == "wizard" && spell_levels["magus"]) {[m
[31m-        return spell_levels["magus"];[m
[32m+[m[32m     p   return spell_levels["magus"];[m
     }[m
     if (classtype == "psionics" && spell_levels["psion"]) {[m
         return spell_levels["psion"];[m
