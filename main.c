
#include <stdio.h>

//forward declaration
int test_main(void);


int main()
{
#ifdef TEST
    printf("Hello Unit Test!\n");
    return test_main();
#endif

    printf("Hello World!\n");
}

