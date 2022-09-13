#define PY_SSIZE_T_CLEAN
#include <Python.h>


PyDoc_STRVAR(max_subarray_doc,
"max_subarray(nums: List[int]) -> int\n\n\
 Given an integer array nums, find the\n\
contiguous subarray (containing at least\n\
one number) which has the largest sum and\n\
return its sum.");


PyObject*
_max_subarray(PyObject *self, PyObject *args)
{
    /* Given an integer array nums, find the
    * contiguous subarray (containing at least
    * one number) which has the largest sum and
    * return its sum. */

    PyObject *nums = NULL;
    int i = 0, newSum = 0, num = 0;
    int numsSize = 0, previous = 0;

    if (!PyArg_ParseTuple(args, "O", &nums)) {
        Py_XDECREF(nums);
        return NULL;
    }

    numsSize = PyObject_Length(nums);
    previous = PyLong_AsLong(PyList_GetItem(nums, 0));
    for(i = 0; i < numsSize; i++){
        if(newSum < 0){
            newSum = 0;
        }
        num = PyLong_AsLong(PyList_GetItem(nums, i));
        newSum += num;
        if(newSum > previous){
            previous = newSum;
        }
    }
    Py_XDECREF(nums);
    return Py_BuildValue("i", previous);
}
