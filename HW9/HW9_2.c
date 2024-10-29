#include <stdio.h>

int mine[5][5] = {{22,57,114,7,4},
                  {4,28,98,98,99},
                  {6,6,25,32,54},
                  {88,38,44,18,16},
                  {99,10,44,85,5}};

int open[5][5] = {{0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0},
                  {0,0,0,0,0}};

int MassOpen (int x, int i, int j)
{
    if (mine[i][j] == x) open[i][j] = 1;
    if (i == 0 & j == 0) return 0;
    else if (j == 0) return MassOpen(x, i - 1, 4);
    else return MassOpen(x, i, j - 1);
}
int main()
{
    int x;
    while(1)
    {
        for(int i = 0; i < 5; i++)
        {
            for(int j = 0; j < 5; j++)
            {
                printf("%d ", open[i][j]);
            }
            printf("\n");
        }
        printf("Enter num: ");
        scanf("%d", &x);
        MassOpen(x, 4, 4);
    }
    return 0;
}
