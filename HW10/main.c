#include <stdio.h>

#define cycle(i) for(int i = 0; i < 5; i++)
#define PROG_1 1
#define PROG_2 2
#define FIB 2584

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

 int Fibonacci(int n)
 {
     if(n == 0) return 0;
     else if(n == 1) return 1;
     else return (Fibonacci(n - 1) + Fibonacci(n - 2));
 }

int main()
{
    int command = 0, n = 0, i = 0, x = 0;
    printf("Enter the program 1 or 2: \n");
    scanf("%d", &command);
    if (command == PROG_1)
        while ( n != FIB)
        {
            n = Fibonacci(i);
            printf("%d ", n);
            i++;
        }
    else if (command == PROG_2)
        while(1)
    {
        cycle(i)
        {
            cycle(j)
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
