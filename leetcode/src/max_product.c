#define PY_SSIZE_T_CLEAN
#include <Python.h>


PyDoc_STRVAR(max_product_doc,
"max_product(nums: List[int]) -> int\n\n\
Given an integer array nums, find a\n\
contiguous non-empty subarray within the\n\
array that has the largest product, and\n\
return the product.");


PyObject*
_max_product(PyObject *self, PyObject *args)
{
    /* Given an integer array nums, find a
     * contiguous non-empty subarray within the
     * array that has the largest product, and
     * return the product. */

    PyObject *nums = NULL;
    int i = 0, j = 0, num = 0;
    int minV = 1, maxV = 1, current = 0, tempV = 0;
    int tempArr[2] = {0, 0};
    int numsSize = 0, product = 0;

    if (!PyArg_ParseTuple(args, "O", &nums)) {
        Py_XDECREF(nums);
        return NULL;
    }

    numsSize = PyObject_Length(nums);
    product = PyLong_AsLong(PyList_GetItem(nums, 0));
    for (i = 0; i < numsSize; i++) {
        num = PyLong_AsLong(PyList_GetItem(nums, i));
        if (num > product) {
            product = num;
        }
    }
    for (i = 0; i < numsSize; i++) {
        num = PyLong_AsLong(PyList_GetItem(nums, i));
        current = maxV * num;
        tempV = num;
        tempArr[0] = num * maxV;
        tempArr[1] = num * minV;
        for (j = 0; j < 2; j++) {
            if (tempArr[j] > tempV) {
                tempV = tempArr[j];
            }
            maxV = tempV;
        }
        tempV = num;
        tempArr[0] = current;
        for (j = 0; j < 2; j++) {
            if (tempArr[j] < tempV) {
                tempV = tempArr[j];
            }
            minV = tempV;
        }
        if (maxV > product) {
            product = maxV;
        }
    }
    Py_DECREF(nums);
    return Py_BuildValue("i", product);
}
