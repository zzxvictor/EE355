#ifndef ITEM_H
#define ITEM_H

#define ATTACKVALUE 10
#define DEFENSEVALUE 10

class Item
{
   protected:
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
      std::string getName();

};

class Equipment : public Item 
{
   private:
      int defense;
   public:
      Equipment();
      int getDefense ();
      std::string getName();

};
#endif
