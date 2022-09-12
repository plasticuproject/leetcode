#define PY_SSIZE_T_CLEAN
#include <Python.h>


PyDoc_STRVAR(letter_combinations_doc,
"letter_combinations(digits: str) -> List[str]\n\n\
Given a string containing digits from 2-9\n\
inclusive, returns all possible letter combinations\n\
that the number could represent.");


char*
mapper(char digit)
{
    /* Given a string representation
     * of a number, returns a string of
     * letters mapped to that number. */

    int digitInt = digit;
    int digitModifier = (digitInt + 47 + (((digitInt + 50) % 50) * 2));
    int offset = 0, count = 0, i = 0, j = 0;

    if (digitInt == 55) {
        offset = 0;
        count = 4;
    }
    else if (digitInt == 56) {
        offset = 1;
        count = 4;
    }
    else if (digitInt == 57) {
        offset = 1;
        count = 5;
    }
    else {
        offset = 0;
        count = 3;
    }

    char *result = malloc((count - offset) + 1);
    if (result == NULL) {
        return NULL;
    }
    for (i = offset, j = 0; i < count; i++, j++) {
        result[j] = digitModifier + i;
    }
    result[count - offset] = '\0';
    return result;
}


static PyObject*
_letter_combinations(PyObject *self, PyObject *args)
{
    /* Given a string containing digits from 2-9
     * inclusive, returns all possible letter combinations
     * that the number could represent. */

    PyObject *list = NULL;
    char *digits = {'\0'}, *tempMap = {'\0'};
    int returnSize = 0, digitSize = 0, resultSize = 1, mapLength = 0;
    int i = 0, j = 0, idx = 0, lastDigitIndex = 0;

    if (!PyArg_ParseTuple(args, "s", &digits)) {
        Py_XDECREF(list);
        return NULL;
    }

    for (i = 0; digits[i] != '\0'; i++) {
        digitSize++;
    }
    if (digitSize == 0) {
        return (PyObject*)PyList_New(0);
    }

    for (i = 0; i < digitSize; i++) {
        tempMap = mapper(digits[i]);
        for (j = 0; tempMap[j] != '\0'; j++) {
            mapLength++;
        }
        resultSize *= mapLength;
        free(tempMap);
    }

    char **ret = malloc(resultSize * sizeof(char*));
    if (ret == NULL) {
        Py_XDECREF(list);
        return NULL;
    }
    int *pickUp = calloc(digitSize, sizeof(int));
    if (pickUp == NULL) {
        Py_XDECREF(list);
        free(ret);
        return NULL;
    }

    tempMap = mapper(digits[digitSize - 1]);
    for (i = 0; tempMap[i] != '\0'; i++) {
        lastDigitIndex++;
    }
    free(tempMap);

    while(pickUp[digitSize - 1] < lastDigitIndex)
    {
        ret[returnSize] = malloc(digitSize + 1 * sizeof(char));
        if (ret[returnSize] == NULL) {
            Py_XDECREF(list);
            free(ret);
            free(pickUp);
            return NULL;
        }
        idx = 0;
        for (i = 0; i < digitSize; i++) {
            tempMap = mapper(digits[i]);
            ret[returnSize][idx] = tempMap[pickUp[i]];
            free(tempMap);
            idx++;
        }
        ret[returnSize][idx] = '\0';
        returnSize++;
        pickUp[0] = pickUp[0] + 1;
        for (i = 0; i + 1 < digitSize; i++) {
            mapLength = 0;
            tempMap = mapper(digits[i]);
            for (j = 0; tempMap[j] != '\0'; j++) {
                mapLength++;
            }
            free(tempMap);
            if (pickUp[i] == mapLength) {
                pickUp[i] = 0;
                pickUp[i + 1] = pickUp[i + 1]  + 1;
            }
            else {
                break;
            }
        }
    }
    free(pickUp);
    list = PyList_New(returnSize);
    for (i = 0; i < returnSize; i++) {
        PyList_SetItem(list, i, Py_BuildValue("U", ret[i]));
    }
    return list;
}
