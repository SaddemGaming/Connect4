#include "VerticalWinStrategy.h"

bool VerticalWinStrategy::check(const std::vector<std::vector<std::string>>& board,
                                 int lastRow, int lastCol, const std::string& marker) const {
    int count = 0;
    for (int row = 0; row < board.size(); ++row) {
        if (board[row][lastCol] == marker) {
            count++;
            if (count == 4) return true;
        } else {
            count = 0;
        }
    }
    return false;
}
