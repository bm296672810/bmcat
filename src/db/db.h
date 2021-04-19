#ifndef DB_H
#define DB_H

#include <memory>

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QVector>

template <typename... Args>
void unused(Args...){}

class DataManage;

namespace db {

enum ConnType {
    CT_MYSQL,
    CT_SQLITE,
    CT_UNKNOWN
};

struct connection
{
    int      id;
    QString  name;
    ConnType type;
    QString  addr;  // mysql addr 是数据库的ip，sqlite addr是文件路径
    QString  port;
    QString  user;
    QString  pwd;
    QString  dbname;
};

void InitDB();
void FreeDB();

QVector<connection> getConnection();
QVector<std::shared_ptr<DataManage>> GetDataManages();
}

class DataManage
{
public:
    DataManage(db::connection conn) : _conn(conn) {}
    ~DataManage() {}
    QString ConnName() const { return _conn.name; }
    db::ConnType ConnType() const { return _conn.type; }
    QStringList GetTables() const;
    void InitDatabase();
    void SetConnName(const QString& name) { _conn.name = name; updateValue(); }

private:
    void updateValue();

private:
    db::connection _conn;
    std::shared_ptr<QSqlDatabase> _db;

};

#endif // WORKAREA_H
