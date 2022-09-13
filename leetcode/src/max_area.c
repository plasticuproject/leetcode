#define PY_SSIZE_T_CLEAN
#include <Python.h>


PyDoc_STRVAR(max_area_doc,
"max_area(height: List[int]) -> int\n\n\
 Given an integer array height of\n\
 length n. There are n vertical lines\n\
 drawn such that the two endpoints of the\n\
 ith line are (i, 0) and (i, height[i]).\n\
 Finds two lines that together with the\n\
 x-axis form a container, such that the\n\
 container contains the most water and\n\
 returns the maximum amount of water a\n\
 container can store.");


static PyObject*
_max_area(PyObject *self, PyObject *args)
{
    /* Given an integer array height of
     * length n. There are n vertical lines
     * drawn such that the two endpoints of the
     * ith line are (i, 0) and (i, height[i]).
     * Finds two lines that together with the
     * x-axis form a container, such that the
     * container contains the most water and
     * returns the maximum amount of water a
     * container can store. */

    PyObject *height = NULL;
    int heightSize = 0;
    int minIdx = 0, maxIdx = 0;
    int heightMinIdx = 0, heightMaxIdx = 0;
    int minHeight = 0, area = 0, res = 0;

    if (!PyArg_ParseTuple(args, "O", &height)) {
        Py_XDECREF(height);
        return NULL;
    }

    heightSize = PyObject_Length(height);
    maxIdx = (heightSize - 1);
    while (minIdx < maxIdx) {
        heightMinIdx = PyLong_AsLong(PyList_GetItem(height, minIdx));
        heightMaxIdx = PyLong_AsLong(PyList_GetItem(height, maxIdx));
        minHeight = (heightMinIdx < heightMaxIdx) ? heightMinIdx : heightMaxIdx;
        area = minHeight * (maxIdx - minIdx);
        if (area > res) {
            res = area;
        }
        if (heightMinIdx <= heightMaxIdx) {
            minIdx++;
        }
        else {
            maxIdx--;
        }
    }
    Py_XDECREF(height);
    return Py_BuildValue("i", res);
}
