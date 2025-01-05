#ifndef GAMESCREEN_H
#define GAMESCREEN_H

#include <QMainWindow>
#include "GameBoard.h"
#include "Player.h"

namespace Ui {
class GameScreen;
}

class GameScreen : public QMainWindow {
    Q_OBJECT

public:
    explicit GameScreen(Player *player1, Player *player2, bool isPvC, QWidget *parent = nullptr);
    ~GameScreen();

private:
    Ui::GameScreen *ui;
    GameBoard gameBoard;
    Player *player1;
    Player *player2;
    Player *currentPlayer;
    bool PvC;

    void updateBoard();
    void checkGameOver();
    void switchTurn();

private slots:
    void onMakeMoveButtonClicked();
};

#endif // GAMESCREEN_H
