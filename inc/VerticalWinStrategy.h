#ifndef VERTICALWINSTRATEGY_H
#define VERTICALWINSTRATEGY_H

#include "WinConditionStrategy.h"

class VerticalWinStrategy : public WinConditionStrategy {
public:
    bool check(const std::vector<std::vector<std::string>>& board,
               int lastRow, int lastCol, const std::string& marker) const override;
};

#endif // VERTICALWINSTRATEGY_H
