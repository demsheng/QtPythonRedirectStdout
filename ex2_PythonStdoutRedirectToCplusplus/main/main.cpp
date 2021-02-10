#include<Python.h>

#include <string>
#include <iostream>
using namespace std;

//需要调用gld.pyd
int main()//int argc, char ** argv)
{
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
    return 0;
}

