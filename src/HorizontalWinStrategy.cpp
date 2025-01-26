#include "HorizontalWinStrategy.h"

bool HorizontalWinStrategy::check(const std::vector<std::vector<std::string>>& board,
                                   int lastRow, int lastCol, const std::string& marker) const {
    int count = 0;
    for (int col = 0; col < board[0].size(); ++col) {
        if (board[lastRow][col] == marker) {
            count++;
            if (count == 4) return true;
        } else {
            count = 0;
        }
    }
    return false;
}
