#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;
#include "game.h"

/*
 * Display the Rock, Paper, Scissors menu
 */
void GameMenu()
{
    cout << "--------------------------------------" << endl;
    cout << "-- Lets play Rock, Paper, Scissors! --" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Press 1 for Rock, 2 for Paper, 3 for Scissors:" << endl;
}

/**
 * @brief Generate a random number between 1 and 3
 *
 * @return int: random number
 */
int AiChoice()
{
    // gets a random number between 1 and 3
    srand(time(NULL));     // sed random seed
    int ai = rand() % 3 + 1;
    // Display random computer choice
    cout << "The computer selects: " << ai << endl;
    return ai;  // return value
}

/**
 * @brief Logic for Rock, Paper, Scissors game
 *
 * @param player: player 1 choice
 * @param computer: player 2 choice
 */
void RockPaperScissors(int player, int computer)
{
    if(player == 1)
        {
            if(computer == 1)
            {
                cout << "Rock meets Rock its a tie!" << endl;
            }
            if(computer == 2)
            {
                cout << "Rock is covered by Paper the computer wins!" << endl;
            }
            if(computer == 3)
            {
                cout << "Rock crushes Scissors you win!" << endl;
            }
        }
    else if(player == 2)
        {
            if(computer == 1)
            {
                cout << "Paper covers Rock you win!" << endl;
            }
            if(computer == 2)
            {
                cout << "Paper meets Paper its a tie!" << endl;
            }
            if(computer == 3)
            {
                cout << "Paper is cut by Scissors the computer wins!" << endl;
            }
        }
    else if(player == 3)
        {
            if(computer == 1)
            {
                cout << "Scissors are crushed by Rock computer wins!" << endl;
            }
            if(computer == 2)
            {
                cout << "Scissors cuts Paper you win!" << endl;
            }
            if(computer == 3)
            {
                cout << "Scissors meet Scissors its a tie!" << endl;
            }
        }
    else
        {
            cout << "You didn't select 1, 2, or 3" << endl;
        }
}