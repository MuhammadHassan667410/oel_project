// word_swap_game.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
using namespace std;
bool playWordSwapGame(int& triesUsed)
{
    int maxTries = 3;
    string answer;

    cout << "===== WORD SWAP CHALLENGE =====" << endl;
    cout << "Unscramble the word: PYTCREN" << endl;
    cout << "Hint: To hide a message by turning it into a secret code" << endl;
    cout << "You have " << maxTries << " tries." << endl;

    for (triesUsed = 1; triesUsed <= maxTries; triesUsed++)
    {
        cout << endl << "Try " << triesUsed << " of " << maxTries << endl;
        cout << "Enter your answer: ";
        cin >> answer;

        if (answer == "ENCRYPT" || answer == "encrypt")
        {
            cout << "Correct! You solved the challenge." << endl;
            return true;
        }
        else
        {
            cout << "Wrong answer." << endl;
        }
    }

    // all 3 tries were used without a correct answer
    triesUsed = maxTries;
    cout << endl << "Out of tries! The correct word was ENCRYPT." << endl;
    return false;
}

int main()
{
	int triesUsed = 0;
	bool gameWon = playWordSwapGame(triesUsed);
	return 0;
}