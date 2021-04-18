#include "workarea.h"
#include "ui_workarea.h"
#include "db/db.h"

Workarea::Workarea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Workarea)
{
    ui->setupUi(this);
    initUI();
}

Workarea::~Workarea()
{
    delete ui;
}

void Workarea::initUI()
{
    split = new QSplitter;
    split->addWidget(ui->treeWidget);
    split->addWidget(ui->tabWidget);
    ui->horizontalLayout->addWidget(split);
    setLayout(ui->horizontalLayout);
    // default Handle width 2
    split->setHandleWidth(2);
    // default the width 1:3
    split->setStretchFactor(1,3);

    initTreeWidget();
}

void Workarea::initTreeWidget()
{
    auto dms = db::GetDataManages();

    QList<QTreeWidgetItem*> items;
    for(int i = 0; i < dms.size(); i++)
    {
        QTreeWidgetItem* root = new QTreeWidgetItem(ui->treeWidget, QStringList(dms.at(i)->ConnName()));

        QIcon icon;
        switch(dms.at(i)->ConnType())
        {
        case db::ConnType::CT_MYSQL:
            icon.addPixmap(QPixmap(":/pics/mysql_dark.png"), QIcon::Normal);
            icon.addPixmap(QPixmap(":/pics/mysql_light.png"), QIcon::Active);
            break;
        case db::ConnType::CT_SQLITE:
            icon.addPixmap(QPixmap(":/pics/sqlite_dark.png"), QIcon::Normal);
            icon.addPixmap(QPixmap(":/pics/sqlite_light.png"), QIcon::Active);
            break;
        default:break;
        }
        root->setIcon(0, icon);

//        items.append(root);
    }
    ui->treeWidget->addTopLevelItems(items);
}
