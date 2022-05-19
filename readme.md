# Multiplatform build for C

The idea of this repository is to be very simple, just to show the basic idea.

Only two SO and two compilers have been added but it can be extended.

- It only depends on C
- Unit tests

## Build on Windows

Open the Developer command prompt and type
```
cl build.c && build
```
## Build on Linux

Open the terminal
```
gcc build.c -o build && ./build
```

## Running unit tests
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
