#include "MainWindow.h"
#include <QApplication>

/**
 * @brief Main entry point of the application.
 */
int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.show();
    return app.exec();
}
