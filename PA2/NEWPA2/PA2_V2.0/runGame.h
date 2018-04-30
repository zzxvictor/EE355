#ifndef RUNGAME_H
#define RUNGAME_H

class HunterBook;
class Monsterbook;
class PalicoBook;
class ChampionBook;
class GUI;


void run(HunterBook * hb, Monsterbook *mb, PalicoBook *pb, ChampionBook *cb);
bool checkGame(HunterBook * hb, Monsterbook *mb, PalicoBook *pb, ChampionBook *cb);
void mergeHunterPalico(HunterBook * hb, PalicoBook *pb, ChampionBook *cb);
void runFight(HunterBook * hb, Monsterbook *mb, PalicoBook *pb, ChampionBook *cb);
void moveAround(HunterBook * hb, Monsterbook *mb, PalicoBook *pb, ChampionBook *cb);
void hunterFightMonster(HunterBook * hb, Monsterbook *mb);
void palicoFightMonster(PalicoBook *pb, Monsterbook *mb);
void ChampionFightMonster(ChampionBook *cb, Monsterbook *mb);

#endif
