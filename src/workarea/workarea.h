#ifndef WORKAREA_H
#define WORKAREA_H

#include <QWidget>
#include <QTreeWidgetItem>
#include <QSplitter>

#include "db/db.h"

namespace Ui {
class Workarea;
}

class Workarea : public QWidget
{
    Q_OBJECT

public:
    explicit Workarea(QWidget *parent = nullptr);
    ~Workarea();

private:
    void initUI();
    void initTreeWidget();

private slots:
    void itemDoubleClicked(QTreeWidgetItem *item, int column);

private:
    Ui::Workarea *ui;
    QSplitter* split;
    QList<QTreeWidgetItem*> items;
    QVector<std::shared_ptr<DataManage>> dms;
};

#endif // WORKAREA_H
