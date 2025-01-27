#include "GameScreen.h"
#include "ui_GameScreen.h"
#include "EndGame.h"
#include "PlayerSetup.h"

GameScreen::GameScreen(std::unique_ptr<Player> p1, std::unique_ptr<Player> p2, bool isPvC, QWidget *parent)
    : QMainWindow(parent),
      ui(std::make_unique<Ui::GameScreen>()),
      player1(std::move(p1)),
      player2(std::move(p2)),
      PvC(isPvC),
      currentPlayer(player1.get()) {
    ui->setupUi(this);

    connect(ui->makeMoveButton, &QPushButton::clicked, this, &GameScreen::onMakeMoveButtonClicked);

    drawBoard();
    ui->statusLabel->setText(QString("%1's Turn").arg(QString::fromStdString(currentPlayer->getName())));
}

GameScreen::~GameScreen() = default;

void GameScreen::drawBoard() {
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

void GameScreen::updateBoard() {
    int lastRow = gameBoard.getLastRow();
    int lastCol = gameBoard.getLastColumn();

    const auto& grid = gameBoard.getGrid();
    QString marker = QString::fromStdString(grid[lastRow][lastCol]);

    QLabel* label = qobject_cast<QLabel*>(ui->gridLayout->itemAtPosition(lastRow, lastCol)->widget());
    if (label) {
        label->setText(marker);
    }
}


void GameScreen::onMakeMoveButtonClicked() {
    bool ok;
    int column = ui->ColumnInput->text().toInt(&ok) - 1;

    if (!gameBoard.makeMove(column, currentPlayer->getMarker())) {
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
        auto endGame = std::make_unique<EndGame>(
            QString("%1 Wins!").arg(QString::fromStdString(currentPlayer->getName())), this);

        connect(endGame.get(), &EndGame::replayRequested, this, [this]() {
            this->close();
            auto setup = std::make_unique<PlayerSetup>();
            setup->show();
            setup.release();
        });

        connect(endGame.get(), &EndGame::quitRequested, this, []() {
            qApp->quit();
        });

        endGame->exec();
    } else if (gameBoard.isBoardFull()) {
        auto endGame = std::make_unique<EndGame>("It's a Draw!", this);

        connect(endGame.get(), &EndGame::replayRequested, this, [this]() {
            this->close();
            auto setup = std::make_unique<PlayerSetup>();
            setup->show();
            setup.release();
        });

        connect(endGame.get(), &EndGame::quitRequested, this, []() {
            qApp->quit();
        });

        endGame->exec();
    }
}

void GameScreen::switchTurn() {
    currentPlayer = (currentPlayer == player1.get()) ? player2.get() : player1.get();
}