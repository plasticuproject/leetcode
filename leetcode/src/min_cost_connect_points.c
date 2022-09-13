#define PY_SSIZE_T_CLEAN
#include <Python.h>


#define MAX 20000001


PyDoc_STRVAR(min_cost_connect_points_doc,
"min_cost_connect_points(points: List[List[int]]) -> int\n\n\
Given an array points representing integer coordinates\n\
of some points on a 2D-plane, where points[i] = [xi, yi],\n\
return the minimum cost to make all points connected. All\n\
points are connected if there is exactly one simple path\n\
between any two points.");


typedef struct {
    int key[2];
    int distance;
} map;


PyObject*
_min_cost_connect_points(PyObject *self, PyObject *args)
{
    /* Given an array points representing integer coordinates
     * of some points on a 2D-plane, where points[i] = [xi, yi],
     * return the minimum cost to make all points connected. All
     * points are connected if there is exactly one simple path
     * between any two points. */

    PyObject *points = NULL;
    int result = 0, pointsSize = 0, point_one = 0, point_two = 0;
    int tempMin = 0, tempDistance = 0;
    int absX = 0, absY = 0;
    int i = 0, j = 0;
    int tempKey[2] = {0, 0};
    int idx[2] = {0, 0};

    if (!PyArg_ParseTuple(args, "O", &points)) {
        Py_XDECREF(points);
        return NULL;
    }

    pointsSize = PyObject_Length(points);
    map *dist = NULL, *tempDist = NULL, *elem = NULL;
    dist = malloc(sizeof(map) * pointsSize);
    if (dist == NULL) {
        Py_XDECREF(points);
        return NULL;
    }
    tempDist = dist;
    elem = malloc(sizeof(map));
    if (elem == NULL) {
        Py_XDECREF(points);
        free(dist);
        return NULL;
    }

    for (i = 0; i < pointsSize; i++) {
        point_one = PyLong_AsLong(PyList_GetItem(PyList_GetItem(points, i), 0));
        point_two = PyLong_AsLong(PyList_GetItem(PyList_GetItem(points, i), 1));
        elem->key[0] = point_one;
        elem->key[1] = point_two;
        elem->distance = (i) ? MAX : 0;
        dist[i] = *elem;
    }
    free(elem);

    while (pointsSize) {
        tempMin = MAX;
        for (i = 0; i < pointsSize; i++) {
            elem = &dist[i];
            if (elem->distance < tempMin) {
                tempMin = elem->distance;
                idx[0] = elem->key[0];
                idx[1] = elem->key[1];
            }
        }

        j = 0;
        for (i = 0; i < pointsSize; i++) {
            elem = &dist[i];
            tempKey[0] = elem->key[0];
            tempKey[1] = elem->key[1];
            tempDistance = elem->distance;
            if ((elem->key[0] == idx[0]) && (elem->key[1] == idx[1])) {
                result += elem->distance;
            }
            else {
                absX = idx[0] - elem->key[0];
                if (absX < 0) {
                    absX = -absX;
                }
                absY = idx[1] - elem->key[1];
                if (absY < 0) {
                    absY = -absY;
                }
                tempMin = absX + absY;
                if (tempMin < tempDistance) {
                    tempDistance = tempMin;
                }
                elem = &tempDist[j];
                elem->key[0] = tempKey[0];
                elem->key[1] = tempKey[1];
                elem->distance = tempDistance;
                j++;
            }
        }
        dist = tempDist;
        pointsSize--;
    }
    free(dist);
    Py_XDECREF(points);
    return Py_BuildValue("i", result);
}
