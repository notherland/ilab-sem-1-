#include <stdio.h>
#include <cmath>
#include <assert.h>

const char FAIL = 0;
const char SUCCESS = 1;
const char ST_FULL = 2;
const char ST_EMPTY = 3;
const char NULL_PTRS = 4;
const char DATANULLPTR = 5;
const char SIZENULLPTR = 6;
const int CAPACITY = 10;
const int MAXSIZE = CAPACITY + 1;

struct stack {
    char data[CAPACITY];
    size_t size;
    int Errorcode;
};

char Pop(struct stack *st_ptrs);

bool Push(struct stack *st_ptrs, char x);

bool StackOK(struct stack *st_ptrs);

void Dump(struct stack *st_ptrs);

int main() {

    struct stack st = {{0}, 0, 0};
    char x = NAN;
    scanf("%c", &x);
    Push(&st, x);

}

bool Push(struct stack *st_ptrs, char x) {
    if (!StackOK(st_ptrs))
        Dump(st_ptrs);
    /*if (st_ptrs->size >= CAPACITY)
        if (!StackOK(st_ptrs))
            Dump(st_ptrs);*/
    st_ptrs->data[st_ptrs->size++] = x;
    if (!StackOK(st_ptrs))
        Dump(st_ptrs);
    return SUCCESS;
}

char Pop(struct stack *st_ptrs) {


    if (st_ptrs->size == 0) {
        st_ptrs->Errorcode = ST_EMPTY;
        return FAIL;
    }
    st_ptrs->size--;
    return st_ptrs->data[st_ptrs->size - 1];

}

bool StackOK(struct stack *st_ptrs) {
    assert(st_ptrs);
    if (st_ptrs->data == nullptr) {
        st_ptrs->Errorcode = DATANULLPTR;
        return FAIL;
    }
    /*if (st_ptrs->size == nullptr) {
        st_ptrs->Errorcode = SIZENULLPTR;
        return FAIL;}*/
    if (st_ptrs->size <= 0) {
        st_ptrs->Errorcode = ST_EMPTY;
        return FAIL;
    }
    if (st_ptrs->size > CAPACITY) {
        st_ptrs->Errorcode = ST_FULL;
        return FAIL;
    }
    if (st_ptrs->size > CAPACITY) {
        st_ptrs->Errorcode = ST_FULL;
        return FAIL;
    }

    return SUCCESS;
}

void Dump(struct stack *st_ptrs) {
    printf("Stack size %d", st_ptrs->size);
    printf("There is an error");
    switch (st_ptrs->Errorcode) {
        case 2: {
            printf("Stack is overflow");
            break;
        }
        case 3: {
            printf("Stack is empty");
            break;
        }
            //  case 4: {printf ("Stack is overflow"); break;};
        case 5: {
            printf("Null pointer to data");
            break;
        }
        case 6: {
            printf("Null pointer to size");
            break;
        }
    }

}
