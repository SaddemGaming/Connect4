// HumanPlayer.cpp
#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(const std::string& name, const std::string& marker)
    : m_name(name), m_marker(marker) {}

std::string HumanPlayer::getName() const {
    return m_name;
}

std::string HumanPlayer::getMarker() const {
    return m_marker;
}

int HumanPlayer::getMove(const std::vector<std::vector<std::string>>& board) const {
    int column;
    std::cout << m_name << " (" << m_marker << "), enter your move (0-6): ";
    std::cin >> column;
    return column;
}
