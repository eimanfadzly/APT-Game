#include "board.h"
#include "player.h"

using std::vector;

const vector<vector<Cell>> Board::BOARD_1 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

const vector<vector<Cell>> Board::BOARD_2 =
{
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY },
    { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
    { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
};

Board::Board()
{
    board = new std::vector<std::vector<Cell>>(DEFAULT_BOARD_DIMENSION, std::vector<Cell>(DEFAULT_BOARD_DIMENSION, EMPTY));
}

Board::~Board()
{
    // Delete
    delete board;
}

void Board::load(int boardId) {
    // Load board if player chooses 1 or 2 option
    if (boardId == 1) {
        *board = BOARD_1;
    } else if (boardId == 2) {
        *board = BOARD_2;
    } else {
        std::cout << "Invalid board id!" << std::endl;
    }
}

bool Board::placePlayer(Position position)
{
    // Check if the position is within bounds and the cell is not BLOCKED
    if (position.x < 0 || position.x >= DEFAULT_BOARD_DIMENSION || position.y < 0 || position.y >= DEFAULT_BOARD_DIMENSION) {
        return false;
    }
    if ((*board)[position.x][position.y] == BLOCKED) {
        return false;
    }
    (*board)[position.x][position.y] = PLAYER;
    return true;
}

PlayerMove Board::movePlayerForward(Player* player)
{
    // TODO
    return PLAYER_MOVED; // A flag to indicate one of the 3 possible outcomes
}

void Board::display(Player* player) {
    if (player == nullptr) {
        std::cout << "| |0|1|2|3|4|5|6|7|8|9|" << std::endl;
        for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i) {
            std::cout << "|" << i << "|";
            for (int j = 0; j < DEFAULT_BOARD_DIMENSION; ++j) {
                std::cout << EMPTY_OUTPUT << "|";
            }
            std::cout << std::endl;
        }
    } else {
        std::cout << "| |0|1|2|3|4|5|6|7|8|9|" << std::endl;
        for (int i = 0; i < DEFAULT_BOARD_DIMENSION; ++i) {
            std::cout << "|" << i << "|";
            for (int j = 0; j < DEFAULT_BOARD_DIMENSION; ++j) {
                if ((*board)[i][j] == EMPTY) {
                    std::cout << EMPTY_OUTPUT << "|";
                } else if ((*board)[i][j] == BLOCKED) {
                    std::cout << BLOCKED_OUTPUT << "|";
                } else if ((*board)[i][j] == PLAYER && player->position.x == i && player->position.y == j) {
                    player->displayDirection();
                    std::cout << LINE_OUTPUT << "|";
                } else {
                    std::cout << EMPTY_OUTPUT << "|";
                }
            }
            std::cout << std::endl;
        }
    }
}


