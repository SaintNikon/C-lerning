#include <stdio.h>
#include <stdlib.h>

int main()
{
    int mass[5] = {-5, 33, 27, 16, -1};
    for(int i = 0; i < 5; i++) printf("%d ", *(mass+i));
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            if(*(mass+j) > *(mass+j+1))
            {
                int k = *(mass+j);
                *(mass+j) = *(mass+j+1);
                *(mass+j+1) = k;
            }
        }
    }
    printf("\nmass is sorted\n");
    for(int i = 0; i < 5; i++) printf("%d ", *(mass+i));
    return 0;
}
