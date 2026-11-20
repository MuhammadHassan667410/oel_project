#include<iostream>
using namespace std;

bool playMirroringGame(int& triesUsed)
{
    int maxTries = 3;
    string answer;

    cout << "LEVEL 3 : SYMMETRIC MIRRORING" << endl;
    cout << "decrypt the message " << endl;
    cout << "WVXRKSVI" << endl;

    for (triesUsed = 1; triesUsed <= maxTries; triesUsed++)
    {
        cout << "attempt " << triesUsed << " out of " << maxTries << "." << endl;
        cin >> answer;

        if (answer == "decipher" || answer == "DECIPHER")
        {
            cout << "LEVEL CLEARED" << endl;
            return true;
        }
    }

    // all 3 tries were used without a correct answer
    triesUsed = maxTries;
    cout << "LEVEL FAILED" << endl;
    return false;
}
