// ComputerPlayer.cpp
#include "ComputerPlayer.h"
#include <cstdlib>

ComputerPlayer::ComputerPlayer(const std::string& name, const std::string& marker)
    : m_name(name), m_marker(marker) {}

std::string ComputerPlayer::getName() const {
    return m_name;
}

std::string ComputerPlayer::getMarker() const {
    return m_marker;
}

int ComputerPlayer::getMove(const std::vector<std::vector<std::string>>& board) const {
    std::srand(std::time(nullptr));
    int column;
    do {
        column = std::rand() % board[0].size();
    } while (!isValidMove(board, column));
    return column;
}

bool ComputerPlayer::isValidMove(const std::vector<std::vector<std::string>>& board, int column) const {
    return column >= 0 && column < board[0].size() && board[0][column] == "-";
}
