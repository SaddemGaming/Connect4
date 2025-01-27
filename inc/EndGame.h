#ifndef ENDGAME_H
#define ENDGAME_H

#include <QDialog>

namespace Ui {
class EndGame;
}

class EndGame : public QDialog {
    Q_OBJECT

public:
    explicit EndGame(const QString &message, QWidget *parent = nullptr);
    ~EndGame();

signals:
    void replayRequested(); // Signal emitted for replay
    void quitRequested();   // Signal emitted for quit

private:
    std::unique_ptr<Ui::EndGame> ui;
};

#endif // ENDGAME_H
