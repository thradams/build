# Multiplatform build for C

The idea of this repository is to be **very simple**, just to **show the basic idea**.

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

The maketest is also a sample of a tool that is compiled and used by the build.
Other tools can be added.

Some defines and functions may be useful. A header file build.h is the complement
for the build.

## build.c

[Build.c](build.c) is where we add our build "script".
Preprocessor is very handy at this point to concatenate strings and have options. 
We also can pass options to the build using defines and use these define internally.

[build.h](build.h) is were we add common defines and utils.

## More details about maketest tool

With -DTEST option the tool [tools/maketest.c](tools/maketest.c) is built in advance. Then it runs searching for 

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

# How do I use?

I don't use this build system for the cicle "do { build->debug } while(1)". For this
task I use the IDE project. (Visual Studio for instance). It does not have the 
"compile only changed files" feature, although it could be added.

I use this build run unit test and to compile for other platftorms, for instance I use 
WSL on windows to build the linux version using clang and gcc. It is also used the create
the "deploy" or installer (this feature is not showed here)


# Tool
Command line tool to generate the directory structure with samples
https://github.com/thradams/buildgen
