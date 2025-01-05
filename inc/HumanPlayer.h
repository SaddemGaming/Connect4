#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include "Player.h"

/**
 * @brief Represents a human player.
 */
class HumanPlayer : public Player {
public:
    /**
     * @brief Constructs a HumanPlayer object.
     * @param name The name of the player.
     * @param marker The marker used by the player.
     */
    HumanPlayer(const std::string& name, const std::string& marker);

    std::string getName() const override;
    std::string getMarker() const override;
    int getMove(const std::vector<std::vector<std::string>>& board) const override;

private:
    std::string m_name;
    std::string m_marker;
};

#endif // HUMANPLAYER_H
