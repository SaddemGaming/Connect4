// GameBoard.cpp
#include <stdexcept>
#include "GameBoard.h"
#include "HorizontalWinStrategy.h"
#include "VerticalWinStrategy.h"
#include "DiagonalWinStrategy.h"

GameBoard::GameBoard()
    : m_rows(DEFAULT_ROWS), m_columns(DEFAULT_COLUMNS),
      m_grid(m_rows, std::vector<std::string>(m_columns, EMPTY_CELL)),
      m_lastRow(-1),
      m_lastColumn(-1) {
    // Initialize win condition strategies
    winStrategies.push_back(std::make_unique<HorizontalWinStrategy>());
    winStrategies.push_back(std::make_unique<VerticalWinStrategy>());
    winStrategies.push_back(std::make_unique<DiagonalWinStrategy>());
}


bool GameBoard::makeMove(int column, const std::string& marker) {
    if (isValidMove(column)) {
        int row = findEmptyRow(column);
        m_grid[row][column] = marker;
        m_lastRow = row;
        m_lastColumn = column;
        return true;
    }
    return false;
}

bool GameBoard::checkForWin(const std::string& marker) const {
    for (const auto& strategy : winStrategies) {
        if (strategy->check(m_grid, m_lastRow, m_lastColumn, marker)) {
            return true;
        }
    }
    return false;
}

bool GameBoard::isBoardFull() const {
    return std::all_of(m_grid[0].begin(), m_grid[0].end(),
                       [](const std::string& cell) { return cell != EMPTY_CELL; });
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