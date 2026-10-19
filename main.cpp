
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    char playAgain;

    cout << "============================\n";
    cout << "   NUMBER GUESSING GAME\n";
    cout << "============================\n";

    do {
        int secretNumber = rand() % 100 + 1;
        int guess;
        int attempts = 0;

        cout << "\nI'm thinking of a number from 1 to 100!\n";
        cout << "Can you guess what it is?\n";

        while (true) {
            cout << "\nEnter your guess: ";

            if (!(cin >> guess)) {
                cout << "Please enter a valid number!\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                continue;
            }

            if (guess < 1 || guess > 100) {
                cout << "Your guess must be between 1 and 100.\n";
                continue;
            }

            attempts++;

            if (guess < secretNumber) {
                cout << "Too low! Try a higher number.\n";
            }
            else if (guess > secretNumber) {
                cout << "Too high! Try a lower number.\n";
            }
            else {
                cout << "\nCongratulations! You guessed it!\n";
                cout << "The secret number was " << secretNumber << ".\n";
                cout << "Number of attempts: " << attempts << "\n";

                if (attempts <= 5) {
                    cout << "Amazing! You're a guessing genius!\n";
                }
                else if (attempts <= 10) {
                    cout << "Great job!\n";
                }
                else {
                    cout << "You got it! Try to beat your score next time.\n";
                }

                break;
            }
        }

        cout << "\nWould you like to play again? (y/n): ";
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "\nThanks for playing! Goodbye!\n";

    return 0;
}