#include <stdio.h>
#include "include.h"

int main() {
    puts("Hi, Cpp");
    printf("CMake does work well !? ::%s::",test_include() ? "yes":"nope");
    return 0;
}