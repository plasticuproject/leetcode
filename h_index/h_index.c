#include <stdio.h>

// gcc h_index.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


void swap(int *first, int *second){
    int temp = *first;
    *first = *second;
    *second = temp;
}

int partition(int arr[], int lower, int upper){
    int i = (lower - 1);
    int pivot = arr[upper];
    int j;
    for(j = lower; j < upper; j++){
        if(arr[j] <= pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[upper]);
    return (i + 1);
}

void quickSort(int arr[], int lower, int upper){
    if(upper > lower){
        int partitionIndex = partition(arr, lower, upper);
        quickSort(arr, lower, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, upper);
    }
}

int hIndex(int* citations, int citationsSize){
    /* Given an array of integers citations
     * where citations[i] is the number of
     * citations a researcher received for their
     * ith paper, return compute the researcher's
     * h-index. */

    quickSort(citations, 0, (citationsSize - 1));
    int i;
    for(i = 0; i < citationsSize; i++){
        if(citations[i] >= (citationsSize - i)){
            return citationsSize - i;
        }
    }
    return 0;
}


// TESTS
int main(void) {
    int returnVal = 0;

    // assert [3, 0, 6, 1, 5] == 3
    int c[5] = {3, 0, 6, 1, 5};
    int s = sizeof(c) / sizeof(int);
    int result = hIndex(c, s);
    printf("%d", result);
    if(result != 3){returnVal = 1;}

    printf("\n");
    return returnVal;
}
