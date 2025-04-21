#include <stdio.h>


int main()
{
    int num;
    printf("Massiv rezmernost: ");
    scanf("%d", &num);
    int arr[num];

    for(int i = 0; i < num; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < num; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    for(int i = 0; i < num; i++)
    {
        arr[i]= NULL;
    }
    for(int i = 0; i < num; i++)
    {
        printf("%d\t", arr[i]);
    }

    return 0;
}
