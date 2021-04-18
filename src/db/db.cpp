#include "db.h"
namespace db {
std::shared_ptr<QSqlDatabase> mdb = nullptr;

void InitDB()
{
    mdb = std::make_shared<QSqlDatabase>();

    *mdb = QSqlDatabase::addDatabase("QSQLITE");
    mdb->setDatabaseName("MyDataBase.db");
    if (!mdb->open())
    {
        qDebug() << "Error: Failed to connect database." << mdb->lastError();
    }
    else
    {
        qDebug() << "Succeed to connect database." ;
    }
}

void FreeDB()
{
    mdb->close();
}

QVector<connection> getConnection()
{
    QVector<connection> conns;
    if(!mdb)
        return conns;

    QString sql("select * from connection");
    QSqlQuery que(*mdb);
    que.exec(sql);

    while(que.next())
    {
        connection c;
        c.id    = que.value(0).toInt();
        c.name  = que.value(1).toString();
        c.type  = (ConnType)que.value(2).toInt();
        c.addr  = que.value(3).toString();

        if(c.type == ConnType::CT_MYSQL)
        {
            c.port = que.value(4).toString();
            c.user = que.value(5).toString();
            c.pwd  = que.value(6).toString();
            c.dbname = que.value(7).toString();
        }

        conns.append(c);
    }

    return conns;
}

QVector<std::shared_ptr<DataManage>> GetDataManages()
{
    auto conns = getConnection();
    QVector<std::shared_ptr<DataManage>> dms;
    for(auto i : conns)
    {
        std::shared_ptr<DataManage> dm = std::make_shared<DataManage>(i);
        dms.append(dm);
    }

    return dms;
}
}

void DataManage::updateValue()
{

}
