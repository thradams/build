
#include <stdio.h>
int test_main(void);



int main()
{
#ifdef TEST    
    return test_main();
#endif

    printf("Hello World!\n");
}

