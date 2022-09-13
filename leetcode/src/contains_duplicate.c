#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include "../include/uthash.h"


PyDoc_STRVAR(contains_duplicate_doc,
"contains_duplicate(nums: List[int]) -> bool\n\n\
Given an integer array nums, returns true if\n\
any value appears at least twice in the array,\n\
and return false if every element is distinct.");


typedef struct {
    int key, index;
    UT_hash_handle hh;
} hashEntry;


static PyObject*
_contains_duplicate(PyObject *self, PyObject *args)
{
    /* Given an integer array nums, returns true if
     * any value appears at least twice in the array,
     * and return false if every element is distinct. */

    int i = 0, number = 0, returnValue = 0, numsSize = 0;
    PyObject *nums = NULL;
    hashEntry *memo = NULL, *elem = NULL, *tmp = NULL;

    if (!PyArg_ParseTuple(args, "O", &nums))
        goto fail;

    numsSize = PyObject_Length(nums);
    for (i = 0; i < numsSize; i++) {
        number = PyLong_AsLong(PyList_GetItem(nums, i));
        HASH_FIND_INT(memo, &number, elem);
        if (elem) {
            returnValue = 1;
            break;
        }
        else {
            elem = malloc(sizeof(hashEntry));
            if (elem == NULL)
                goto fail;

            elem->key = number;
            elem->index = i;
            HASH_ADD_INT(memo, key, elem);
        }
    }
    HASH_ITER(hh, memo, elem, tmp) {
        HASH_DEL(memo, elem);
        free(elem);
    }
    HASH_CLEAR(hh, memo);
    Py_XDECREF(nums);
    if (returnValue) {
        Py_RETURN_TRUE;
    }
    else {
        Py_RETURN_FALSE;
    }

fail:
    HASH_ITER(hh, memo, elem, tmp) {
        HASH_DEL(memo, elem);
        free(elem);
    }
    HASH_CLEAR(hh, memo);
    Py_XDECREF(nums);
    return NULL;
}
