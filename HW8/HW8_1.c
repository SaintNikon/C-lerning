#include <stdio.h>


int main()
{
    int a = 30;
    int *pa = &a;
    printf("var a = %d\n", a);
    printf("address a = %p\n", (void*)pa);
    *pa = 50;
    printf("var a = %d\n", a);
    printf("address a = %p\n", (void*)pa);
    return 0;
}
