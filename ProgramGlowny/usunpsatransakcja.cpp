#include "usunpsatransakcja.h"

UsunPsaTransakcja::UsunPsaTransakcja(QTableView* widok)
    : widok(widok)
{
}

void UsunPsaTransakcja::wykonaj()
{
    QModelIndex index = widok->selectionModel()->currentIndex();
    QAbstractItemModel* model = widok->model();
    model->removeRow( index.row(), index.parent() );
}

