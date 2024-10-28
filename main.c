#include <stdio.h>

void sort(int arr[], int n)
{
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(*(arr+j) > *(arr+j+1))
            {
                int k = *(arr+j);
                *(arr+j) = *(arr+j+1);
                *(arr+j+1) = k;
            }
        }
    }
}
int main()
{
    int n = 5;
    int mass[] = {-66, 33, -18, 25, 1};
    for(int i = 0; i < n; i++) printf("%d ", *(mass+i));
    int summ = 0, max = 0, min = 0;
    sort(mass,n);
    for(int i = 0; i < n; i++) summ+=*(mass+i);
    printf("\n---------------\n");
    printf("the average value of the array: %d\n", summ/n);
    printf("the median value of the array: %d\n", *(mass+n/2));
    printf("the maximum value of the array: %d\n", *(mass+n-1));
    printf("the minimum value of the array: %d\n", *(mass));

    return 0;
}
