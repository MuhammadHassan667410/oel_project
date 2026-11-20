// main.cpp
// VAULT ESCAPE - FOCP project
// This is the main file of the game. It shows the instructions,
// runs all 6 levels one by one, adds up the points and then
// decides if the player escaped the vault or not.

#include <iostream>
#include "games.h"      // prototypes of all 6 game functions
using namespace std;

// Function prototypes
void showInstructions();
int getPoints(int triesUsed, int firstTry, int secondTry, int thirdTry);
bool playLevel(int level, int& score);

int main()
{
    int totalLevels = 6;
    int passingScore = 45;      // points needed to escape
    int maxScore = 60;          // highest points possible
    int score = 0;
    bool alive = true;
    bool escaped = false;

    showInstructions();

    // the game keeps running until the player dies or escapes
    while (alive == true && escaped == false)
    {
        score = 0;      // every new run starts from 0 points

        // play the levels one by one
        for (int level = 1; level <= totalLevels; level++)
        {
            if (playLevel(level, score) == false)
            {
                alive = false;      // failed a level, so the player dies
                break;              // no more levels
            }
        }

        // this part only runs if all 6 levels were passed
        if (alive == true)
        {
            cout << endl << "========================================" << endl;
            cout << "You passed all " << totalLevels << " levels!" << endl;
            cout << "Your total score: " << score << " out of " << maxScore << endl;

            if (score >= passingScore)
            {
                escaped = true;
            }
            else
            {
                cout << "You needed at least " << passingScore << " points to open the vault door." << endl;
                cout << "The vault resets... you have to start again from Level 1!" << endl;
                cout << "========================================" << endl;
            }
        }
    }

    // final result of the game
    cout << endl << "========================================" << endl;
    if (escaped == true)
    {
        cout << "The vault door opens..." << endl;
        cout << "CONGRATULATIONS! YOU ESCAPED THE VAULT!" << endl;
    }
    else
    {
        cout << "You failed the level and died inside the vault." << endl;
        cout << "GAME OVER" << endl;
    }
    cout << "========================================" << endl;

    return 0;
}

// Prints the story, the levels, the point system and the rules.
void showInstructions()
{
    cout << "========================================" << endl;
    cout << "            VAULT ESCAPE" << endl;
    cout << "========================================" << endl;
    cout << "You are locked inside a secret vault." << endl;
    cout << "To escape, you must clear 6 levels of codes and puzzles." << endl;

    cout << endl << "----- THE LEVELS -----" << endl;
    cout << "Level 1 (EASY)   Word Swap: the letters of a word are mixed up," << endl;
    cout << "                 put them back in the right order." << endl;
    cout << "Level 2 (EASY)   Symmetric Mirroring: every letter is swapped with" << endl;
    cout << "                 its mirror letter (A <-> Z, B <-> Y ...). Find the word." << endl;
    cout << "Level 3 (MEDIUM) Number Pattern: find the next fraction in the pattern." << endl;
    cout << "Level 4 (MEDIUM) ASCII Decoding: turn the ASCII numbers back into a word." << endl;
    cout << "Level 5 (HARD)   3-Step Reflection: a harder code that mixes mirroring" << endl;
    cout << "                 and shifting of letters. You only have 120 seconds!" << endl;
    cout << "Level 6 (HARD)   Detective: study the clues and catch the murderer." << endl;
    cout << "                 You only have 60 seconds and ONE accusation!" << endl;

    cout << endl << "----- POINTS -----" << endl;
    cout << "You get 3 tries in every level (except Level 6)." << endl;
    cout << "                1st try   2nd try   3rd try" << endl;
    cout << "Easy levels        5         3         1" << endl;
    cout << "Medium levels     10         7         4" << endl;
    cout << "Hard (Level 5)    15        11         7" << endl;
    cout << "Hard (Level 6)    15 points if you solve the case" << endl;
    cout << "Maximum points: 60" << endl;

    cout << endl << "----- RULES -----" << endl;
    cout << "1. If you fail any level, you die and the game is over." << endl;
    cout << "2. You need at least 45 points to escape the vault." << endl;
    cout << "3. If you pass all levels with less than 45 points," << endl;
    cout << "   you must start the whole game again." << endl;
    cout << "========================================" << endl;
}

// Gives the points for a level depending on which try the player passed in.
// firstTry, secondTry and thirdTry are the points for each try.
int getPoints(int triesUsed, int firstTry, int secondTry, int thirdTry)
{
    if (triesUsed == 1)
        return firstTry;
    else if (triesUsed == 2)
        return secondTry;
    else
        return thirdTry;
}

// Plays one level and adds its points to the score.
// score is passed by reference so the points are added to the real score in main.
// Returns true if the level was passed, otherwise false.
bool playLevel(int level, int& score)
{
    int tries = 0;
    int points = 0;
    bool passed = false;

    cout << endl << "========================================" << endl;

    switch (level)
    {
    case 1:
        cout << "LEVEL 1 of 6 (EASY)" << endl;
        passed = playWordSwapGame(tries);
        points = getPoints(tries, 5, 3, 1);
        break;
    case 2:
        cout << "LEVEL 2 of 6 (EASY)" << endl;
        passed = playMirroringGame(tries);
        points = getPoints(tries, 5, 3, 1);
        break;
    case 3:
        cout << "LEVEL 3 of 6 (MEDIUM)" << endl;
        passed = playPatternGame(tries);
        points = getPoints(tries, 10, 7, 4);
        break;
    case 4:
        cout << "LEVEL 4 of 6 (MEDIUM)" << endl;
        passed = playAsciiGame(tries);
        points = getPoints(tries, 10, 7, 4);
        break;
    case 5:
        cout << "LEVEL 5 of 6 (HARD)" << endl;
        passed = playReflectionGame(tries);
        points = getPoints(tries, 15, 11, 7);
        break;
    case 6:
        cout << "LEVEL 6 of 6 (HARD)" << endl;
        passed = playDetectiveGame();
        points = 15;        // this level has no tries, so it is always 15
        break;
    }

    // points are only given if the level was passed
    if (passed == true)
    {
        score = score + points;
        cout << endl << "You earned " << points << " points. Total score: " << score << endl;
    }

    return passed;
}
