
/*
* gcc -DTEST build.c -o build && ./build
* 
* cl -DTEST build.c & build
*/
#include "build.h"
#include <stdio.h>


#define SOURCE \
   " file1.c" \
   " file2.c" \
   " main.c"  \

int main()
{
    printf("Build using " COMPILER_NAME "\n");

#ifdef TEST

#ifdef BUILD_WINDOWS_MSC
    call("cl tools/maketest.c");
    call("maketest.exe unit_test.c " SOURCE);
    call("cl -o out.exe" " -DTEST unit_test.c " SOURCE);
    call("out.exe");
#endif

#ifdef BUILD_LINUX_GCC
    call("gcc -o maketest tools/maketest.c");
    call("./maketest unit_test.c " SOURCE);
    call("gcc -o out" " -DTEST unit_test.c " SOURCE);
    call("./out");
#endif


#else

#ifdef BUILD_WINDOWS_MSC
    call("cl -o out.exe" SOURCE);
#endif

#ifdef BUILD_LINUX_GCC
    call("gcc -o out" SOURCE);
#endif

#endif
}
