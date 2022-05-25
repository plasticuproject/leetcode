#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// gcc peeking_iterator.c -O1 -fsanitize=address -fno-omit-frame-pointer -std=gnu99; ./a.out


struct Iterator {
    // Returns true if the iteration has more elements.
    bool (*hasNext)();

    // Returns the next element in the iteration.
    int (*next)();
};

struct PeekingIterator {
    struct Iterator* iterator;
    int previous;
    bool hasPeeked;

};

struct PeekingIterator* Constructor(struct Iterator* iter) {
    struct PeekingIterator* piter = malloc(sizeof(struct PeekingIterator));
    piter->iterator = iter;
    piter->hasPeeked = false;
    return piter;
}

int peek(struct PeekingIterator* obj) {
    if(!obj->hasPeeked){
        obj->previous = (obj->iterator->next)();
        obj->hasPeeked = true;
    }
    return obj->previous;
}

int next(struct PeekingIterator* obj) {
    if(obj->hasPeeked){
        obj->hasPeeked = false;
        return obj->previous;
    }
    return (obj->iterator->next)();
}

bool hasNext(struct PeekingIterator* obj) {
    return((obj->hasPeeked) || (obj->iterator->hasNext)());
}


/**
 * Your PeekingIterator struct will be instantiated and called as such:
 * PeekingIterator* obj = peekingIteratorCreate(arr, arrSize);
 * int param_1 = peek(obj);
 * int param_2 = next(obj);
 * bool param_3 = hasNext(obj);
 * peekingIteratorFree(obj);
*/
