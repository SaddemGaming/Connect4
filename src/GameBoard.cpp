// GameBoard.cpp
#include "GameBoard.h"

GameBoard::GameBoard() : m_rows(6), m_columns(7), m_grid(m_rows, std::vector<std::string>(m_columns, "-")) {}

bool GameBoard::makeMove(int column, const std::string& marker) {
    if (isValidMove(column)) {
        int row = findEmptyRow(column);
        m_grid[row][column] = marker;
        return true;
    }
    return false;
}

bool GameBoard::checkForWin(const std::string& marker) const {
    return checkHorizontalWin(marker) || checkVerticalWin(marker) || checkDiagonalWin(marker);
}

bool GameBoard::isBoardFull() const {
    return std::all_of(m_grid[0].begin(), m_grid[0].end(), [](const std::string& cell) { return cell != "-"; });
}

void GameBoard::printBoard() const {
    for (const auto& row : m_grid) {
        for (const auto& cell : row) {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
}

bool GameBoard::isValidMove(int column) const {
    return column >= 0 && column < m_columns && m_grid[0][column] == "-";
}

int GameBoard::findEmptyRow(int column) const {
    for (int row = m_rows - 1; row >= 0; --row) {
        if (m_grid[row][column] == "-") {
            return row;
        }
    }
    throw std::runtime_error("Column is full.");
}

bool GameBoard::checkHorizontalWin(const std::string& marker) const {
    for (const auto& row : m_grid) {
        for (size_t col = 0; col <= m_columns - 4; ++col) {
            if (row[col] == marker && row[col + 1] == marker &&
                row[col + 2] == marker && row[col + 3] == marker) {
                return true;
            }
        }
    }
    return false;
}

bool GameBoard::checkVerticalWin(const std::string& marker) const {
    for (size_t col = 0; col < m_columns; ++col) {
        for (size_t row = 0; row <= m_rows - 4; ++row) {
            if (m_grid[row][col] == marker && m_grid[row + 1][col] == marker &&
                m_grid[row + 2][col] == marker && m_grid[row + 3][col] == marker) {
                return true;
            }
        }
    }
    return false;
}

bool GameBoard::checkDiagonalWin(const std::string& marker) const {
    for (size_t row = 0; row <= m_rows - 4; ++row) {
        for (size_t col = 0; col <= m_columns - 4; ++col) {
            if (m_grid[row][col] == marker && m_grid[row + 1][col + 1] == marker &&
                m_grid[row + 2][col + 2] == marker && m_grid[row + 3][col + 3] == marker) {
                return true;
            }
        }
        for (size_t col = 3; col < m_columns; ++col) {
            if (m_grid[row][col] == marker && m_grid[row + 1][col - 1] == marker &&
                m_grid[row + 2][col - 2] == marker && m_grid[row + 3][col - 3] == marker) {
                return true;
            }
        }
    }
    return false;
}
