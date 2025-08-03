QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    appsetting.cpp \
    folderedit.cpp \
    main.cpp \
    setting.cpp \
    widget.cpp

HEADERS += \
    appsetting.h \
    buttondelegate.h \
    folderedit.h \
    setting.h \
    widget.h

FORMS += \
    appsetting.ui \
    folderedit.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


CODECFORSRC = UTF-8

RESOURCES += \
    resources.qrc

# Debug模式
contains(CONFIG, debug) {
    DESTDIR = $$PWD/bin/Debug
}

# Release模式
contains(CONFIG, release) {
    DESTDIR = $$PWD/bin/Release
}
