#include "newhitocontroller.h"

NewHitoController::NewHitoController()
{

}

NewHitoController::~NewHitoController() {
    Hitokoto::saveToFile();
}

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
