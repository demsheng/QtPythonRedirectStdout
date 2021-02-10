#include "qdebugstream.h"
#include <QtGui>
#include <QMainWindow>
#include <QTextEdit>
#include <QApplication>

int main(int argc, char **argv)
{
    QApplication application(argc, argv);
    application.connect(&application, SIGNAL(lastWindowClosed()),&application, SLOT(quit()));

    QMainWindow* mainWindow = new QMainWindow();

    QTextEdit* myTextEdit = new QTextEdit(mainWindow);
    //myTextEdit->setTextFormat(Qt::LogText);
    QDebugStream qout(std::cout, myTextEdit);

    mainWindow->setCentralWidget(myTextEdit);

    mainWindow->show();

    std::cout << "Send this to the Text Edit!" << std::endl;
    std::cout << "1" << std::endl;
    std::cout << "2" << std::endl;

    return application.exec();
}
