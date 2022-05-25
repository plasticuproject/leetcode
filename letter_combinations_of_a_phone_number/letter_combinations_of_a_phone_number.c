#include <stdio.h>
#include <stdlib.h>

// gcc letter_combinations_of_a_phone_number.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out

#define MAX 5


char *mapper(char digit){
    /* Given a string representation
     * of a number, returns a string of
     * letters mapped to that number. */
    int digitInt = digit;
    int digitModifier = (digitInt + 47 + (((digitInt + 50) % 50) * 2));
    int offset, count;
    if(digitInt == 55){offset = 0, count = 4;}
    else if(digitInt == 56){offset = 1, count = 4;}
    else if(digitInt == 57){offset = 1, count = 5;}
    else{offset = 0, count = 3;}
    char *result = malloc((count - offset) + 1);
    int i, j;
    for(i = offset, j = 0; i < count; i++, j++){result[j] = (digitModifier + i);}
    result[count - offset] = '\0';
    return result;
}

char **letterCombinations(char* digits, int* returnSize){
    /* Given a string containing digits from 2-9
     * inclusive, returns all possible letter combinations
     * that the number could represent. */
    *returnSize = 0;
    int digitSize = 0;
    int i, j;
    for(i = 0; digits[i] != '\0'; i++){digitSize++;}
    if (digitSize == 0){return NULL;}

    char* tempMap;
    int resultSize = 1;
    int mapLength = 0;
    for(int i = 0; i < digitSize; i++){
        tempMap = mapper(digits[i]);
        for(j = 0; tempMap[j] != '\0'; j++){mapLength++;}
        resultSize *= mapLength;
        free(tempMap);
    }

    char **ret = malloc(resultSize * sizeof(char*));
    int *pickUp = calloc(digitSize, sizeof(int));
    int lastDigitIndex = 0;
    tempMap = mapper(digits[digitSize - 1]);
    for(i = 0; tempMap[i] != '\0'; i++){lastDigitIndex++;}
    free(tempMap);

    while(pickUp[digitSize - 1] < lastDigitIndex){
        ret[*returnSize] = malloc(digitSize + 1 * sizeof(char));
        int idx = 0;
        for(int i = 0; i < digitSize; i++){
            tempMap = mapper(digits[i]);
            ret[*returnSize][idx] = tempMap[pickUp[i]];
            free(tempMap);
            idx++;
        }
        ret[*returnSize][idx] = '\0';
        (*returnSize)++;
        pickUp[0] = pickUp[0] + 1;
        for(int i = 0; i + 1 < digitSize; i++){
            mapLength = 0;
            tempMap = mapper(digits[i]);
            for(j = 0; tempMap[j] != '\0'; j++){mapLength++;}
            free(tempMap);
            if(pickUp[i] == mapLength){
                pickUp[i] = 0;
                pickUp[i + 1] = pickUp[i + 1]  + 1;
            }
            else{break;}
        }
    }
    free(pickUp);
    return ret;
}


//TESTS
int main(void){
    int i, s;
    int rs = 0;
    char *n[MAX];
    char **result;
    char *test[1024]; // 4^MAX

    // assert ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"] == 23
    test[0] = "ad", test[1] = "ae", test[2] = "af", test[3] = "bd", test[4] = "be";
    test[5] = "bf", test[6] = "cd", test[7] = "ce", test[8] = "cf";
    *n = "23";
    s = 2;
    result = letterCombinations(*n, &rs);
    for(i= 0; i < rs; i++){
        printf("%s ", result[i]);
        free(result[i]);
    }
    printf("\n");
    free(result);

    // assert ["a", "b", "c"] == 2
    test[0] = "2"; test[1] = "2"; test[2] = "2";
    *n = "2";
    s = 1;
    result = letterCombinations(*n, &rs);
    for(i= 0; i < rs; i++){
        printf("%s ", result[i]);
        free(result[i]);
    }
    printf("\n");
    free(result);
    return 0;
}
