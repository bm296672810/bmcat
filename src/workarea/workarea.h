#ifndef WORKAREA_H
#define WORKAREA_H

#include <QWidget>
#include <QSplitter>

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

private:
    Ui::Workarea *ui;
    QSplitter* split;
};

#endif // WORKAREA_H
