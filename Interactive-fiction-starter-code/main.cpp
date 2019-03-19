#include <iostream>
#include "Location.h"
#include "Player.h"
#include "GameItem.h"

using namespace std;

int main()
{
  // ==== PLEASE READ ====
  // This code sets up and runs an EXAMPLE story.
  // It does NOT comprehensively test the classes in the project!
  // You should add a lot of code here to make sure everything
  // is working correctly.

  // Creating some locations
  Location * b = new Location("Ballroom",
			      "This is a grand ballroom with a wooden floor and many fancy curtains.");

  Location * k = new Location("Kitchen",
			      "A small kitchen filled with pots and pans.");

  Location * d = new Location("Dining Room",
			      "A large room with a big table.");

  // Connect the locations together
  b->AddExit("east", k);
  k->AddExit("west", b);
  k->AddExit("north", d);
  d->AddExit("south", k);
  d->AddExit("southwest", b);
  b->AddExit("northeast", d);

  // Creating a player and starting them in the kitchen
  Player * p = new Player("AFGNCAAP", "You are an AFGNCAAP. (Google it.)", k);
  p->PlayGame();

  // Deallocating the location objects
  // (Not stricly necessary since the application is about to terminate
  //  anyway, but a good habit!)
  delete b;
  delete k;
  delete d;
}
