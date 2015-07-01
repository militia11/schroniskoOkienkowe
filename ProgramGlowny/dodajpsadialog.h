#ifndef DODAJPSADIALOG_H
#define DODAJPSADIALOG_H

#include <QDialog>
#include "pies.h"

namespace Ui {
class DodajPsaDialog;
}

class DodajPsaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajPsaDialog(QWidget *parent = 0);
    ~DodajPsaDialog();

    int getId() const;
    QString getImie() const;
    int getWiek() const;
    RodzajPsa getRodzaj() const;
    QString getRasa() const;
    void setId(int noweId);
    void setImie(QString noweImie);
    void setWiek(int nowyWiek);
    void setRodzaj(QString nowyRodzaj);
    void setRasa(QString nowaRasa);

private:
    void sprawdzIUstawRodzaj();
    void ustawParametry();

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DodajPsaDialog *ui;
    int id;
    QString imie;
    int wiek;
    RodzajPsa rodzaj;
    QString rasa;
};

#endif // DODAJPSADIALOG_H
