#ifndef DIAGONALWINSTRATEGY_H
#define DIAGONALWINSTRATEGY_H

#include "WinConditionStrategy.h"

class DiagonalWinStrategy : public WinConditionStrategy {
public:
    bool check(const std::vector<std::vector<std::string>>& board,
               int lastRow, int lastCol, const std::string& marker) const override;
};

#endif // DIAGONALWINSTRATEGY_H
