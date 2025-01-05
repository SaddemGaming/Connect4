#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "PlayerSetup.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);

    // Connect the "Start Game" button
    connect(ui->startGameButton, &QPushButton::clicked, this, &MainWindow::onStartGame);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::onStartGame() {
    PlayerSetup *playerSetupDialog = new PlayerSetup(this);

    // Connect the signal from PlayerSetup to close MainWindow
    connect(playerSetupDialog, &PlayerSetup::accepted, this, &MainWindow::close);

    playerSetupDialog->exec();
}
