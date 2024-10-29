#include <stdio.h>

 int Fibonacci(int n)
 {
     if(n == 0) return 0;
     else if(n == 1) return 1;
     else return (Fibonacci(n - 1) + Fibonacci(n - 2));
 }

int main()
{
    int n = 0, i = 0;
    while ( n != 2584)
    {
        n = Fibonacci(i);
        printf("%d ", n);
        i++;
    }
    return 0;
}
