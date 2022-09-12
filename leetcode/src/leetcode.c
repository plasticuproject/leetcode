#define PY_SSIZE_T_CLEAN
#include <Python.h>

#include "max_area.c"
#include "contains_duplicate.c"
#include "count_bits.c"
#include "h_index.c"
#include "letter_combinations.c"
#include "max_product.c"
#include "max_subarray.c"
#include "min_cost_connect_points.c"


static struct PyMethodDef methods[] = {
    {
        "max_area",
        (PyCFunction)_max_area,
        METH_VARARGS,
        max_area_doc
    },
    {
        "contains_duplicate",
        (PyCFunction)_contains_duplicate,
        METH_VARARGS,
        contains_duplicate_doc
    },
    {
        "count_bits",
        (PyCFunction)_count_bits,
        METH_VARARGS,
        count_bits_doc
    },
    {
        "h_index",
        (PyCFunction)_h_index,
        METH_VARARGS,
        h_index_doc
    },
    {
        "letter_combinations",
        (PyCFunction)_letter_combinations,
        METH_VARARGS,
        letter_combinations_doc
    },
    {
        "max_product",
        (PyCFunction)_max_product,
        METH_VARARGS,
        max_product_doc
    },
    {
        "max_subarray",
        (PyCFunction)_max_subarray,
        METH_VARARGS,
        max_subarray_doc
    },
    {
        "min_cost_connect_points",
        (PyCFunction)_min_cost_connect_points,
        METH_VARARGS,
        min_cost_connect_points_doc
    },
    {NULL, NULL, 0, NULL}
};


static struct PyModuleDef module = {
    PyModuleDef_HEAD_INIT,
    "leetcode",
    "Python interface for my leetcode C solutions",
    -1,
    methods
};


PyMODINIT_FUNC PyInit_leetcode(void) {
    return PyModule_Create(&module);
};
