
#include "file2.h"
#include <stdbool.h>

bool IsValid(const char* s)
{
    if (s == 0)
        return false;
    return true;
}



#ifdef TEST
#define ASSERT(X) if (!(X)) return __LINE__
int IsValidTest()
{
    ASSERT(!IsValid(0));
    return 0;
}


#endif