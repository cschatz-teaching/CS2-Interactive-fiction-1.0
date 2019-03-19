#include "Player.h"
#include "utils.h"

Player::Player(string playerName, string playerDescription, Location * startLocation)
{
	// TO DO:
	// Implement the Player constructor

}

void Player::HandleOneWordCommand(string command)
{
	if (command == "quit")
	{
		cout << "Really? That makes me sad. But ok, I'll stop the story now.\n";
    gameIsOver = true;
	}
  else
	{
		// TO DO:
		// Replace/extend the placeholder code below to fully implement
		// the HandleOneWordCommand method.
		cout << "[PLACEHOLDER] You gave me the command '" << command << "'.\n";

	}
}

void Player::HandleTwoWordCommand(string command, string thing)
{
	// TO DO:
	// Replace/extend the placeholder code below to fully implement
	// the HandleTwoWordCommand method.
  cout << "[PLACEHOLDER] You told me you want to '" << command << "' the '" << thing << "'.\n";
}

void Player::PlayGame()
{
	// TO DO:
	// Probably nothing! :)
	// This method is fully implemented, but you may decide
	//  on some of your own tweaks as you develop the rest of the program.

	gameIsOver = false;
	string userSentence = "";

	// Describe the current location
	cout << "\n";
	currentLocation->Describe();

	while (!gameIsOver)
	{
		// Print a prompt
		cout << "\n";
		cout << "> ";

    // Get a line of input from the user
    getline(cin, userSentence);

    // Always change to lowercase to make processing simpler
    userSentence = ConvertToLowercase(userSentence);

    // Break it into words
    vector<string> words = DivideLineIntoWords(userSentence);

    // "Unabbreviate" the first word
    UnAbbreviate(words[0]);

    // Print a blank line for readability
    cout << "\n";

    // Check for the user entering nothing
    if (userSentence == "")
		{
			cout << "(You didn't type anything!)\n";
			continue;
		}

		// Handle commands
    int wordCount = words.size();
    if (wordCount == 1)
		{
		  HandleOneWordCommand(words[0]);
		}
    else if (wordCount == 2)
		{
		  HandleTwoWordCommand(words[0], words[1]);
		}
    else
		{
		  cout << "I don't know how to respond to commands with more than 2 words, sorry!\n";
		}
  }
  cout << "\n";
  cout << "Have a nice day!\n";
}
