#include "crimeModel.h"
#include "Crime.h"
#include <QAbstractListModel>

CrimeModel::CrimeModel(const QList<Crime*>& crimes, QObject* parent)
    : QAbstractListModel(parent), crimes(crimes)
{

}

QModelIndex CrimeModel::index(int row, int column, const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return createIndex(row, column);
}

int CrimeModel::rowCount(const QModelIndex& parent) const
{
    if (parent.isValid())
        return 0;

    return crimes.size();
}

QVariant CrimeModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole)
    {
        if (index.row() >= 0 && index.row() < crimes.size())
        {
            Crime* crime = crimes.at(index.row());
            return crime->getCase();
        }
    }
    return QVariant();
}

Crime* CrimeModel::getCrime(const QModelIndex index)
{
    return crimes.at(index.row());
}

CrimeModel::~CrimeModel()
{
    for (Crime* crime: crimes)
        delete(crime);
    crimes.clear();
}

QString CrimeModel::getWorstCrime(const QString state)
{
    QString ans;
    int max = 0;
    for (Crime* crime: crimes){
        if(crime->getState() == state){
            if(crime->getKilled() >= max){
                max = crime->getKilled();
                ans = crime->getCase();
            }
        }
    }
    return ans;
}
