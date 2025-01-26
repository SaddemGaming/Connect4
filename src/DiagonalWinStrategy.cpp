#include "DiagonalWinStrategy.h"

bool DiagonalWinStrategy::check(const std::vector<std::vector<std::string>>& board,
                                 int lastRow, int lastCol, const std::string& marker) const {
    int count = 0;

    // Top-left to bottom-right
    for (int i = -3; i <= 3; ++i) {
        int row = lastRow + i;
        int col = lastCol + i;
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size()) {
            if (board[row][col] == marker) {
                count++;
                if (count == 4) return true;
            } else {
                count = 0;
            }
        }
    }

    count = 0;

    // Bottom-left to top-right
    for (int i = -3; i <= 3; ++i) {
        int row = lastRow - i;
        int col = lastCol + i;
        if (row >= 0 && row < board.size() && col >= 0 && col < board[0].size()) {
            if (board[row][col] == marker) {
                count++;
                if (count == 4) return true;
            } else {
                count = 0;
            }
        }
    }

    return false;
}
