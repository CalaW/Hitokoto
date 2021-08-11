/**
 * @file hitotablecontroller.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief Controller to control new hitokoto window
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#ifndef HITOTABLECONTROLLER_H
#define HITOTABLECONTROLLER_H

#include <map>
#include <QAbstractTableModel>
#include "MyTime.h"
#include "Hitokoto.h"

/**
 * @class HitoTableController
 * @brief Controller to control new hitokoto window
 * 
 */
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
    qint64 m_lStartTime;
    qint64 m_lEndTime;
    bool m_bIsByRange;
    multimap<time_t, Hitokoto*>::const_iterator m_Begin;
    multimap<time_t, Hitokoto*>::const_iterator m_End;
};

#endif // HITOTABLECONTROLLER_H
