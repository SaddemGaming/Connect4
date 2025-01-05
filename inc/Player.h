#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

/**
 * @brief Abstract base class representing a player.
 */
class Player {
public:
    /**
     * @brief Gets the player's name.
     * @return The player's name.
     */
    virtual std::string getName() const = 0;

    /**
     * @brief Gets the player's marker.
     * @return The player's marker.
     */
    virtual std::string getMarker() const = 0;

    /**
     * @brief Determines the player's move.
     * @param board The current game board.
     * @return The column number for the move.
     */
    virtual int getMove(const std::vector<std::vector<std::string>>& board) const = 0;

    /**
     * @brief Virtual destructor.
     */
    virtual ~Player() = default;
};

#endif // PLAYER_H
