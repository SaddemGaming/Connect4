#include "GameScreen.h"
#include "ui_GameScreen.h"
#include "EndGame.h"
#include "PlayerSetup.h"

GameScreen::GameScreen(Player *p1, Player *p2, bool isPvC, QWidget *parent)
    : QMainWindow(parent),
      ui(new Ui::GameScreen),
      player1(p1),
      player2(p2),
      PvC(isPvC),
      currentPlayer(p1) {
    ui->setupUi(this);

    connect(ui->makeMoveButton, &QPushButton::clicked, this, &GameScreen::onMakeMoveButtonClicked);

    updateBoard();
    ui->statusLabel->setText(QString("%1's Turn").arg(QString::fromStdString(currentPlayer->getName())));
}

GameScreen::~GameScreen() {
    delete player1;
    delete player2;
    delete ui;
}

void GameScreen::updateBoard() {
    const auto &grid = gameBoard.getGrid();
    for (int row = 0; row < 6; ++row) {
        for (int col = 0; col < 7; ++col) {
            QLabel *label = qobject_cast<QLabel *>(ui->gridLayout->itemAtPosition(row, col)->widget());
            if (label) {
                label->setText(QString::fromStdString(grid[row][col]));
            }
        }
    }
}

void GameScreen::onMakeMoveButtonClicked() {
    bool ok;
    int column = ui->ColumnInput->text().toInt(&ok) - 1;

    if (!ok || column < 0 || column >= 7 || !gameBoard.makeMove(column, currentPlayer->getMarker())) {
        ui->statusLabel->setText("Invalid move. Try again.");
        return;
    }

    updateBoard();
    checkGameOver();
    switchTurn();

    // If it's the computer's turn, make its move automatically
    if (PvC) {
        int computerMove = currentPlayer->getMove(gameBoard.getGrid());
        gameBoard.makeMove(computerMove, currentPlayer->getMarker());
        updateBoard();
        checkGameOver();
        switchTurn();
    }

    ui->statusLabel->setText(QString("%1's Turn").arg(QString::fromStdString(currentPlayer->getName())));
}

void GameScreen::checkGameOver() {
    if (gameBoard.checkForWin(currentPlayer->getMarker())) {
        EndGame *endGame = new EndGame(QString("%1 Wins!").arg(QString::fromStdString(currentPlayer->getName())), this);

        // Handle signals from EndGame dialog
        connect(endGame, &EndGame::replayRequested, this, [this]() {
            this->close(); // Close the GameScreen
            PlayerSetup *setup = new PlayerSetup(); // Restart setup
            setup->show();
        });

        connect(endGame, &EndGame::quitRequested, this, [this]() {
            qApp->quit(); // Quit the application
        });

        endGame->exec(); // Show EndGame dialog
    } else if (gameBoard.isBoardFull()) {
        EndGame *endGame = new EndGame("It's a Draw!", this);

        // Handle signals from EndGame dialog
        connect(endGame, &EndGame::replayRequested, this, [this]() {
            this->close(); // Close the GameScreen
            PlayerSetup *setup = new PlayerSetup(); // Restart setup
            setup->show();
        });

        connect(endGame, &EndGame::quitRequested, this, [this]() {
            qApp->quit(); // Quit the application
        });

        endGame->exec(); // Show EndGame dialog
    }
}


void GameScreen::switchTurn() {
    currentPlayer = (currentPlayer == player1) ? player2 : player1;
}
