#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();
char** split_string(char*);

char* kangaroo(int x1, int v1, int x2, int v2) 
{
    int n=1;
    if(x1==x2&&v1==v2)
    {
        return "YES";
    }
    else if (v1==v2&&x1!=x2)
        return "NO";
    else if((x1<x2&&v1<v2)||(x2<x1&&v2<v1))
        return "NO";
    else if(((x2-x1)%(v2-v1)==0)&&x1!=x2)
        return "YES";
    return "NO"; 
}

int main()
{
    FILE* fptr = fopen(getenv("OUTPUT_PATH"), "w");

    char** x1V1X2V2 = split_string(readline());

    char* x1_endptr;
    char* x1_str = x1V1X2V2[0];
    int x1 = strtol(x1_str, &x1_endptr, 10);

    if (x1_endptr == x1_str || *x1_endptr != '\0') { exit(EXIT_FAILURE); }

    char* v1_endptr;
    char* v1_str = x1V1X2V2[1];
    int v1 = strtol(v1_str, &v1_endptr, 10);

    if (v1_endptr == v1_str || *v1_endptr != '\0') { exit(EXIT_FAILURE); }

    char* x2_endptr;
    char* x2_str = x1V1X2V2[2];
    int x2 = strtol(x2_str, &x2_endptr, 10);

    if (x2_endptr == x2_str || *x2_endptr != '\0') { exit(EXIT_FAILURE); }

    char* v2_endptr;
    char* v2_str = x1V1X2V2[3];
    int v2 = strtol(v2_str, &v2_endptr, 10);

    if (v2_endptr == v2_str || *v2_endptr != '\0') { exit(EXIT_FAILURE); }

    char* result = kangaroo(x1, v1, x2, v2);

    fprintf(fptr, "%s\n", result);

    fclose(fptr);

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}

char** split_string(char* str) {
    char** splits = NULL;
    char* token = strtok(str, " ");

    int spaces = 0;

    while (token) {
        splits = realloc(splits, sizeof(char*) * ++spaces);
        if (!splits) {
            return splits;
        }

        splits[spaces - 1] = token;

        token = strtok(NULL, " ");
    }

    return splits;
}
