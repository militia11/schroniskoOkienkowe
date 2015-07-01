#include "delegatdanych.h"

#include <QSpinBox>
#include <QPainter>
#include <QLineEdit>
#include <QMessageBox>
#include <QRegExpValidator>
#include <QRegExp>
#include <QComboBox>

DelegatDanych::DelegatDanych(QObject *parent) :QItemDelegate(parent){}

QWidget* DelegatDanych::createEditor(QWidget *parent,const QStyleOptionViewItem &option,const QModelIndex &index) const {
    QString field = index.model()->headerData(index.column(), Qt::Horizontal).toString();

    // te 3 nizej polaczyc w jedno : !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    if (field == "Wiek" ) {
        QSpinBox* editor = new QSpinBox(parent);
        editor->setFrame(true);
        editor->setMinimum(1);
        editor->setMaximum(100);
        return editor;
    }
    if (field == "Nr domu" ) {
        QSpinBox* editor = new QSpinBox(parent);
        editor->setFrame(true);
        editor->setMinimum(1);
        editor->setMaximum(100);
        return editor;
    }
    if(field == "ID psa" || field == "ID klienta") {
        QSpinBox* editor = new QSpinBox(parent);
        editor->setFrame(true);
        editor->setMinimum(1);
        editor->setMaximum(100);
        //editor->setSingleStep(100);
        return editor;
    }
    if (field == "Numer Telefonu ") {
        QLineEdit* editor = new QLineEdit(parent);
        QRegExp phoneFormat("([1-9]\\d\\d)-(\\d{3})-(\\d{3})");
        QRegExpValidator* phoneValid(new QRegExpValidator(phoneFormat));
        editor->setValidator(phoneValid);
        return editor;
    }
    if(field == "Kategoria") {
        QComboBox* editor = new QComboBox(parent);
        editor->setFrame(true);
        QStringList kategorie;
        kategorie << "Nieokreślony" << "Łagodny" << "Agresywny" << "Do domu" << "Na podwórko";
        editor->addItems(kategorie);
        return editor;
    }
    return QItemDelegate::createEditor(parent, option, index);
}

void DelegatDanych::setEditorData(QWidget *editor,const QModelIndex &index) const {
    QString field = index.model()->headerData(index.column(), Qt::Horizontal).toString();
    if ( field == "Wiek" || field == "ID klienta" || field == "Nr domu" ) {
        int value = index.model()->data(index).toInt();
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
        return;
    }

    if ( field == "ID" ) {
        int value = index.model()->data(index).toInt();
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
        return;
    }

    if ( field == "Employee:" ) {
        if(index.model()->data(index).toString() == "[OPEN JOB]") {
            QMessageBox::warning(0,"Warning","<center>This is Open Job.<br><b>Can't edit.</b> Empty Position", QMessageBox::Ok);
            editor->setDisabled(true);
            return;
        }
    }
    QString value = index.model()->data(index).toString();
    QLineEdit* lineEditNumber = static_cast<QLineEdit*>(editor);
    lineEditNumber->setText(value);
}

void DelegatDanych::setModelData(QWidget* editor, QAbstractItemModel* model, const QModelIndex &index) const {
    QString field = index.model()->headerData(index.column(), Qt::Horizontal).toString();
    if ( field == "Wiek" || field == "Nr domu" ) {
        QSpinBox* spinBox = static_cast<QSpinBox*>(editor);
        spinBox->interpretText();
        int value = spinBox->value();
        model->setData(index, value);
        return;
    }
    if ( field == "Wiek" || field == "ID klienta" || field == "Nr domu" ) {
        int value = index.model()->data(index).toInt();
        QSpinBox *spinBox = static_cast<QSpinBox*>(editor);
        spinBox->setValue(value);
        return;
    }
    QItemDelegate::setModelData(editor,model,index);
}

void DelegatDanych::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &) const {
    editor->setGeometry(option.rect);
}

void DelegatDanych::paint(QPainter* painter,const QStyleOptionViewItem& option,const QModelIndex& index) const {
    QString field = index.model()->headerData(index.column(), Qt::Horizontal).toString();

//    if (field == "Position:") {
//        QString str ="->" + index.data(Qt::DisplayRole).toString()  ;
//        painter->drawText(option.rect, str, QTextOption());
//        if (option.state & QStyle::State_Selected){
//            QItemDelegate::paint(painter,option, index );
//        }
//        return;
//    }
//    if (field == "Employee:") {
//        QString str = index.data(Qt::DisplayRole).toString();
//        painter->save();
//        if(str != "[OPEN JOB]"){
//            QImage image(":/resources/icon_08.png");
//            painter->drawImage(option.rect, image);
//            painter->setPen(Qt::blue);
//        }
//        painter->drawText(option.rect, Qt::AlignCenter, "     -*-" + str + "-*-");
//        painter->restore();
//        if (option.state & QStyle::State_Selected){
//            QItemDelegate::paint(painter,option, index );
//        }
//        return;
//    }
      return QItemDelegate::paint(painter,option, index );
}

