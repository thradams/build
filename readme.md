# Multiplatform build for C

The idea of this repository is to be very simple, just to show the **basic idea**.

Only two SO and two compilers have been added but it can be extended.

- It only depends on C
- Unit tests

## Building your C project on Windows

Open the Developer command prompt and type
```
cl build.c && build
```
## Building your C project on Linux

Open the terminal
```
gcc build.c -o build && ./build
```

## Build and run your C project with unit tests
Add -DTEST, for linux or windows.

For instance:

```
gcc -DTEST build.c -o build && ./build
```

Output

```
build2$ gcc -DTEST build.c -o build && ./build
Build using gcc
----------------------------------------------------------------
make test tool Thiago A 2021
file1.c                                            1
file2.c                                            1
main.c                                             0
file 'unit_test.c' was updated
----------------------------------------------------------------
Hello Unit Test!

file1.c
  sum_test                                           FAILED 15
file2.c
  mult_test                                          OK
```

The idea behind the maketest code generation is to **be simple to be customized**
instead of be very complex with a lot of options. The same for the build code.

Some defines and function may be useful and common for many builds in this case
they can be added into build.h for future use.



## More details about maketest tool

With -DTEST option the tool is built before. Then it runs searching for 

```cpp
#ifdef TEST
#endif
```
 ...and then for function pattern "int funcname()" or "int funcname(void)" inside ifdefs.
 
```cpp
#ifdef TEST
int funcname()
{
  return 0;
}
#endif
```

In case you want to add your unit test facilities..

```cpp
#ifdef TEST
#include "myunittest.h"
int funcname()
{
  MY_ASSERT(1 == 1);
  return 0;
}
#endif
```

