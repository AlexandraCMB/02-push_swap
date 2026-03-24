#include <stdio.h>
#include <limits.h>
#include <stdint.h>

int main() {
    printf("int Range:    %d to %d\n", INT_MIN, INT_MAX);
    printf("size_t Max:   %llu\n", (unsigned long long)SIZE_MAX);
    printf("Size of int:  %zu bytes\n", sizeof(int));
    printf("Size of size_t: %zu bytes\n", sizeof(size_t));
    return 0;
}