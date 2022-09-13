#define PY_SSIZE_T_CLEAN
#include <Python.h>


PyDoc_STRVAR(find_min_doc,
"find_min(nums: List[int]) -> int\n\n\
 Suppose an array of length n sorted\n\
in ascending order is rotated between\n\
1 and n times. Given the sorted\n\
rotated array nums of unique elements,\n\
return the minimum element of this\n\
array.");


static PyObject*
_find_min(PyObject *self, PyObject *args)
{
    /* Suppose an array of length n sorted
     *in ascending order is rotated between
     *1 and n times. Given the sorted
     *rotated array nums of unique elements,
     *return the minimum element of this
     *array. */

    int i = 0, numsSize = 0;
    int currentNum = 0, previousNum = 0;
    PyObject *nums = NULL;

    if (!PyArg_ParseTuple(args, "O", &nums)) {
        Py_XDECREF(nums);
        return NULL;
    }

    numsSize = PyObject_Length(nums);
    for (i = numsSize - 1; i > 0; i--) {
        currentNum = PyLong_AsLong(PyList_GetItem(nums, i));
        previousNum = PyLong_AsLong(PyList_GetItem(nums, i - 1));
        if (currentNum - 1 < previousNum) {
            Py_XDECREF(nums);
            return Py_BuildValue("i", currentNum);
        }
    }
    Py_XDECREF(nums);
    return Py_BuildValue("i", PyLong_AsLong(PyList_GetItem(nums, 0)));
}
