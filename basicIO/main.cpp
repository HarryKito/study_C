#include <stdio.h>

#include "include.h"

#ifndef test_include
#define test_include 0
#endif

int main() {
    puts("Hi, Cpp");
    printf("CMake does work well !? ::%s::\n",test_include ? "yes":"nope");

    printf("%-12s : %2zu byte\n", "char", sizeof(char));
    printf("%-12s : %2zu byte\n", "short", sizeof(short));
    printf("%-12s : %2zu byte\n", "int", sizeof(int));
    printf("%-12s : %2zu byte\n", "long", sizeof(long));
    printf("%-12s : %2zu byte\n", "long long", sizeof(long long));
    printf("%-12s : %2zu byte\n", "float", sizeof(float));
    printf("%-12s : %2zu byte\n", "double", sizeof(double));
    return 0;
}
