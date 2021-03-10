# CHALLENGE: ROCK, PAPER, SCISSORS


---

## Purpose

This is an introductory assignment. The purpose of this assignment is to help you review all the basic programming concepts plus some new `C++` concepts.  

## Skills and Knowledge

This activity will help you practice the following skills that essential to know for basic programming in `C++`:

- Define libraries
- Call functions
- Define namespaces

This lab will also help you to become familiar with the following important content knowledge in CS:

- Setting and working in a development environment.
- Review basic programming concepts.
- Use basic unit testing to validate your code: `catch2`.

---

## Files to work on

You will be working the following files:

- All the functions you write, will be part of the library `game`. The library consist of these two files:
  - `src/game.cpp`
  - `src/game.h`
- Our "driver" will be `src/main.cpp`.

Please **DO NOT MODIFY** any other files. Modifying any other file may result 
in the unit tests not passing.

---

## Part 1: Create Game Flow

In the following activity, we will use a `while` loop to play the
famous rock, paper, and scissors game. We will also practice the use
conditionals.

### Part 1.1: Define Game Menu

The first task is to create a menu that displays the user choices. This function does not take any arguments, and it does not return anything back to the user. Begin by declaring the function signature in `game.h`

```cpp
void GameMenu();
```

Function breakdown:

- `void`: return value from the function, in this case void means nothing to return.
- `GameMenu`: is the function name
- `()`: empty parenthesis means no input parameter.

Now, define the function in our implementation file: `game.cpp`

```cpp
/**
 * @brief Display the Rock, Paper, Scissors game menu
 *
 */
void GameMenu()
{
  // Your output message here

}
```

Your function should display the message below.

Note: make sure your output matches this string exactly as is being display. Double check your output for spaces, new lines, etc.

```bash
--------------------------------------
-- Lets play Rock, Paper, Scissors! --
--------------------------------------
Press 1 for Rock, 2 for Paper, 3 for Scissors:
```

Next, let's define a variable to capture the user input and call our  `GameMenu()` function in `main` program.

```cpp
// main.cpp

int main()
{
  int choice, ai;
  // Part 1: Call Menu Function
  GameMenu();
  cin >> choice;      // capture input

  // Just for testing this task. Remove after this
  cout << "You entered: " << choice << endl;

  return 0;
}
```

#### Run Code Part 1.1

From the dropdown select main and run.

#### Sample Output Part 1.1

```bash

--------------------------------------
-- Lets play Rock, Paper, Scissors! --
--------------------------------------
Press 1 for Rock, 2 for Paper, 3 for Scissors:
1
You entered: 1
```

### Part 1.2: Define Game Flow

Your next task is to create game flow. The player should have the option to play the game up to 3 times.
To implement this, move the code from the previous task into a `while loop`. Then, ask the player if they want to play again. If the player enters `Y or y`, then you repeat the code in the loop.
For now, we will assume the player will not enter any invalid input.

```cpp
int main()
{
    // Set the char variable for the y/n while loop.
    char ch = 'Y';

    // Part 1.2: start of game loop, the loop will run until ch != 'Y' or 'y'
    while (ch == 'Y' || ch == 'y')
    {
        int choice;
        // Part 1: Call Menu Function
        GameMenu();
        cin >> choice;      // capture input

        // Repeat process
        cout << "Would you like to play again? Y/N" << endl;
        // No validation on input is required at this point. We will assume the user
        // uses only Y|y for true, anything else is false
        cin >> ch;
    }  // end of while loop
    return 0;
}
```

#### Run Code Part 1.2

From the dropdown select main and run.

#### Sample Output Part 1.2

```bash

--------------------------------------
-- Lets play Rock, Paper, Scissors! --
--------------------------------------
Press 1 for Rock, 2 for Paper, 3 for Scissors:
1
Would you like to play again? Y/N
Y
--------------------------------------
-- Lets play Rock, Paper, Scissors! --
--------------------------------------
Press 1 for Rock, 2 for Paper, 3 for Scissors:
2
Would you like to play again? Y/N
N
```

### Part 1.3: Define Play Limit

Now, in order to avoid someone from hording the game, we will set up a 3 games per player cap.
To implement this, keep track each time you ask the player if they want to play again. Once a player reaches the maximum quota, exit the `while loop` using the `break` command.

```cpp
int main()
{
    // Set the char variable for the y/n while loop.
    char ch = 'Y';
    int games = 0;  // use this variable to keep track of # of games

    // start of game loop, the loop will run until ch != 'Y' or 'y'
    while (ch == 'Y' || ch == 'y')
    {
      // ...
      // ...

      // Part 1.3: Increment counter
      games++;
      if(games >= 3)  // exit loop if >= 3
      {
          cout << "You played " << games << ". Thank you for playing." << endl;
          break;
      }

    }  // end of while loop
    return 0;
}
```

#### Run Code Part 1.3

From the dropdown select main and run.

#### Sample Output Part 1.3

```bash

...
Would you like to play again? Y/N
Y
...
Would you like to play again? Y/N
Y
...
Would you like to play again? Y/N
Y
You played 3 times. Thank you for playing.
```

## Part 2: Generate a Random Number for AI Player

Instead of repeating the logic to select the second player's choice, in this case the computer, we are going to randomly generate this choice. Begin by defining your function signature in `game.h`

```cpp
int AiChoice();
```

Function breakdown:

- `int`: return value from the function, in this case int means the random integer number.
- `AiChoice`: is the function name
- `()`: empty parenthesis means no input parameter.

Now, define the function in our implementation file: `game.cpp`. To use the built-in `rand()` function, you need to include the `ctime` and `cstdlib` libraries.

Since we have not fully discussed functions that return values, I will give you this definition.

```cpp
#include <ctime>    // for the time seed time
#include <cstdlib>  // for srand(), rand() function
/**
 * @brief Generate a random number between 1 and 3
 *
 * @return int: random number
 */
int AiChoice()
{
    // gets a random number between 1 and 3
    srand (time(NULL));     // sed random seed
    int ai = rand() % 3 + 1;
    // Display random computer choice
    cout << "The computer selects: " << ai << endl;
    return ai;  // return value
}
```

Now, call the function in main

```cpp
  // ...
        // Part 1.1: Call Menu Function
        GameMenu();
        cin >> choice;      // capture input

        // Part 2: Get AI choice
        int ai = AiChoice();

        // JUST FOR TESTING THIS Part. REMOVE AFTER THIS
        cout << "Player choice: " << choice << " computer choice: " << ai << endl;

        // Repeat process
        cout << "Would you like to play again? Y/N" << endl;
  // ...
```

### Run Code Part 2

From the dropdown select main and run.

### Sample Output Part 2

```bash
--------------------------------------
-- Lets play Rock, Paper, Scissors! --
--------------------------------------
Press 1 for Rock, 2 for Paper, 3 for Scissors:
1
The computer selects: 2
Player choice: 1 computer choice: 2
Would you like to play again? Y/N
N
```

## Part 3: Game Logic

Finally, you get to implement the game logic. For this, we are going to create another function that will take the two choices, as input parameters and it will determine the winner based on the game rules.

Your output message should be that of the `message` column based on the choices

- Rock = 1
- Paper = 2
- Scissors = 3

| Player | Computer | Winner   | Message                                      |
| :----- | :------- | :------- | :------------------------------------------- |
| 1      | 1        | Tie      | Rock meets Rock its a tie!                   |
| 1      | 2        | Computer | Rock is covered by Paper the computer wins!  |
| 1      | 3        | Player   | Rock crushes Scissors you win!               |
| 2      | 1        | Player   | Paper covers Rock you win!                   |
| 2      | 2        | Tie      | Paper meets Paper its a tie!                 |
| 2      | 3        | Computer | Paper is cut by Scissors the computer wins!  |
| 3      | 1        | Computer | Scissors are crushed by Rock computer wins!" |
| 3      | 2        | Player   | Scissors cuts Paper you win!                 |
| 3      | 3        | Tie      | Scissors meet Scissors its a tie!            |
| other  | other    | ---      | You didn't select 1, 2, or 3                 |

For any other combination, the message should be:

```txt
You didn't select 1, 2, or 3
```

Your function signature in `game.h` is

```cpp
void RockPaperScissors(int player, int computer);
```

and your implementation should go in `game.cpp`

```cpp
/**
 * @brief Logic for Rock, Paper, Scissors game
 *
 * @param player: player 1 choice
 * @param computer: player 2 choice
 */
void RockPaperScissors(int player, int computer)
{
  // Your logic goes here
}
```

Finally, test is in your `main()` function.

```cpp
int main()
{
    // Set the char variable for the y/n while loop.
    char ch = 'Y';
    int games = 0;

    // start of game loop, the loop will run until ch != 'Y' or 'y'
    while (ch == 'Y' || ch == 'y')  // Part 1.2
    {
        int choice, ai;
        // Part 1.1: Call Menu Function
        GameMenu();
        cin >> choice;  // capture input

        // Part 2: Get AI choice
        ai = AiChoice();

        // Part 3: Call logic function
        RockPaperScissors(choice, ai);

        // Repeat process
        cout << "Would you like to play again? Y/N" << endl;
        // No validation on input is required at this point.
        // uses only Y|y for true, anything else is false
        cin >> ch;
        // Part 1.3: Increment counter
        games++;
        if (games >= 3)  // exit loop if >= 3
        {
            cout << "You played " << games << " times. Thank you for playing." << endl;
            break;
        }
    }
    return 0;
}
```

### Run Code Part 3

From the dropdown select main and run.

### Sample Output Part 3: Full program

```txt
--------------------------------------
-- Lets play Rock, Paper, Scissors! --
--------------------------------------
Press 1 for Rock, 2 for Paper, 3 for Scissors:
2
The computer selects: 1
Paper covers Rock you win!
Would you like to play again? Y/N
Y
--------------------------------------
-- Lets play Rock, Paper, Scissors! --
--------------------------------------
Press 1 for Rock, 2 for Paper, 3 for Scissors:
4
The computer selects: 3
You didn't select 1, 2, or 3
Would you like to play again? Y/N
Y
--------------------------------------
-- Lets play Rock, Paper, Scissors! --
--------------------------------------
Press 1 for Rock, 2 for Paper, 3 for Scissors:
1
The computer selects: 2
Rock is covered by Paper the computer wins!
Would you like to play again? Y/N
Y
You played 3 times. Thank you for playing.
`
```
---

## Validate your code

Once you are satisfied with your work, run the unit test file:

From the dropdown select main_test and run.

Tests passed: 12 of 12 tests

---

## Submit your code

Zip your src folder and submit in Canvas.

---