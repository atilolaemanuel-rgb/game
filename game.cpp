#include <iostream>
#include <cstdlib>
#include <ctime>

int main() {
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    std::cout << "WELCOME TO GUESS THE NUMBER :)" << std::endl;
    std::cout << "Select difficulty: 1=Easy (10 attempts), 2=Medium (7 attempts), 3=Hard (5 attempts)" << std::endl;
    int difficultyLevel = 2;
    std::cout << "Enter difficulty (1-3) [default 2]: ";
    if (!(std::cin >> difficultyLevel)) {
        return 1;
    }

    int maxAttempts = 7;
    if (difficultyLevel == 1) maxAttempts = 10;
    else if (difficultyLevel == 3) maxAttempts = 5;

    int numberToGuess = (std::rand() % 20) + 1; // 1..20

    std::cout << "Guess a number between 1 and 20. You have " << maxAttempts << " attempts." << std::endl;

    int attempts = 0;
    while (attempts < maxAttempts) {
        int userGuess = 0;
        std::cout << "Your guess: ";
        if (!(std::cin >> userGuess)) {
            std::cout << "Invalid input. Exiting." << std::endl;
            return 1;
        }
        attempts++;

        if (userGuess == numberToGuess) {
            std::cout << "Congratulations, you guessed the number in " << attempts << " attempt(s)!" << std::endl;
            return 0;
        }

        if (userGuess < numberToGuess) std::cout << "Too low.";
        else std::cout << "Too high.";

        std::cout << " Attempts left: " << (maxAttempts - attempts) << std::endl;
    }

    std::cout << "Out of attempts. The number was " << numberToGuess << "." << std::endl;
    return 0;
}