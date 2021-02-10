#-------------------------------------------------
#
# Project created by QtCreator 2017-09-28T12:03:12
#
#-------------------------------------------------
#cmake -G "Visual Studio 15 2017 Win64" ..
# Desktop_Qt_5_12_9_MSVC2017_64bit-Release

#请选择release模式！
#需要调用gld.pyd，由./gld/gld.pro生成
QT += core gui
QT += widgets

TARGET = ex2
TEMPLATE = app
#CONFIG += staticlib
DESTDIR = ../bin #定义项目编译之后生成的结果文件的存放路径

SOURCES += \
    main.cpp \

HEADERS += \

win32:INCLUDEPATH += $$quote(F:\MyProgram\QtProject\libs\python3_9_1\include)
CONFIG(debug, debug|release) {
#debug
win32:LIBS += $$quote(F:\MyProgram\QtProject\libs\python3_9_1\libs\python39_d.lib)
} else {
#release
win32:LIBS += $$quote(F:\MyProgram\QtProject\libs\python3_9_1\libs\python39.lib)
}





