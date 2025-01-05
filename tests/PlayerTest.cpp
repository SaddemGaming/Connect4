#include "HumanPlayer.h"
#include "ComputerPlayer.h"
#include "GameBoard.h"
#include <gtest/gtest.h>

// Test HumanPlayer
TEST(HumanPlayerTest, InitializesCorrectly) {
    HumanPlayer player("Player 1", "X");

    EXPECT_EQ(player.getName(), "Player 1");
    EXPECT_EQ(player.getMarker(), "X");
}

// Test ComputerPlayer
TEST(ComputerPlayerTest, MakesValidMoves) {
    ComputerPlayer computer("Computer", "O");
    GameBoard board;

    int move = computer.getMove(board.getGrid());
    EXPECT_GE(move, 0); // Valid column
    EXPECT_LT(move, 7); // Valid column
}
