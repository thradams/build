# This is a template project to create multiplatform C programs

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
Add -DTEST. For instance:

```
gcc -DTEST build.c -o build && ./build
```



