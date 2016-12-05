/**
* @Author: Tian Qiao <qiaotian>
* @Date:   2016-11-27T09:58:36+08:00
* @Email:  qiaotian@me.com
* @Last modified by:   qiaotian
* @Last modified time: 2016-11-27T09:58:36+08:00
*/

#include "predictor.h"
#include <Python.h>

int Predictor::prepare() {
    return 0;
}

int Predictor::process() {
    //1st step: initialize Python
    //load Python modules by calling C API of Python
    Py_Initialize(); //cout << "iniialized" << endl;
    //check initialization
    if (!Py_IsInitialized())
    {
        return -1;
    }

    //2nd step: load sys module
    PyRun_SimpleString("import sys");

    //3rd step: load parameters, for example, ./sample.py arg1 arg2
    //PyRun_SimpleString("sys.argv['arg1','arg2']");

    //4th step: call python script to run the trainning process
    if (!PyRun_SimpleString("execfile('./sample.py')")) return -1;

    // close python interpretor
    Py_Finalize();
    return 0;
}
