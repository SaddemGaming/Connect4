#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>
#include <memory>
#include "GameBoard.h"
#include "Player.h"

namespace Ui {
    class GameScreen; // Forward declaration
}

class GameScreen : public QMainWindow {
    Q_OBJECT

public:
    explicit GameScreen(std::unique_ptr<Player> player1,
                        std::unique_ptr<Player> player2,
                        bool isPvC,
                        QWidget* parent = nullptr);
    ~GameScreen();

private:
    std::unique_ptr<Ui::GameScreen> ui;
    GameBoard gameBoard;
    std::unique_ptr<Player> player1;
    std::unique_ptr<Player> player2;
    Player* currentPlayer;
    bool PvC;

    void updateBoard();
    void checkGameOver();
    void switchTurn();

private slots:
    void onMakeMoveButtonClicked();
};

#endif // GAMESCREEN_H
