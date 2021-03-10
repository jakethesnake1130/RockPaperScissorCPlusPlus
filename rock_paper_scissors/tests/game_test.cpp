#include <string>
#include <time.h>
#include "game.h"
#include "cout_redirect.h"  // To test cout <<
// this tells catch to provide a main()
// only do this in one cpp file
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

void delay() {
  clock_t start = clock();
  while (clock() < start + 1000)
    ;
}

TEST_CASE("Testing GameMenu", "[Part1]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    // Act
    GameMenu();                              // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string =
        "--------------------------------------\n"
        "-- Lets play Rock, Paper, Scissors! --\n"
        "--------------------------------------\n"
        "Press 1 for Rock, 2 for Paper, 3 for Scissors:\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing AiChoice", "[Part2]")
{
  // Arrange
  CoutRedirect buffer;  // open buffer to capture output
  int random_number;
  std::string s_out = "";
  std::string test_string = "";

  for (int i = 0; i < 9; ++i) {
    // Act
    random_number = AiChoice();

    s_out = buffer.getString();  // get capture output to string
    // check range of random number
    // Assert
    CHECK(random_number >= 1);
    CHECK(random_number <= 3);
    delay();
  }


}

TEST_CASE("Testing RockPaperScissors(1,1)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 1;
    int computer = 1;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "Rock meets Rock its a tie!\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing RockPaperScissors(1,2)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 1;
    int computer = 2;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "Rock is covered by Paper the computer wins!\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing RockPaperScissors(1,3)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 1;
    int computer = 3;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "Rock crushes Scissors you win!\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing RockPaperScissors(2,1)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 2;
    int computer = 1;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "Paper covers Rock you win!\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing RockPaperScissors(2,2)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 2;
    int computer = 2;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "Paper meets Paper its a tie!\n" ;

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing RockPaperScissors(2,3)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 2;
    int computer = 3;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "Paper is cut by Scissors the computer wins!\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing RockPaperScissors(3,1)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 3;
    int computer = 1;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "Scissors are crushed by Rock computer wins!\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing RockPaperScissors(3,2)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 3;
    int computer = 2;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "Scissors cuts Paper you win!\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing RockPaperScissors(3,3)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 3;
    int computer = 3;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "Scissors meet Scissors its a tie!\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}

TEST_CASE("Testing RockPaperScissors(4,3)", "[Part3]")
{
    // Arrange
    CoutRedirect buffer;  // open buffer to capture output
    int player = 4;
    int computer = 3;
    // Act
    RockPaperScissors(player, computer);     // capture output
    std::string s_out = buffer.getString();  // get capture output to string
    std::string test_string = "You didn't select 1, 2, or 3\n";

    // Assert
    CHECK(s_out == test_string);  // compare two integers
}