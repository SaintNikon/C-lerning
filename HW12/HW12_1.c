#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    printf("Razmernost massiva: ");
    scanf("%d", &n);
    int *p = calloc(n, sizeof(int));
    if (p == NULL)
    {
        printf("Error memory!\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }

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

    return 0;
}
