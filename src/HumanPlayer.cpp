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
    throw std::runtime_error("HumanPlayer::getMove should not be called directly in a GUI-based application.");
}
