#include "game.h"
#include "helper.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;

// Forward declaration of helper functions
void showMainMenu();
void showStudentInformation();
void handleInvalidInput();

int main() {
    Game game; // Create an instance of Game
    bool running = true;
    while (running) {
        showMainMenu();
        std::string choice;
        std::getline(std::cin, choice);

        if (choice == "1") {
            game.start(); // Start the game using the Game class
        } else if (choice == "2") {
            showStudentInformation();
        } else if (choice == "3") {
            running = false;
        } else {
            handleInvalidInput();
        }
    }

    std::cout << "Good bye!\n";
    return EXIT_SUCCESS;
}

void showMainMenu() {
    std::cout << "Welcome to Vacuum Cleaning Game!\n"
              << "--------------------\n"
              << "1. Play Game\n"
              << "2. Show student information\n"
              << "3. Quit\n\n"
              << "Please enter your choice: ";
}

void showStudentInformation() {
    std::cout << "-----------------------------------\n"
              << "Name: <your full name>\n"
              << "Student ID: <your student number>\n"
              << "Email: <your email address>\n"
              << "-----------------------------------\n"
              << "Please enter your choice: ";
}

void handleInvalidInput() {
    // Simply return to main loop for re-display of menu
    std::cout << "Invalid input, please try again.\n";
}

