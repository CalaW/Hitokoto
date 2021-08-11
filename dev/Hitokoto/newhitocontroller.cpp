/**
 * @file newhitocontroller.cpp
 * @author CalaW (maker_cc@foxmail.com)
 * @brief controller of new hitokoto window
 * @version 0.1
 * @date 2021-08-07
 * 
 * 
 */
#include "newhitocontroller.h"

NewHitoController::NewHitoController()
{

}

/**
 * @brief Destroy the New Hito Controller:: New Hito Controller object
 * 
 * auto save hitokoto map
 * 
 */
NewHitoController::~NewHitoController() {
    Hitokoto::saveToFile();
}

/**
 * @brief add a hitokoto message
 * 
 * @param time 
 * @param content 
 * @param index 
 */
void NewHitoController::addHitokoto(const qint64 time, const QString &content, const int index) {
    Hitokoto_type type;
    switch (index) {
    case 0: type = Hitokoto_type::word;
        break;
    case 1: type = Hitokoto_type::action;
        break;
    case 2: type = Hitokoto_type::thought;
        break;
    }
    new Hitokoto(Time(time), content.toStdString(), type);
}
