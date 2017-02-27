#include "example.hpp"
#include <stdio.h>

int MYLIB_API helloworld(void)
{
    printf("Hello World DLL");
    return 42;
}