#include "VerticalWinStrategy.h"

bool VerticalWinStrategy::check(const std::vector<std::vector<std::string>>& board,
                                 int lastRow, int lastCol, const std::string& marker) const {
    int count = 0;

    for (int i = -3; i <= 3; ++i) {
        int row = lastRow + i;

        if (row >= 0 && row < board.size()) {
            if (board[row][lastCol] == marker) {
                count++;
                if (count == 4) return true;
            } else {
                count = 0;
            }
        }
    }
    return false;
}
