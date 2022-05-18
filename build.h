
#pragma once


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

#ifdef _WIN32
#include <Windows.h>
#include <direct.h>
#include <sys/types.h>
#include <sys/stat.h>
#define mkdir(a, b) _mkdir(a)
#define rmdir _rmdir
#define mkdir(A, B)  _mkdir(A)
#define chdir  _chdir
#else
#include <sys/wait.h>
#include <sys/stat.h>
#include <unistd.h>
#endif


#if defined(_WIN32) && defined(_MSC_VER) && !defined(__clang__)
#define BUILD_WINDOWS
#define BUILD_WINDOWS_MSC
#define COMPILER_NAME "cl"
#define RUN ""
#elif defined(_WIN32) && defined(__clang__)
#define BUILD_WINDOWS
#define BUILD_WINDOWS_CLANG
#define RUN ""
#define COMPILER_NAME "clang"
#elif defined(__linux__) && defined(__clang__)
#define BUILD_LINUX
#define BUILD_LINUX_CLANG
#define COMPILER_NAME "clang"
#define RUN "./"
#elif defined(__linux__) && defined(__GNUC__)
#define BUILD_LINUX
#define BUILD_LINUX_GCC
#define COMPILER_NAME "gcc"
#define RUN "./"
#else
#error Unknown Platform/Compiler
#endif

#ifdef __linux__

int call(const char* command)
{
    system(command);

    int test_result = 0;
    int stat = 0;
    wait(&stat);
    if (WIFEXITED(stat))
    {
        test_result = WEXITSTATUS(stat);
    }
    else if (WIFSIGNALED(stat))
    {
        test_result = WTERMSIG(stat);
    }
    return test_result;
}
#else
int call(const char* command)
{
    return system(command);
}
#endif
