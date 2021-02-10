
#include <QtGui>
#include <QMainWindow>
#include <QTextEdit>
#include <QApplication>

//处理python和qt冲突
#undef slots
#include<Python.h>
#define slots Q_SLOTS

#include <string>
#include <iostream>

#include "qdebugstream.h"
using namespace std;

//需要调用gld.pyd
int main(int argc, char **argv)
{
    QApplication application(argc, argv);
    application.connect(&application, SIGNAL(lastWindowClosed()),&application, SLOT(quit()));
    QMainWindow* mainWindow = new QMainWindow();
    QTextEdit* myTextEdit = new QTextEdit(mainWindow);
    //myTextEdit->setTextFormat(Qt::LogText);
    mainWindow->setCentralWidget(myTextEdit);
    mainWindow->show();

//1. 重定向std::cout到QTextEdit
    QDebugStream qout(std::cout, myTextEdit);
    std::cout << "Send this to the Text Edit!" << std::endl;
    std::cout << "t1" << std::endl;
    std::cout << "t2" << std::endl;


//2. 重定向python print到std::cout
    // Start up Python
    Py_Initialize();

    // Redirect Python output to msg window
    //PyObject* gld_module = Py_InitModule("gld", ioMethods); //python 2.x
    //PyObject* gld = PyModule_Create(&gldmodule);

    const char *code =	"class Sout:\n"
            "    def write(self, s):\n"
            "        output(s)\n"
            "    def flush(self):\n"
            "        self.buff=''\n"
            "\n"
            "import sys\n"
            "from gld import *\n"
            "from code import *\n"
            "sys.stdout = Sout()\n"
            "sys.stderr = Sout()\n"
            "sys.stdin  = None\n"
            "print(1)\n"
            "print(1+1)\n"
            "print(1+2)\n";
//    const char *code = "print(1+2)\n";
    //int r1 = PyRun_SimpleString(code);
    PyRun_SimpleString(code);

    // 关闭Python
    Py_Finalize();

    return application.exec();
}
