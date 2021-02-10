//处理python和qt冲突
#undef slots
#include<Python.h>
#define slots Q_SLOTS

#include <string>
#include <iostream>
using namespace std;

// Write python output to textedit
static PyObject * output(PyObject *self, PyObject *args)
{
	char *string;
	if (!PyArg_ParseTuple(args, "s", &string))
 		return 0;
    //gld::gMsgView()->write( "%s", string);
    //std::cout << "printf from c:" << string << std::endl;
    std::cout << string ;
 	return Py_BuildValue("");
}

//python 2.x
// Define methods available to Python
static PyMethodDef ioMethods[] = {
    {"output", output, METH_VARARGS, "redriect python stdout to qt textedit"},
   {NULL, NULL, 0, NULL}
};
 
static struct PyModuleDef gldmodule =
{
    PyModuleDef_HEAD_INIT,
    "gld", /* name of module */
    "",          /* module documentation, may be NULL */
    -1,          /* size of per-interpreter state of the module, or -1 if the module keeps state in global variables. */
    ioMethods
};

PyMODINIT_FUNC
PyInit_gld(void)
{
    return PyModule_Create(&gldmodule);
}
