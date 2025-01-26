#include "PlayerSetup.h"
#include "ui_PlayerSetup.h"
#include "GameScreen.h"
#include "HumanPlayer.h"
#include "ComputerPlayer.h"

PlayerSetup::PlayerSetup(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PlayerSetup) {
    ui->setupUi(this);

    // Connect the "Confirm" button
    connect(ui->confirmButton, &QPushButton::clicked, this, &PlayerSetup::onConfirm);
}

PlayerSetup::~PlayerSetup() {
    delete ui;
}

void PlayerSetup::onConfirm() {
    std::unique_ptr<Player> player1 = std::make_unique<HumanPlayer>("Player 1", "X");
    std::unique_ptr<Player> player2;

    if (ui->gameModeComboBox->currentIndex() == 1) {
        player2 = std::make_unique<HumanPlayer>("Player 2", "O");
    } else {
        player2 = std::make_unique<ComputerPlayer>("Computer", "O");
    }

    GameScreen *gameScreen = new GameScreen(std::move(player1), std::move(player2), ui->gameModeComboBox->currentIndex() == 0);

    gameScreen->show();

    accept(); // Notify MainWindow to close
}
