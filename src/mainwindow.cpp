#include "mainwindow.h"
#include "./ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    db::InitDB();

    ui->setupUi(this);
    createToolbar();
    createMenu();
    createWorkarea();
}

MainWindow::~MainWindow()
{
    for (auto i : ui->toolBar->actions()) {
        delete i;
    }
    delete ui;

    delete m_connectMenu;

    db::FreeDB();
}

void MainWindow::createToolbar()
{
    ui->toolBar->setFixedHeight(40);
    QList<QAction*> toolBarList;
    toolBarList.append(new QAction(QStringLiteral("connect")));
    toolBarList.append(new QAction(QStringLiteral("create_select")));
    toolBarList.append(new QAction(QStringLiteral("table")));
    toolBarList.append(new QAction(QStringLiteral("view")));
    toolBarList.append(new QAction(QStringLiteral("function")));
    ui->toolBar->addActions(toolBarList);

    connect(ui->toolBar, &QToolBar::actionTriggered, this, &MainWindow::toolbarTriggerd);
}

void MainWindow::createMenu()
{
    m_connectMenu = new QMenu;
    m_connectMenu->addAction(QStringLiteral("MySQL..."));
    m_connectMenu->addAction(QStringLiteral("SQLite..."));
    m_connectMenu->addSeparator();
}

void MainWindow::toolbarTriggerd(QAction* a)
{
    if(a->text() == "connect")
    {
        qDebug() << "connect";
        auto pos = ui->toolBar->mapToGlobal(ui->toolBar->pos());
        pos.rx() += ui->toolBar->height() / 2;
        pos.ry() += ui->toolBar->height() / 2;
        m_connectMenu->popup(pos);
    }
}

void MainWindow::createWorkarea()
{
    m_workArea = new Workarea(ui->centralwidget);

    ui->verticalLayout->addWidget(m_workArea);
    ui->centralwidget->setLayout(ui->verticalLayout);
}
