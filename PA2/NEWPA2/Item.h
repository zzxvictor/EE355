#ifndef ITEM_H
#define ITEM_H

#define ATTACKVALUE 10
#define DEFENSEVALUE 10

class Item
{
   private:
      std::string name;
   public:
      Item();
};


class Sword : public Item 
{
   private:
      int attack;
   public:
      Sword();
      int getAttack();

};

class Equipment : public Item 
{
   private:
      int defense;
   public:
      Equipment();
      int getDefense ();

};
#endif
