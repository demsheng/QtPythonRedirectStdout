#-------------------------------------------------
#
# Project created by QtCreator 2017-09-28T12:03:12
#
#-------------------------------------------------
#cmake -G "Visual Studio 15 2017 Win64" ..
# Desktop_Qt_5_12_9_MSVC2017_64bit-Release

#请选择release模式！
QT -= core gui
QT -= widgets

TARGET = gld
TEMPLATE = lib
#CONFIG += staticlib
DESTDIR = ../bin #定义项目编译之后生成的结果文件的存放路径

SOURCES += \
    gldmodule.cpp


HEADERS += \

#message($$TARGET)          # 生成目标的名字
#message($$DESTDIR)         # 目标输出文件路径
#message($$PWD)             # 当前文件(.pro或.pri)所在的路径
#message($$OUT_PWD)         # Makefile生成的路径

win32:INCLUDEPATH += $$quote(F:\MyProgram\QtProject\libs\python3_9_1\include)

CONFIG(debug, debug|release) {
win32:LIBS += $$quote(F:\MyProgram\QtProject\libs\python3_9_1\libs\python39_d.lib)
} else {
win32:LIBS += $$quote(F:\MyProgram\QtProject\libs\python3_9_1\libs\python39.lib)
}

#message("now")
#message($$quote($$FILE1))
#message($$quote($$FILE2))


win32 {
    #复制gld.dll到gld.pyd
    #让test.py可以调用gld.pyd
    FILE1=$$DESTDIR/gld.dll
    FILE2=$$DESTDIR/gld.pyd
    FILE1 ~= s,/,\\,g
    FILE2 ~= s,/,\\,g
    QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE1) $$quote($$FILE2) $$escape_expand(\\n\\t)

    #复制test.py到$$OUT_PWD/release
    #message($$PWD)             # 当前文件(.pro或.pri)所在的路径
    FILE3=$$PWD/test.py
    FILE4=$$DESTDIR/test.py
    FILE3 ~= s,/,\\,g
    FILE4 ~= s,/,\\,g
    QMAKE_POST_LINK += $$QMAKE_COPY $$quote($$FILE3) $$quote($$FILE4) $$escape_expand(\\n\\t)
}
export(QMAKE_POST_LINK)
