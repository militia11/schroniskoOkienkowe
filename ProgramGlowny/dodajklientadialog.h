#ifndef DODAJKLIENTADIALOG_H
#define DODAJKLIENTADIALOG_H

#include <QDialog>
#include <QRegExp>

namespace Ui {
class DodajKlientaDialog;
}

class DodajKlientaDialog : public QDialog
{
    Q_OBJECT

public:
    explicit DodajKlientaDialog(QWidget *parent = 0);
    ~DodajKlientaDialog();

    int getId() const;
    QString getImie() const;
    QString getNazwisko() const;
    QString getNumerTelefonu() const;
    QString getUlica() const;
    int getNumerDomu() const;
    QString getMiasto() const;
    QString getKodPocztowy() const;
    void setId(int noweId);
    void setImie(QString noweImie);
    void setNazwisko(QString noweNazwisko);
    void setNumerTelefonu(QString nowyNumerTel);
    void setUlica(QString nowaUlica);
    void setNumerDomu(int nowyNumerDomu);
    void setMiasto(QString noweMiasto);
    void setKodPocztowy(QString nowyKodPocztowy);

private slots:
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

private:
    Ui::DodajKlientaDialog *ui;
    static QRegExp formatNrTelefonu;
    int id;
    QString imie;
    QString nazwisko;
    QString numerTelefonu;
    QString ulica;
    int numerDomu;
    QString miasto;
    QString kodPocztowy;
};

#endif // DODAJKLIENTADIALOG_H
