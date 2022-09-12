#define PY_SSIZE_T_CLEAN
#include <Python.h>


PyDoc_STRVAR(count_bits_doc,
"count_bits(n: int) -> List[int]\n\n\
Given an integer n, returns an\n\
array ans of length n + 1 such that\n\
for each i (0 <= i <= n), ans[i] is\n\
the number of 1's in the binary\n\
representation of i.");


static PyObject*
_count_bits(PyObject *self, PyObject *args)
{
    /* Given an integer n, returns an
     * array ans of length n + 1 such that
     * for each i (0 <= i <= n), ans[i] is
     * the number of 1's in the binary
     * representation of i. */

    int num = 0, returnSize = 0, offset = 1, i = 0;
    int *ans = 0;
    PyObject *list = NULL;

    if (!PyArg_ParseTuple(args, "i", &num))
        goto fail;

    returnSize = (num + 1);
    list = PyList_New(returnSize);
    ans = calloc(returnSize, sizeof(int));
    if (ans == NULL)
        goto fail;

    PyList_SetItem(list, i, PyLong_FromLong(ans[0]));
    for (i = 1; i < returnSize; i++) {
        if (i == (offset * 2)) {
            offset = i;
        }
        ans[i] = (1 + (ans[i - offset]));
        PyList_SetItem(list, i, PyLong_FromLong(ans[i]));
    }
    return list;

fail:
    Py_XDECREF(list);
    return NULL;
}
