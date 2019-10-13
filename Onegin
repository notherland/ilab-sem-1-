#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

int Length(FILE *f);

void Input(char Inputbuffer[], FILE *f, int size);

int Amount(char *buffer, int size);

int Comparison(const void *a, const void *b);

void Output();

struct strings {
    int *ptr;
    int len;
};

struct strings Maketext(char *buffer, int *r1, int *r, int size);

int main() {

    int i = 0, n = 0, size, n_lines = 0, n_c = 0;
    FILE *f = fopen("/home/ksenia/CLionProjects/Onegin/file.txt", "r");
    assert (f != NULL);
    size = Length(f);
    fclose(f);
    char *buffer = (char *) calloc(size, sizeof(char) + 1);
    if (*buffer = 0)
        printf("Недостаточно памяти");
    struct strings *text = (struct strings *) calloc(size, sizeof(struct strings) + 1);
    if (*text = 0)
        printf("Недостаточно памяти");
    Input(buffer, size);
    n_lines = Amount(buffer, size);
    for (i = 0; i < n_lines; i += 1) {
        text[i] = Maketext(buffer, &n_c, &n, size);
    }
    qsort(text, n_lines, sizeof(struct strings), Comparison);
    for (i = 0; i < n_lines; i += 1) {
        printf("%s\n", text[i].ptr);
    }
}

void Input(char Inputbuffer[], FILE *f, int size) {
    if (fread(Inputbuffer, sizeof(char), size, f = fopen("/home/ksenia/CLionProjects/Onegin/file.txt", "r")) == 0)
        printf("error");
}

int Length(FILE *f) {
    int length = 0;
    fseek(f, 0, SEEK_END);
    length = ftell(f);
    fseek(f, 0, SEEK_SET);
    return length;
}


int Amount(char *buffer, int size) {
    assert (buffer != 0);
    int counterl = 1, p = 0;
    for (p = 0; p < size; p += 1) {
        if ((buffer[p - 1] == '\0') && (buffer[p] == '\n'))
            buffer[p] = ' ';
        if (buffer[p] == '\n') {
            buffer[p] = '\0';
            counterl += 1;
        }
    }
    return counterl;
}

int Comparison(const void *a, const void *b) {
    assert (a != 0);
    assert (b != 0);
    struct strings s1 = *(struct strings *) a;
    struct strings s2 = *(struct strings *) b;
    char *string1 = s1.ptr;
    char *string2 = s2.ptr;
    // printf ("%c %c\n", *string1, *string2);
    int x1 = 0, x2 = 0;
    while ((x1 + 1 < (s1.len)) && (x2 + 1 < (s2.len)) && (*(string1 + x1) == *(string2 + x2))) {
        while (isalpha(*(string1 + x1)) == 0) { x1 += 1; }
        while (!isalpha(*(string2 + x2))) x2 += 1;
        x1 += 1;
        x2 += 1;

    }
    return (*(string1 + x1) - *(string2 + x2));
}

struct strings Maketext(char *buffer, int *r1, int *r, int size) {
    struct strings make;
    make.ptr = buffer + *r1;
    *r = *r1;
    while ((buffer[*r1] != '\0') && (*r1 < size)) {
        *r1 += 1;
    }
    *r1 += 1;
    make.len = *r1 - *r;
    return make;
}

void Output();




