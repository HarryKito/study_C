#include <stdio.h>

#include "include.h"

#ifndef test_include
#define test_include 0
#endif

int main() {
    puts("Hi, Cpp");
    printf("CMake does work well !? ::%s::",test_include ? "yes":"nope");
    return 0;
}
