#include "HorizontalWinStrategy.h"

bool HorizontalWinStrategy::check(const std::vector<std::vector<std::string>>& board,
                                   int lastRow, int lastCol, const std::string& marker) const {
    int count = 0;

    for (int i = -3; i <= 3; ++i) {
        int col = lastCol + i;

        if (col >= 0 && col < board[0].size()) {
            if (board[lastRow][col] == marker) {
                count++;
                if (count == 4) return true;
            } else {
                count = 0;
            }
        }
    }
    return false;
}
