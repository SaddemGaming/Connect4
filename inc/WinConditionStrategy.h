#ifndef WINCONDITIONSTRATEGY_H
#define WINCONDITIONSTRATEGY_H

#include <vector>
#include <string>

class WinConditionStrategy {
public:
    virtual ~WinConditionStrategy() = default;

    /**
     * @brief Checks if a win condition is satisfied.
     * @param board The game board grid.
     * @param lastRow The row of the last move.
     * @param lastCol The column of the last move.
     * @param marker The player's marker.
     * @return True if the win condition is satisfied, false otherwise.
     */
    virtual bool check(const std::vector<std::vector<std::string>>& board, 
                       int lastRow, int lastCol, const std::string& marker) const = 0;
};

#endif // WINCONDITIONSTRATEGY_H
