#include <iostream>
using namespace std;

bool playPatternGame(int& triesUsed)
{
    int maxTries = 3;
    int userNum, userDen;

    cout << "===== NUMBER PATTERN GAME =====" << endl;
    cout << "Find the next number in this pattern:" << endl;
    cout << "1/2 , 3/5 , 8/13 , 21/34 , ?" << endl;
    cout << "You have " << maxTries << " tries." << endl;

    for (triesUsed = 1; triesUsed <= maxTries; triesUsed++)
    {
        cout << endl << "Try " << triesUsed << " of " << maxTries << endl;
        cout << "Enter the numerator: ";
        cin >> userNum;
        cout << "Enter the denominator: ";
        cin >> userDen;

        // the correct answer is 55/89
        if (userNum == 55 && userDen == 89)
        {
            cout << "Correct! The next number is 55/89" << endl;
            return true;
        }
        else
        {
            cout << "Wrong answer." << endl;
        }
    }

    // all 3 tries were used without a correct guess
    triesUsed = maxTries;
    cout << endl << "Out of tries! The correct answer was 55/89" << endl;
    return false;
}

int main()
{
	int triesUsed;
	playPatternGame(triesUsed);
	return 0;
}