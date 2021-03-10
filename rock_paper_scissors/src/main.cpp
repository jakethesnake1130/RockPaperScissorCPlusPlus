#include <iostream>
#include "game.h"
using namespace std;

int main()
{
    // Set the char variable for the y/n while loop.
    char ch = 'Y';
    int games = 0;

    // Part 1.2: start of game loop, the loop will run until ch != 'Y' or 'y'
    while (ch == 'Y' || ch == 'y')
    {
        int choice;
        // Part 1: Call Menu Function
        GameMenu();
        cin >> choice;      // capture input

        //Part 2: Get the AI choice
        int ai = AiChoice();

        // Part 3: Call logic function
        RockPaperScissors(choice, ai);

        // Repeat process
        cout << "Would you like to play again? Y/N" << endl;
        // No validation on input is required at this point. We will assume the user
        // uses only Y|y for true, anything else is false
        cin >> ch;
        games++;
        if(games >= 3)
        {
            cout << "You played " << games << " games. That's enough for today, thanks for playing" << endl;
            break;
        }
    }  // end of while loop
    return 0;
}