#include <stdio.h>

const char ST_FULL = 1;
const char SUCCESS = 2;
const char FAIL = 3;
#define CAPACITY 10

template <typename T>

struct stack {
    T data[CAPACITY];
    size_t size;
};

template <typename T>
T Push ( struct stack *st_ptrs, char x);

template <typename T>
T Pop (struct stack* st_ptrs);


int main() {

    struct stack st = {{0},0};

    scanf ("%c", &x);
    status = Push (&st, x);

}

char Push (struct stack *st_ptrs, char x)
{
    if (st_ptrs->size>=CAPACITY)
        return ST_FULL;
    st_ptrs -> data[st_ptrs->size++] = x;
    return SUCCESS;

}

char Pop (struct stack* st_ptrs)
{
    if (st_ptrs->size == 0)
        return FAIL;
    st_ptrs->size--;
    return st_ptrs->data[st_ptrs->size - 1];

}

char Top (struct stack *st_ptrs)
{
    if (st_ptrs->size <= 0)
        return ST_FULL;
    return st_ptrs->data[st_ptrs->size - 1];

}
