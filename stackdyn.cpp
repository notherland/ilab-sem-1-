
#include <stdio.h>
#include <cmath>
#include <assert.h>
#include <stdlib.h>

const char FAIL = 0;
const char SUCCESS = 1;
const char ST_FULL = 2;
const char ST_EMPTY = 3;
const char NULL_PTRS = 4;
const char DATANULLPTR = 5;
const char SIZENULLPTR = 6;
const int MAXSIZE = 3;

struct stack {
    char* data;
    size_t size;
    size_t maxsize;
    int Errorcode;
};

char Pop(struct stack *st_ptrs);

bool Push(struct stack *st_ptrs, char x);

bool StackOK(struct stack *st_ptrs);

void Dump(struct stack *st_ptrs);

void Mem_increase (struct stack *st_ptrs);

void Mem_reduce (struct stack *st_ptrs);

void Stack_Init (struct stack *st_ptrs);

void Stack_Destraction (struct stack *st_ptrs);


int main() {


    struct stack st;
    Stack_Init (&st);
    char x = NAN, elem;
    scanf("%c", &x);
    Stack_Init (&st);
    Push(&st, x);
    printf ("|1|\n");
    Push(&st, x);
    printf ("|2|\n");
    Push(&st, x);
    printf ("|3|\n");
    Push(&st, x);
    printf ("|4|\n");
    printf ("%c", Pop(&st));
    Stack_Destraction(&st);

}


void Stack_Init (struct stack *st_ptrs)
{
    assert (st_ptrs);
    st_ptrs->size = 0;
    st_ptrs->maxsize = MAXSIZE;
    st_ptrs->data = (char*)calloc(st_ptrs->size, sizeof(char));
    st_ptrs->Errorcode = -1;
}

bool Push(struct stack *st_ptrs, char x) {
    if (!StackOK(st_ptrs))
        Dump(st_ptrs);
    /*if (st_ptrs->size >= CAPACITY)
        if (!StackOK(st_ptrs))
            Dump(st_ptrs);*/
    Mem_increase(st_ptrs);
    st_ptrs->data[st_ptrs->size++] = x;
    if (!StackOK(st_ptrs))printf ("1\n");
        Dump(st_ptrs);
    return SUCCESS;
}

char Pop(struct stack *st_ptrs) {
    if (st_ptrs->size == 0) {
        st_ptrs->Errorcode = ST_EMPTY;
        StackOK(st_ptrs);
    }
    Mem_reduce (st_ptrs);
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
    if (st_ptrs->size > MAXSIZE) {
        st_ptrs->Errorcode = ST_FULL;
        return FAIL;
    }

    return SUCCESS;
}

void Dump(struct stack *st_ptrs) {
    printf("Stack size %d\n", st_ptrs->size);
    printf("There is an error:\n");
    switch (st_ptrs->Errorcode) {
        case 2: {
            printf("Stack is overflow\n");
            break;
        }
        case 3: {
            printf("Stack is empty\n");
            break;
        }
            //  case 4: {printf ("Stack is overflow"); break;};
        case 5: {
            printf("Null pointer to data\n");
            break;
        }
        case 6: {
            printf("Null pointer to size\n");
            break;
        }
    }

}

void Mem_increase (struct stack *st_ptrs)
{
       st_ptrs->data = (char*)realloc(st_ptrs->data, st_ptrs->size + 1);
}

void Mem_reduce (struct stack *st_ptrs)
{
    st_ptrs->data = (char*)realloc(st_ptrs->data, st_ptrs->size - 1);
}

void Stack_Destraction (struct stack *st_ptrs)
{
    free (st_ptrs->data);
    st_ptrs->size = 0;
    st_ptrs->Errorcode = 0;
    st_ptrs-> maxsize = 0;
}

