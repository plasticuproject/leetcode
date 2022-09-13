#define PY_SSIZE_T_CLEAN
#include <Python.h>


PyDoc_STRVAR(hamming_weight_doc,
"hamming_weight(num: int) -> int\n\n\
Takes an unsigned integer and\n\
returns the number of '1' bits it has.");


static PyObject*
_hamming_weight(PyObject *self, PyObject *args)
{
    /* Takes an unsigned integer and
    returns the number of '1' bits it has. */

    int count = 0;
    unsigned long num = 0;  // __uint32_t

    if (!PyArg_ParseTuple(args, "k", &num)) {
        return NULL;
    }

    while (num) {
        num &= (num - 1);
        count++;
        // or:
        // count += num % 2
        // num = num >> 1
    }
    return Py_BuildValue("i", count);
}
