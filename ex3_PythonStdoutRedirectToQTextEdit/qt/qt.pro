#-------------------------------------------------
#
# Project created by QtCreator 2020-01-14T09:48:23
#
#-------------------------------------------------

#请选择release模式！
#需要调用gld.pyd，由./gld/gld.pro生成

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ex3
TEMPLATE = app
DESTDIR = ../bin #定义项目编译之后生成的结果文件的存放路径

SOURCES += \
    main.cpp
HEADERS += \
    qdebugstream.h

win32:INCLUDEPATH += $$quote(F:\MyProgram\QtProject\libs\python3_9_1\include)
CONFIG(debug, debug|release) {
win32:LIBS += $$quote(F:\MyProgram\QtProject\libs\python3_9_1\libs\python39_d.lib)
} else {
win32:LIBS += $$quote(F:\MyProgram\QtProject\libs\python3_9_1\libs\python39.lib)
}
