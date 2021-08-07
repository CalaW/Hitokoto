#include "hitotablecontroller.h"
#include <QApplication>

HitoTableController::HitoTableController(QObject *parent) : QAbstractTableModel(parent)
{
    setHeaderData(0, Qt::Horizontal, tr("Time"));
    setHeaderData(1, Qt::Horizontal, tr("Type"));
    setHeaderData(2, Qt::Horizontal, tr("Content"));
    m_is_by_range = false;
    m_begin = Hitokoto::cbegin();
    m_end = Hitokoto::cend();
}

int HitoTableController::rowCount(const QModelIndex& parent) const
{
    if (m_is_by_range) {
        int cnt = 0;
        for (auto it = m_begin; it != m_end; ++it) {
            cnt++;
        }
        return cnt;
    } else {
        return Hitokoto::size();
    }
}

int HitoTableController::columnCount(const QModelIndex & parent) const
{
    return 3;
}

QVariant HitoTableController::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole)
        return QVariant();

    auto it = m_begin;
    for (int i = 0; i < index.row(); i++) {
        it++;
    }

    if (index.column() == 0)
        return QString::fromStdString((*it).second->getTimeString());
    if (index.column() == 1)
        return QString::fromStdString((*it).second->getTypeString());
    if (index.column() == 2)
        return QString::fromStdString((*it).second->getContent());

    return QVariant();
}

void HitoTableController::setStartTime(const qint64 start_time) {
    m_start_time = start_time;
    m_end = Hitokoto::lower_bound(start_time);
    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
}

void HitoTableController::setEndTime(const qint64 end_time) {
    m_end_time = end_time;
    m_begin = Hitokoto::upper_bound(end_time);
    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
}

void HitoTableController::setViewByRange(bool by_range) {
    m_is_by_range = by_range;
    if (!m_is_by_range) {
        m_begin = Hitokoto::cbegin();
    }
    emit dataChanged(index(0,0), index(rowCount(), columnCount()));
}
