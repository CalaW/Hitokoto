QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    MyTime.cpp \
    admincontroller.cpp \
    logincontroller.cpp \
    logindialog.cpp \
    main.cpp \
    maincontroller.cpp \
    mainwindow.cpp\
    AdminUser.cpp \
    Cipher.cpp \
    EncryptStrategy.cpp \
    Hitokoto.cpp \
    Md5.cpp \
    TrivialUser.cpp \
    User.cpp

HEADERS += \
    MyTime.h \
    admincontroller.h \
    logincontroller.h \
    logindialog.h \
    maincontroller.h \
    mainwindow.h \
    AdminUser.h \
    Cipher.h \
    EncryptStrategy.h \
    Hitokoto.h \
    Md5.h \
    TrivialUser.h \
    User.h

FORMS += \
    logindialog.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
