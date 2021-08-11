/**
 * @file newhitocontroller.h
 * @author CalaW (maker_cc@foxmail.com)
 * @brief controller of hitokoto window
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#ifndef NEWHITOCONTROLLER_H
#define NEWHITOCONTROLLER_H

#include "Hitokoto.h"
#include "MyTime.h"
#include <QtGlobal>
#include <QString>

/**
 * @class NewHitoController
 * @brief controller of hitokoto window
 * 
 */
class NewHitoController
{
public:
    NewHitoController();
    ~NewHitoController();
    void addHitokoto(const qint64 time, const QString& content, const int type);
};

#endif // NEWHITOCONTROLLER_H
