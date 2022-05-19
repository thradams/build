
#include "file1.h"

int sum(int a, int b)
{
    return a + b;
}


#ifdef TEST

int sum_test()
{
    if (sum(2, 2) != 6)
        return __LINE__;

    return 0;
}


#endif
