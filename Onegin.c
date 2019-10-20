#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

struct strings {
    int *ptr;
    int len;
};

int Length(FILE *f);

void Input(char Inputbuffer[], int size, FILE *readfile);

int Amount(char *buffer, int size);

int Comparison(const void *a, const void *b);

void Output(struct strings *text, int n_lines, FILE *writefile);

struct strings Maketext(char *buffer, int *number, int *n_lines);

int main() {

    /* char r1[7] = {'A, ojff'};
     char r2[5] = {'A, ff'};
     struct strings d1 = {*r1, 7};
     struct strings d2 = {*r2, 5};
     printf("%d", Comparison(&d1, &d2));*/
    int i = 0, size, n_lines = 0, number = 0;
    FILE *readfile = fopen("/home/ksenia/CLionProjects/Onegin/file.txt", "r");
    FILE *writefile = fopen("/home/ksenia/CLionProjects/Oneginsorted.txt", "w");
    assert (readfile != NULL);
    assert (writefile != NULL);
    size = Length(readfile);
    //fclose(readfile);
    char *buffer = (char *) calloc(size, sizeof(char) + 1);
    if (buffer == NULL)
        printf("Недостаточно памяти");
    struct strings *text = (struct strings *) calloc(size, sizeof(struct strings) + 1);
    if (text == NULL)
        printf("Недостаточно памяти");
    Input(buffer, size, readfile);
    n_lines = Amount(buffer, size);
    for (i = 0; i < n_lines; i += 1) {
        text[i] = Maketext(buffer, &number, &n_lines);
    }
    qsort(text, n_lines, sizeof(struct strings), Comparison);
    Output(text, n_lines, writefile);
    fclose(writefile);
    free(buffer);
    free(text);
}

void Input(char Inputbuffer[], int size, FILE *readfile) {
    //FILE *fp;
    if (fread(Inputbuffer, sizeof(char), size, readfile) == 0)
        printf("error");
    //fclose(fp);

}

int Length(FILE *readfile) {
    assert (readfile != 0);
    int length = 0;
    fseek(readfile, 0, SEEK_END);
    length = ftell(readfile);
    fseek(readfile, 0, SEEK_SET);
    return length;
}


int Amount(char *buffer, int size) {
    assert (buffer != 0);
    int counterl = 0, p = 0;
    for (p = 0; p < size; p += 1) {
        if (buffer[p] == '\n') {
            buffer[p] = '\0';
            /*if (p != 0 && (buffer[p - 1] == '\0') && (buffer[p] == '\n'))
                buffer[p] = '\0';
            while (buffer[p] == '\n') {
                buffer[p] = '\0';*/
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
    // printf ("%d %d\n", s1.len, s2.len);
    // printf ("%s\n%s\n", string1, string2);
    int x1 = 0, x2 = 0;
    while ((!isalpha(*(string1 + x1))) && (x1 + 1 < s1.len - 1)) x1 += 1;
    while ((!isalpha(*(string2 + x2))) && (x2 + 1 < s2.len - 1)) x2 += 1;
    while ((x1 + 1 < s1.len) && (x2 + 1 < s2.len) &&
           ((*(string1 + x1) == *(string2 + x2)) || (!isalpha(*(string1 + x1))) || (!isalpha(*(string2 + x2))))) {
        while (!isalpha(*(string1 + x1))) x1 += 1;
        while (!isalpha(*(string2 + x2))) x2 += 1;
        if (*(string1 + x1) == *(string2 + x2)) {
            x1 += 1;
            x2 += 1;
        }
    }
   // printf("%d\n", *(string1 + x1) - *(string2 + x2));
    return (*(string1 + x1) - *(string2 + x2));
}

struct strings Maketext(char *buffer, int *number, int *n_lines) {
    assert (buffer != 0);
    assert (number != 0);
    assert (n_lines != 0);
    struct strings make;
    int l_length = 0;
    l_length = strlen(buffer + *number);
    //printf("%d ", l_length);
    while (l_length == 0) {
        *number += 1;
        l_length = strlen(buffer + *number);
        *n_lines = *n_lines - 1;
    }
    //printf("%d ", l_length);
    make.ptr = buffer + *number;
    *number = *number + l_length + 1;
    make.len = l_length;
    // printf("%d\n", *number);
    //printf ("%s\n", make.ptr);
    return make;
}

void Output(struct strings *text, int n_lines, FILE *writefile) {
    int i = 0;
    for (i = 0; i < n_lines; i += 1) {
        printf("%s\n", text[i].ptr);
    }
    for (int i = 0; i < n_lines; i++) {
        fprintf(writefile, "%s\n", text[i].ptr);
    }
}
