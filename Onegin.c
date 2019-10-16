#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <ctype.h>

struct strings {
    int *ptr;
    int len;
};

int Length(FILE *f);

void Input(char Inputbuffer[], int size);

int Amount(char *buffer, int size);

int Comparison(const void *a, const void *b);

void Output(struct strings *text, int n_lines, FILE *writefile);

struct strings Maketext(char *buffer, int *r1, int *r, int size);

int main() {

    int i = 0, number1 = 0, size, n_lines = 0, number2 = 0;
    FILE *readfile = fopen("/home/ksenia/CLionProjects/Onegin/file.txt", "r");
    FILE *writefile = fopen("/home/ksenia/CLionProjects/Oneginsorted.txt", "w");
    assert (readfile != NULL);
    size = Length(readfile);
    fclose(readfile);
    char *buffer = (char *) calloc(size, sizeof(char) + 1);
    if (buffer == NULL)
        printf("Недостаточно памяти");
    struct strings *text = (struct strings *) calloc(size, sizeof(struct strings) + 1);
    if (text == NULL)
        printf("Недостаточно памяти");
    Input(buffer, size);
    n_lines = Amount(buffer, size);
    for (i = 0; i < n_lines; i += 1) {
        text[i] = Maketext(buffer, &number2, &number1, size);
    }
    qsort(text, n_lines, sizeof(struct strings), Comparison);
    Output(text, n_lines, writefile);
    fclose(writefile);
    free (buffer);
    free (text);

}

void Input(char Inputbuffer[], int size) {
    FILE *fp;
    if (fread(Inputbuffer, sizeof(char), size, fp = fopen("/home/ksenia/CLionProjects/Onegin/file.txt", "r")) == 0)
        printf("error");
    fclose(fp);

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
    while (!isalpha(*(string1 + x1))) x1 += 1;
    while (!isalpha(*(string2 + x2))) x2 += 1;
    while ((x1 + 1 < s1.len) && (x2 + 1 < s2.len) && (*(string1 + x1) == *(string2 + x2))) {
        while (!isalpha(*(string1 + x1))) x1 += 1;
        while (!isalpha(*(string2 + x2))) x2 += 1;
        if (*(string1 + x1) == *(string2 + x2)) {
            x1 += 1;
            x2 += 1;
        }
    }

    return (*(string1 + x1) - *(string2 + x2));
}

struct strings Maketext(char *buffer, int *number2, int *number1, int size) {
    assert (buffer != 0);
    assert (number2 != 0);
    assert (number1 != 0);
    struct strings make;
    make.ptr = buffer + *number2;
    *number1 = *number2;
    while ((buffer[*number2] != '\0') && (*number2 < size)) {
        *number2 += 1;
    }
    *number2 += 1;
    make.len = *number2 - *number1;
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
