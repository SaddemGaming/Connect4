#ifndef GAMEBOARD_H
#define GAMEBOARD_H

#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

/**
 * @brief Represents the Connect 4 game board.
 */
class GameBoard {
public:
    /**
     * @brief Constructs the game board.
     */
    GameBoard();

    /**
     * @brief Makes a move on the board.
     * @param column The column for the move.
     * @param marker The player's marker.
     * @return True if the move was successful, false otherwise.
     */
    bool makeMove(int column, const std::string& marker);

    /**
     * @brief Checks if a player has won.
     * @param marker The player's marker.
     * @return True if the player has won, false otherwise.
     */
    bool checkForWin(const std::string& marker) const;

    /**
     * @brief Checks if the board is full.
     * @return True if the board is full, false otherwise.
     */
    bool isBoardFull() const;

    /**
     * @brief Prints the game board to the console.
     */
    void printBoard() const;

    /**
     * @brief Gets the current board grid.
     * @return The grid of the board.
     */
    const std::vector<std::vector<std::string>>& getGrid() const { return m_grid; }

private:
    int m_rows;
    int m_columns;
    std::vector<std::vector<std::string>> m_grid;

    bool isValidMove(int column) const;
    int findEmptyRow(int column) const;
    bool checkHorizontalWin(const std::string& marker) const;
    bool checkVerticalWin(const std::string& marker) const;
    bool checkDiagonalWin(const std::string& marker) const;
};

#endif // GAMEBOARD_H
