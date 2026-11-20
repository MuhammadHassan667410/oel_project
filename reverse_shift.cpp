#include <iostream>
#include <string>
#include <ctime>
using namespace std;

bool playReflectionGame(int& triesUsed)
{
    int maxTries = 3;
    int timeLimit = 120;                // seconds
    time_t startTime = time(0);         // the moment the level starts
    string answer;

    cout << "LEVEL 5: 3-Step Reflection" << endl;
    cout << "decrypt the given word" << endl;
    cout << "level type: hard" << endl;
    cout << "You have " << timeLimit << " seconds!" << endl;
    cout << "SJUFYHDOIJ" << endl;

    for (triesUsed = 1; triesUsed <= maxTries; triesUsed++)
    {
        cout << "Time left: " << timeLimit - (time(0) - startTime) << " seconds" << endl;
        cout << "attempt " << triesUsed << " out of " << maxTries << "." << endl;
        cin >> answer;

        if (time(0) - startTime > timeLimit)
        {
            cout << "TIME'S UP!" << endl;
            cout << "LEVEL FAILED" << endl;
            return false;
        }

        if (answer == "encryption" || answer == "ENCRYPTION")
        {
            cout << "LEVEL CLEARED" << endl;
            return true;
        }
        else
        {
            if (triesUsed < maxTries)
                cout << "wrong answer, try again" << endl;
        }
    }

    // all 3 tries were used without a correct answer
    triesUsed = maxTries;
    cout << "LEVEL FAILED" << endl;
    return false;
}
