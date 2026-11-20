#include <iostream>
#include <string>

using namespace std;

bool playAsciiGame(int& triesUsed)
{
    int size = 8;
    //              P    r    o    M   O    t    e   D
    int codes[8] = { 80, 114, 111, 77, 79, 116, 101, 68 };
    int maxTries = 3;
    string guess;

    cout << "Hint: capital letters A = 65, B = 66 ... Z = 90" << endl;
    cout << "      small letters   a = 97, b = 98 ... z = 122" << endl;
    cout << "Decode the word (capital and small letters matter):" << endl;

    // show the ASCII values
    for (int i = 0; i < size; i++)
    {
        cout << codes[i] << " ";
    }
    cout << endl;

    cout << "You have " << maxTries << " tries." << endl;

    for (triesUsed = 1; triesUsed <= maxTries; triesUsed++)
    {
        cout << endl << "Try " << triesUsed << " of " << maxTries << endl;
        cout << "Enter the word: ";
        cin >> guess;

        int length = (int)guess.length();
        bool correct = true;

        if (length != size)
        {
            correct = false;
        }
        else
        {
            // compare every typed letter directly with its ASCII value
            for (int i = 0; i < size; i++)
            {
                if (guess[i] != codes[i]) // Removed toupper()
                {
                    correct = false;
                    break; // Stop checking once a mismatch is found
                }
            }
        }

        if (correct)
        {
            cout << "Correct! The word is ProMOteD" << endl;
            return true;
        }
        else
        {
            cout << "Wrong answer." << endl;
        }
    }

    // all 3 tries were used without a correct guess
    triesUsed = maxTries;
    cout << endl << "Out of tries! The word was ProMOteD" << endl; // Fixed word
    return false;
}

int main()
{
    int triesUsed = 0;
    playAsciiGame(triesUsed);
    return 0;
}