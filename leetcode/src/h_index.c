#define PY_SSIZE_T_CLEAN
#include <Python.h>


PyDoc_STRVAR(h_index_doc,
"h_index(citations: List[int]) -> int\n\n\
Given an array of integers citations\n\
where citations[i] is the number of\n\
citations a researcher received for their\n\
ith paper, return compute the researcher's\n\
h-index.");


void swap(int* first, int* second) {
    int temp = *first;
    *first = *second;
    *second = temp;
}


int
partition(int arr[], int lower, int upper)
{
    int i = (lower - 1), j = 0, pivot = arr[upper];

    for (j = lower; j < upper; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[upper]);
    return (i + 1);
}


void
quickSort(int arr[], int lower, int upper)
{
    if (upper > lower) {
        int partitionIndex = partition(arr, lower, upper);

        quickSort(arr, lower, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, upper);
    }
}


static PyObject*
_h_index(PyObject *self, PyObject *args)
{
    /* Given an array of integers citations
     * where citations[i] is the number of
     * citations a researcher received for their
     * ith paper, return compute the researcher's
     * h-index. */

    PyObject *citations = NULL;
    int i = 0, citationsSize = 0;

    if (!PyArg_ParseTuple(args, "O", &citations)) {
        Py_XDECREF(citations);
        return NULL;
    }

    citationsSize = PyObject_Length(citations);
    int citationLongs[citationsSize];
    for (i = 0; i < citationsSize; i++) {
        citationLongs[i] = PyLong_AsLong(PySequence_GetItem(citations, i));
        Py_XDECREF(citations);
    }

    quickSort(citationLongs, 0, (citationsSize - 1));
    for (i = 0; i < citationsSize; i++) {
        if (citationLongs[i] >= (citationsSize - i)) {
            return Py_BuildValue("i", citationsSize - i);
        }
    }
    Py_XDECREF(citations);
    return Py_BuildValue("i", 0);
}
