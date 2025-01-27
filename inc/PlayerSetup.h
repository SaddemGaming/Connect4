#ifndef PLAYERSETUP_H
#define PLAYERSETUP_H

#include <QDialog>

namespace Ui {
class PlayerSetup;
}

class PlayerSetup : public QDialog {
    Q_OBJECT

public:
    explicit PlayerSetup(QWidget *parent = nullptr);
    ~PlayerSetup();

private slots:
    void onConfirm();

private:
    std::unique_ptr<Ui::PlayerSetup> ui;
};

#endif // PLAYERSETUP_H
