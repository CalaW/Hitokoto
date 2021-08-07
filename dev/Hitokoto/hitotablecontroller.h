#ifndef HITOTABLECONTROLLER_H
#define HITOTABLECONTROLLER_H

#include <map>
#include <QAbstractTableModel>
#include "MyTime.h"
#include "Hitokoto.h"

class HitoTableController : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit HitoTableController(QObject *parent = nullptr);
    enum MapRoles {
            KeyRole = Qt::UserRole + 1,
            typeRole,
            ContentRole
        };

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    void setStartTime(const qint64 start_time);
    void setEndTime(const qint64 end_time);
    void setViewByRange(bool by_range);
    void refresh();
private:
    qint64 m_start_time;
    qint64 m_end_time;
    bool m_is_by_range;
    multimap<time_t, Hitokoto*>::const_iterator m_begin;
    multimap<time_t, Hitokoto*>::const_iterator m_end;
};

#endif // HITOTABLECONTROLLER_H
