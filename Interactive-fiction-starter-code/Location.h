#ifndef LOCATION_H
#define LOCATION_H
#include <iostream>
#include <vector>
#include "GameItem.h"
using namespace std;

class Location
{
 private:
   // The location's name and description
  string name;
  string description;

  // Available directions (Ex: "north", "west", "up")
  vector<string> exitDirections;
  // Links (i.e. pointers) to the Locations the exits directions lead to
  vector<Location *> exitDestinations;
  // Links (i.e. pointers) to Items in this location
  vector<GameItem *> itemsInLocation;

 public:
  Location(string locName, string locDescription);
  void Describe() const;
  void AddExit(string direction, Location * whereTo);
  void AddItem(GameItem * item);
};


#endif
