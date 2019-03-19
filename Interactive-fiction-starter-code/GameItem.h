#ifndef GAMEITEM_H

#define GAMEITEM_H
#include <iostream>
using namespace std;

class GameItem
{
 private:
  string name;
  string description;

 public:
  GameItem(string itemName, string itemDescription);
  void Describe() const;
};

#endif
