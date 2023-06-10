#ifndef CRIMEMODEL_H
#define CRIMEMODEL_H

#include <QAbstractListModel>
#include "Crime.h"
#include <QVariant>

class CrimeModel: public QAbstractListModel
{
    Q_OBJECT
public:
    explicit CrimeModel(const QList<Crime*>& crimes, QObject* parent = nullptr);
    QModelIndex index(int row, int column = 0, const QModelIndex& parent = QModelIndex()) const override;
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    Crime* getCrime(const QModelIndex index);
    QString getWorstCrime(const QString state);

private:

    ~CrimeModel();

private:
    QList<Crime*> crimes;

};

#endif // CRIMEMODEL_H
