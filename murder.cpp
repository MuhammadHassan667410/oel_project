#include <iostream>
#include <ctime>
using namespace std;

// Function prototype
bool playDetectiveGame();

// main (only for testing this game)
int main()
{
    if (playDetectiveGame() == true)
        cout << "\n\nYou WON the detective game!" << endl;
    else
        cout << "\n\nYou LOST the detective game." << endl;

    return 0;
}

// Detective game (final level).
// The player has 60 seconds to investigate, interrogate and accuse.
// There is only one accusation, no extra tries.
// Returns true if the player catches the murderer in time, otherwise false.
bool playDetectiveGame()
{
    int choice;
    int clues = 0;
    bool found[3] = { false, false, false };
    int timeLimit = 60;                 // seconds
    time_t startTime = time(0);         // the moment the game starts

    cout << "===== THE DETECTIVE GAME =====";
    cout << "\nA businessman named Asfandyar has been murdered!";
    cout << "\nHe was found dead in his office.";
    cout << "\nSuspects: Ali (his business partner) and Saad (a client)";
    cout << "\nYou have " << timeLimit << " seconds to solve the case!";

    // ----- INVESTIGATION -----
    cout << "\n\n===== INVESTIGATION =====";

    while (clues < 3)
    {
        cout << "\n\nTime left: " << timeLimit - (time(0) - startTime) << " seconds";
        cout << "\n1. Examine Footprint";
        cout << "\n2. Find Watch";
        cout << "\n3. Check CCTV";
        cout << "\n4. Finish Investigation";
        cout << "\nEnter choice: ";
        cin >> choice;

        if (time(0) - startTime > timeLimit)
        {
            cout << "\nTIME'S UP! The murderer was Ali.";
            return false;
        }

        if (choice >= 1 && choice <= 3)
        {
            if (found[choice - 1] == false)
            {
                found[choice - 1] = true;
                clues++;

                cout << "\nClue discovered!";

                if (choice == 1)
                    cout << "\nWet, muddy footprints lead from the BACK door to the body.\nThe weather report says it only started raining at 9:15 PM.";
                else if (choice == 2)
                    cout << "\nAsfandyar's broken watch stopped at 9:30 PM.\nNext to it is a coffee cup with Saad's fingerprints on it.";
                else
                    cout << "\nThe FRONT door camera shows Saad leaving at 9:00 PM.\nThe back door has no camera, and only Asfandyar and his\nbusiness partner have a key to it.";
            }
            else
                cout << "\nYou have already found this clue!";
        }
        else if (choice == 4)
            break;
        else
            cout << "\nInvalid choice!";
    }

    // ----- INTERROGATION -----
    cout << "\n\n===== INTERROGATION =====";
    cout << "\nTime left: " << timeLimit - (time(0) - startTime) << " seconds";
    cout << "\n1. Question Saad";
    cout << "\n2. Question Ali";
    cout << "\nEnter choice: ";
    cin >> choice;

    if (time(0) - startTime > timeLimit)
    {
        cout << "\nTIME'S UP! The murderer was Ali.";
        return false;
    }

    if (choice == 1)
    {
        cout << "\nSaad: Yes, we had coffee and argued about money he owed me.";
        cout << "\nBut I left at 9 PM through the front door. The road was dry.";
    }
    else if (choice == 2)
    {
        cout << "\nAli: I was at home all evening, I never went out.";
        cout << "\nYou notice his umbrella by the door is still dripping wet.";
    }
    else
        cout << "\nInvalid choice!";

    // ----- ACCUSATION (only one chance) -----
    choice = 0;
    while (choice != 1 && choice != 2)     // repeat only if the choice is invalid
    {
        cout << "\n\n===== WHO IS THE MURDERER? =====";
        cout << "\nTime left: " << timeLimit - (time(0) - startTime) << " seconds";
        cout << "\n1. Saad";
        cout << "\n2. Ali";
        cout << "\nEnter your accusation: ";
        cin >> choice;

        if (time(0) - startTime > timeLimit)
        {
            cout << "\nTIME'S UP! The murderer was Ali.";
            return false;
        }

        if (choice != 1 && choice != 2)
            cout << "\nInvalid choice!";
    }

    if (choice == 2)
    {
        cout << "\nCASE SOLVED!";
        cout << "\nCongratulations, Detective!";
        cout << "\nAli is the murderer!";
        return true;
    }
    else
    {
        cout << "\nWrong accusation!";
        cout << "\nCASE UNSOLVED! The murderer was Ali.";
        return false;
    }
}

int main()
{
    playDetectiveGame();
    return 0;
}