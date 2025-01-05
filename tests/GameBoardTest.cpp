#include "GameBoard.h"
#include <gtest/gtest.h>

// Test GameBoard Initialization
TEST(GameBoardTest, InitializesWithEmptyGrid) {
    GameBoard board;

    const auto &grid = board.getGrid();
    for (const auto &row : grid) {
        for (const auto &cell : row) {
            EXPECT_EQ(cell, "-"); // Each cell should be empty
        }
    }
}

// Test Making a Move
TEST(GameBoardTest, MakesMoveSuccessfully) {
    GameBoard board;

    EXPECT_TRUE(board.makeMove(0, "X"));
    EXPECT_EQ(board.getGrid()[5][0], "X"); // Bottom row
}

// Test Invalid Move
TEST(GameBoardTest, FailsOnInvalidMove) {
    GameBoard board;

    EXPECT_FALSE(board.makeMove(-1, "X")); // Negative column
    EXPECT_FALSE(board.makeMove(7, "X")); // Out-of-bound column
}

// Test Winning Condition
TEST(GameBoardTest, DetectsHorizontalWin) {
    GameBoard board;

    board.makeMove(0, "X");
    board.makeMove(1, "X");
    board.makeMove(2, "X");
    board.makeMove(3, "X");

    EXPECT_TRUE(board.checkForWin("X"));
}

// Test Full Board
TEST(GameBoardTest, DetectsFullBoard) {
    GameBoard board;

    for (int col = 0; col < 7; ++col) {
        for (int row = 0; row < 6; ++row) {
            board.makeMove(col, row % 2 == 0 ? "X" : "O");
        }
    }

    EXPECT_TRUE(board.isBoardFull());
    EXPECT_FALSE(board.makeMove(0, "X")); // Full board should not allow new moves
}
