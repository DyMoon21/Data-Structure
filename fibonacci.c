#include <stdio.h>

int fibonacci(int n)
{
    int last1 = 1;
    int last2 = 1;
    int result = 0;
    for (int i = 3; i <= n; i++)
    {
        result = last1 + last2;
        last2 = last1;
        last1 = result;
    }
    return result;
}

int fibonacci_recursive(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }
    else
    {
        return fibonacci_recursive(n - 1) + fibonacci_recursive(n - 2);
    }
}

int main()
{
    printf("%d\n", fibonacci(6));
    printf("%d\n", fibonacci_recursive(6));
    return 0;
}