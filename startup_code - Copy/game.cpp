#include "game.h"
#include "helper.h"
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::string;
using std::vector;


Game::Game()
{
    board = new Board();
    player = new Player();
}

Game::~Game()
{
    delete board;
    delete player;
}


void Game::start() {
    if (!loadBoard()) return; // Exit if board loading fails or user quits
    initializePlayer();
    play();
}

bool Game::loadBoard() {

    cout << "\nYou can use the following commands to play the game:\n"
         << "load <g>\n"
         << "g: number of the game board to load\n"
         << "init <x>,<y>,<direction>\n"
         << "x: horizontal position of the vacuum cleaner in the room (between 0 & 9)\n"
         << "y: vertical position of the vacuum cleaner in the room (between 0 & 9)\n"
         << "direction: direction of the vacuum cleaner’s movement (north, east, south, west)\n"
         << "forward (or f)\n"
         << "turn_left (or l)\n"
         << "turn_right (or r)\n"
         << "quit\n\n";

    // Initial display of an empty board
    board->display(player);

    cout << "\nAt this stage of the program, only two commands are acceptable:\n"
         << "load <g>\n"
         << "quit\n";

    bool validCommandReceived = false;

    while (!validCommandReceived) {
        std::string command;
        std::cout << "Please enter your command: ";
        std::getline(std::cin, command);

        if (command.substr(0, 4) == "load") {
            int boardNumber = std::stoi(command.substr(5)); // Extract the board number
            board->load(boardNumber);
            std::cout << "Board " << boardNumber << " attempted to load.\n";
            board->display(player);// Assume load was successful
            validCommandReceived = true;
        } else if (command == "quit") {
            std::cout << "Quitting to main menu.\n";
            return false;
        } else {
            std::cout << "Invalid command. Please try again.\n";
        }
    }

    // Assuming initialization occurs after a valid 'load' command
    if (!initializePlayer()) {
        std::cout << "Initialization failed. Returning to main menu.\n";
        return false;
    }

    return true; // Proceed to the next part of the game
}

bool Game::initializePlayer() {
    std::cout << "Enter 'init <x>,<y>,<direction>': ";
    std::string input;
    std::getline(std::cin, input);

    std::vector<std::string> tokens;
    Helper::splitString(input, tokens, ",");

    if (tokens.size() != 3) {
        Helper::printInvalidInput();
        return false; // Ensure to return false because the function expects a boolean return type
    }

    int x, y;
    try {
        x = std::stoi(tokens[0]);
        y = std::stoi(tokens[1]);
    } catch (const std::exception& e) {
        std::cout << "Invalid position input. Please enter numbers for positions." << std::endl;
        return false;
    }

    std::string directionStr = tokens[2];
    Direction direction;

    if (directionStr == DIRECTION_NORTH) {
        direction = NORTH;
    } else if (directionStr == DIRECTION_EAST) {
        direction = EAST;
    } else if (directionStr == DIRECTION_SOUTH) {
        direction = SOUTH;
    } else if (directionStr == DIRECTION_WEST) {
        direction = WEST;
    } else {
        std::cout << "Invalid direction!" << std::endl;
        return false;
    }

    Position position{x, y};
    if (!board->placePlayer(position)) {
        std::cout << "Invalid initial position or position is blocked." << std::endl;
        return false;
    }

    player->initialisePlayer(&position, direction);
    std::cout << "Vacuum cleaner initialized at (" << x << ", " << y << ") facing " << directionStr << ".\n";

        while (true) {
        board->display(player);

        std::cout << "Enter command (forward, turn_left, turn_right, quit): ";
        std::getline(std::cin, input);

            if (input == COMMAND_QUIT) {
                std::cout << "Exiting..." << std::endl;
                return false;
            } else {
                std::cout << "Invalid command. Please try again." << std::endl;
            
            }
        }
}

void Game::play()
{
    //TODO
}
