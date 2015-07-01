#ifndef WYDAJPSADIALOG_H
#define WYDAJPSADIALOG_H

#include <QDialog>
#include <QTableView>

namespace Ui {
class WydajPsaDialog;
}

class WydajPsaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit WydajPsaDialog(QTableView *widok, QWidget *parent = 0);
    ~WydajPsaDialog();
    int getRzad() const;

private:
    void aktualizujListe();

private slots:
    void on_buttonBox_accepted();
    void on_pushButton_clicked();
    void on_buttonBox_rejected();

private:
    QTableView* widok;
    Ui::WydajPsaDialog *ui;
    int rzad;
};

#endif // WYDAJPSADIALOG_H
