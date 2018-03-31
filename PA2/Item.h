#ifndef ITEM_H
#define ITEM_H

#define ATTACKVALUE 10
#define DEFENSEVALUE 10

class item
{
   private:
      string name;
   public:
      item();
};


class Sword : public item 
{
   private:
      int attack;
   public:
      Sword();

};

class Equipment : public item 
{
   private:
      int defense;
   public:
      Equipment();
};
#endif
