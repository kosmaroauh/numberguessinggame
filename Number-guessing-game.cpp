// Number-guessing-game.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <ctime>

class User {
public:
  
    
    void  diff(int a) {

        while (true) {
            std::cout << "Please enter 1 (easy), 2(medium) , or 3(hard)." << std::endl;
            std::cin >> a;
            if (a == 1 || a == 2 || a == 3) {
                
                break;

            }
        }
        
        if (a == 1) {
            std::cout << "Great! You have selected the Easy difficulty level." << std::endl;
            chances = 10;
        }
        else if (a == 2) {
            std::cout << "Great! You have selected the Medium difficulty level." << std::endl;
            chances = 5;
        }
        else if (a == 3) {
            std::cout << "Great! You have selected the Hard difficulty level." << std::endl;
            chances = 3;
        }
        else {
            std::cout << "Invalid choice! Defaulting to Easy difficulty." << std::endl;
            chances = 10;
        }
        
        


    };
    
    
    User() {
        std::srand(std::time(0));  
        num = (std::rand() % 100 + 1);  
        chances = 0;  
    }
    void guessNum() {
        int guess;
        while (chances > 0) {
            std::cout << "Enter your guess (remaining chances: " << chances << "): ";
            std::cin >> guess;

            if (guess < num) {
                std::cout << "Too low! Try again." << std::endl;
            }
            else if (guess > num) {
                std::cout << "Too high! Try again." << std::endl;
            }
            else {
                std::cout << "Congratulations! You guessed the number!" << std::endl;
                return;  
            }
            chances--;
        }

        std::cout << "Sorry, you've run out of chances! The correct number was " << num << "." << std::endl;
    }
    
private:
    int num;
    int chances;
};

int main() {
    User user;

    std::cout << "Welcome to the Number Guessing Game!" << std::endl;
    std::cout << "I'm thinking of a number between 1 and 100." << std::endl;

    int difficulty;
    std::cout << "Please select the difficulty level:" << std::endl;
    std::cout << "1. Easy (10 chances)" << std::endl;
    std::cout << "2. Medium (5 chances)" << std::endl;
    std::cout << "3. Hard (3 chances)" << std::endl;
    std::cout << "Enter your choice:" << std::endl;
    std::cin >> difficulty;

    user.diff(difficulty);  
    std::cout << "Let's start the game!" << std::endl;
    user.guessNum();  

    return 0;
}

    