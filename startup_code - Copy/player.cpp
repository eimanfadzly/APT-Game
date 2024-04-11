#include "player.h"

Position::Position() : x(0), y(0) {}

Position::Position(int x, int y) : x(x), y(y) {}


Player::Player() : moves(0) {}

void Player::initialisePlayer(Position* position, Direction direction)
{
    this->position = *position; // Dereferencing the pointer to copy values
    this->direction = direction;
    moves = 0;
}

void Player::turnDirection(TurnDirection turnDirection)
{
    //TODO
}

Position Player::getNextForwardPosition()
{
    //TODO
    return Position();
}

void Player::updatePosition(Position position)
{
    //TODO
}

void Player::displayDirection() {
    if (direction == NORTH) {
        std::cout << DIRECTION_ARROW_OUTPUT_NORTH;
    } else if (direction == EAST) {
        std::cout << DIRECTION_ARROW_OUTPUT_EAST;
    } else if (direction == SOUTH) {
        std::cout << DIRECTION_ARROW_OUTPUT_SOUTH;
    } else if (direction == WEST) {
        std::cout << DIRECTION_ARROW_OUTPUT_WEST;
    }
}