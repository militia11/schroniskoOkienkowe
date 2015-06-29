#ifndef DODAJPSADIALOG_H
#define DODAJPSADIALOG_H

#include <QDialog>

namespace Ui {
class DodajPsaDialog;
}

class DodajPsaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajPsaDialog(QWidget *parent = 0);
    ~DodajPsaDialog();

private:
    Ui::DodajPsaDialog *ui;
};

#endif // DODAJPSADIALOG_H
