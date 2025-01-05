#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H

#include "Player.h"
#include <ctime>

/**
 * @brief Represents a computer player.
 */
class ComputerPlayer : public Player {
public:
    /**
     * @brief Constructs a ComputerPlayer object.
     * @param name The name of the computer player.
     * @param marker The marker used by the computer player.
     */
    ComputerPlayer(const std::string& name, const std::string& marker);

    std::string getName() const override;
    std::string getMarker() const override;
    int getMove(const std::vector<std::vector<std::string>>& board) const override;

private:
    std::string m_name;
    std::string m_marker;

    /**
     * @brief Checks if a move is valid.
     * @param board The game board.
     * @param column The column to check.
     * @return True if the move is valid, false otherwise.
     */
    bool isValidMove(const std::vector<std::vector<std::string>>& board, int column) const;
};

#endif // COMPUTERPLAYER_H
