#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QToolBar>
#include <QVBoxLayout>
#include <QMenu>

#include "workarea/workarea.h"
#include "db/db.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void toolbarTriggerd(QAction* a);

private:
    void createToolbar();
    void createMenu();
    void createWorkarea();

private:
    Ui::MainWindow *ui;
    QMenu* m_connectMenu;
    Workarea* m_workArea;
};
#endif // MAINWINDOW_H
