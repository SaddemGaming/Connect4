#ifndef HORIZONTALWINSTRATEGY_H
#define HORIZONTALWINSTRATEGY_H

#include "WinConditionStrategy.h"

class HorizontalWinStrategy : public WinConditionStrategy {
public:
    bool check(const std::vector<std::vector<std::string>>& board,
               int lastRow, int lastCol, const std::string& marker) const override;
};

#endif // HORIZONTALWINSTRATEGY_H
