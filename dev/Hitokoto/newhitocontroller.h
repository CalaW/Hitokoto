#ifndef NEWHITOCONTROLLER_H
#define NEWHITOCONTROLLER_H

#include "Hitokoto.h"
#include "MyTime.h"
#include <QtGlobal>
#include <QString>

class NewHitoController
{
public:
    NewHitoController();
    ~NewHitoController();
    void addHitokoto(const qint64 time, const QString& content, const int type);
};

#endif // NEWHITOCONTROLLER_H
