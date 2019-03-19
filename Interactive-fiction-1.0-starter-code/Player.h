#ifndef PLAYER_H
#define PLAYER_H
#include <vector>
#include <iostream>
#include "GameItem.h"
#include "Location.h"
using namespace std;

/*

 ABOUT THE Player CLASS
 ----------------------
 This is inteded as a SINGLETON class.
 A given story/game will have a single Player object, initialized
  to start in one particular Location.

 Some of the methods in this class have already been implemented for you,
 but you will need to implement or modify others.

 Many of the public and private methods whose prototypes are listed
 here are intended as STRONG SUGGESTIONS for how to organize the
 intended functionality, matching our design principle
 that one method should have one job.

 The main "action" of a story/game in progress is handled by the public
 PlayGame method, which would then call one or more of the private
 helper methods


*/

class Player
{
 private:
  string name;
  string description;
  int score;
  int totalMoves;
  bool gameIsOver;
  Location * currentLocation;
  vector<GameItem *> inventory;

  /// Private helper methods
  void Move(string direction);
  void Describe() const;
  void Look() const;
  void ShowInventory() const;
  void DescribeItem(string itemName) const;
  void TakeItem(string itemName);
  void DropItem(string itemName);
  void HandleOneWordCommand(string command);
  void HandleTwoWordCommand(string command, string thing);

 public:
  Player(string playerName, string playerDescription, Location * startLocation);
  void AddItem(GameItem * item);
  void PlayGame();

};










#endif
