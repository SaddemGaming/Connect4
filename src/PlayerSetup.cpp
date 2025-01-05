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
    Player *player1 = new HumanPlayer("Player 1", "X");
    Player *player2 = (ui->gameModeComboBox->currentIndex() == 1)
                      ? static_cast<Player *>(new HumanPlayer("Player 2", "O"))
                      : static_cast<Player *>(new ComputerPlayer("Computer", "O"));

    GameScreen *gameScreen = new GameScreen(player1, player2, ui->gameModeComboBox->currentIndex() == 0);

    gameScreen->show();

    // Emit accepted signal to notify MainWindow to close
    accept();
}
