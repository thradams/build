
#include "file2.h"


int mult(int a, int b)
{
    return a * b;
}


#ifdef TEST

int mult_test()
{
    

    if (mult(2, 3) != 6)
        return __LINE__;

    return 0;
}


#endif