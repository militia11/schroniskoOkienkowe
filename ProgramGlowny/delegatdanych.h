#ifndef DELEGATDANYCH_H
#define DELEGATDANYCH_H

#include <QItemDelegate>

class DelegatDanych : public QItemDelegate
{
    Q_OBJECT

public:
    explicit DelegatDanych(QObject *parent = 0);
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;

    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;

    void updateEditorGeometry(QWidget *editor,
        const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void paint(QPainter* painter,
               const QStyleOptionViewItem& option,
               const QModelIndex& index) const;
};

#endif // DELEGATDANYCH_H
