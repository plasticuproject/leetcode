#include <stdio.h>
#include <stdlib.h>

// gcc test.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

#define MAX 20000001

typedef struct{
    int key[2];
    int distance;
}hashEntry;


int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
    /* Given an array points representing integer coordinates
     * of some points on a 2D-plane, where points[i] = [xi, yi],
     * return the minimum cost to make all points connected. All
     * points are connected if there is exactly one simple path
     * between any two points. */
    int result = 0;
    hashEntry *dist, *tempDist, *elem;
    dist = malloc(sizeof(hashEntry) * pointsSize);
    //tempDist = malloc(sizeof(hashEntry) * pointsSize);
    tempDist = dist;
    elem = malloc(sizeof(hashEntry));


    int i;
    for(i = 0; i < pointsSize; i++){
        elem->key[0] = points[i][0];
        elem->key[1] = points[i][1];
        elem->distance = (i) ? MAX : 0;
        dist[i] = *elem;
    }
    free(elem);

    int tempMin;
    int idx[2];
    int absX, absY;
    int tempDistance;
    int tempKey[2];
    int j;
    while(pointsSize){
        tempMin = MAX;
        for(i = 0; i < pointsSize; i++){
            elem = &dist[i];
            if(elem->distance < tempMin){
                tempMin = elem->distance;
                idx[0] = elem->key[0];
                idx[1] = elem->key[1];
            }
        }

        j = 0;
        for(i = 0; i < pointsSize; i++){
            elem = &dist[i];
            tempKey[0] = elem->key[0];
            tempKey[1] = elem->key[1];
            tempDistance = elem->distance;
            if((elem->key[0] == idx[0]) && (elem->key[1] == idx[1])){
                result += elem->distance;
            }
            else{
                absX = idx[0] - elem->key[0]; if(absX < 0){absX = -absX;}
                absY = idx[1] - elem->key[1]; if(absY < 0){absY = -absY;}
                tempMin = absX + absY;
                if(tempMin < tempDistance){
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
    return result;
}


// TESTS
int main(void){
    int returnVal = 0;
    static int pcs = 2;
    int ps = 5;
    int *a = malloc(sizeof(int) * pcs);
    int *b = malloc(sizeof(int) * pcs);
    int *c = malloc(sizeof(int) * pcs);
    int *d = malloc(sizeof(int) * pcs);
    int *e = malloc(sizeof(int) * pcs);
    int *result = malloc(sizeof(int));
    int **n = malloc(sizeof(int) * ps * pcs);
    n[0] = a, n[1] = b, n[2] = c, n[3] = d, n[4] = e;

    // [[0, 0], [2, 2], [3, 10], [5, 2], [7, 0]]) == 20
    ps = 5;
    a[0] = 0, a[1] = 0;
    b[0] = 2, b[1] = 2;
    c[0] = 3, c[1] = 10;
    d[0] = 5, d[1] = 2;
    e[0] = 7, e[1] = 0;
    *result = minCostConnectPoints(n, ps, &pcs);
    printf("\n%d\n", *result);
    if(*result != 20){returnVal = 1;}

    // [[3, 12], [-2, 5], [-4, 1]] == 18
    ps = 3;
    a[0] = 3, a[1] = 12;
    b[0] = -2, b[1] = 5;
    c[0] = -4, c[1] = 1;
    *result = minCostConnectPoints(n, ps, &pcs);
    printf("\n%d\n", *result);
    if(*result != 18){returnVal = 1;}

    // [[0, 0], [1, 1], [1, 0], [-1, 1]]) == 4
    ps = 4;
    a[0] = 0, a[1] = 0;
    b[0] = 1, b[1] = 1;
    c[0] = 1, c[1] = 0;
    d[0] = -1, d[1] = 1;
    *result = minCostConnectPoints(n, ps, &pcs);
    printf("\n%d\n", *result);
    if(*result != 4){returnVal = 1;}

    // [[2, -3], [-17, -8], [13, 8], [-17, -15]] == 53
    ps = 4;
    a[0] = 2, a[1] = -3;
    b[0] = -17, b[1] = -8;
    c[0] = 13, c[1] = 8;
    d[0] = -17, d[1] = -15;
    *result = minCostConnectPoints(n, ps, &pcs);
    printf("\n%d\n", *result);
    if(*result != 53){returnVal = 1;}

    // [[-1000000, -1000000], [1000000, 1000000]] = 4000000
    ps = 2;
    a[0] = -1000000, a[1] = -1000000;
    b[0] = 1000000, b[1] = 1000000;
    *result = minCostConnectPoints(n, ps, &pcs);
    printf("\n%d\n", *result);
    if(*result != 4000000){returnVal = 1;}

    // [[-14, -14], [-18, 5], [18, -10], [18, 18], [10, -2]] == 102
    ps = 5;
    a[0] = -14, a[1] = -14;
    b[0] = -18, b[1] = 5;
    c[0] = 18, c[1] = -10;
    d[0] = 18, d[1] = 18;
    e[0] = 10, e[1] = -2;
    *result = minCostConnectPoints(n, ps, &pcs);
    printf("\n%d\n", *result);
    if(*result != 102){returnVal = 1;}

    free(a); free(b); free(c); free(d); free(e); free(n); free(result);
    return returnVal;
}
