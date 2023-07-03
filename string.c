#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>

struct node {
    char string[2048];
};



void print_string(const char *string) {
    (void)printf("%s\n", string);
}

int main(void) {

    (void)puts("Testing Recursion!");


    struct node n;
    char hello[] = "Hello world!";
    (void)strncpy(n.string, hello, sizeof(n.string));
    n.string[13] = '\0';

    print_string(n.string);

    char hello_again[] = "Hello world again!";
    (void)strncpy(n.string, hello_again, sizeof(n.string));
    n.string[19] = '\0';

    print_string(n.string);

    size_t size = sizeof n.string;

    (void)printf("size of array %d\n", (int)size);


    return EXIT_SUCCESS;
}
