#ifndef ZEALSEARCHMODEL_H
#define ZEALSEARCHMODEL_H

#include <QHash>
#include <QSet>
#include <QAbstractItemModel>

class ZealSearchModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit ZealSearchModel(QObject *parent = 0);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant data(const QModelIndex &index, int role) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    void setQuery(const QString& q);
    
signals:
    
public slots:

private:
    QString query;
    QHash<QString, int> *counts;
    const QHash<QString, int> getCounts() const;
    QSet<QString> *strings;
    const QString* getString(const QString& str) const {
        if(strings->find(str) == strings->end())
            (*strings).insert(str);
        return &*strings->find(str);
    }
};

#endif // ZEALSEARCHMODEL_H
