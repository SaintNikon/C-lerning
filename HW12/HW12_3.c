#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 5;
    int *p = calloc(n, sizeof(int));
    p[0] = 254;
    p[1] = 128;
    p[2] = 66;
    p[3] = 5;
    p[4] = 782;
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", p[i]);
    }

    free(p);
    printf("\n");
    for(int i = 0; i < n; i++)
    {
        printf("%d\t", p[i]);
    }
    /*int num = 5;
    int p[5];
    p[0] = 254;
    p[1] = 128;
    p[2] = 66;
    p[3] = 5;
    p[4] = 782;
    for(int i = 0; i < num; i++)
    {
        printf("%d\t", p[i]);
    }
    printf("\n");
    for(int i = 0; i < num; i++)
    {
        p[i]= NULL;
    }
    for(int i = 0; i < num; i++)
    {
        printf("%d\t", p[i]);
    }*/

    return 0;
}
