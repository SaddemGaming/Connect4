#include "EndGame.h"
#include "ui_EndGame.h"

EndGame::EndGame(const QString &message, QWidget *parent)
    : QDialog(parent), ui(new Ui::EndGame) {
    ui->setupUi(this);

    // Set the result message
    ui->endMessageLabel->setText(message);

    // Connect the buttons
    connect(ui->replayButton, &QPushButton::clicked, this, [this]() {
        emit replayRequested(); // Emit replay signal
        accept();               // Close dialog
    });

    connect(ui->quitButton, &QPushButton::clicked, this, [this]() {
        emit quitRequested(); // Emit quit signal
        reject();             // Close dialog
    });
}

EndGame::~EndGame() {
    delete ui;
}
