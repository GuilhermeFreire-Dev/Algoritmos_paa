/*
    Algoritmo para gerar a sequência de fibonacci de forma recursiva
*/

#include <iostream>

long long fibonacci(int n)
{
    if (n < 2)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void runFibonacci(int n)
{
    printf("Fibonacci(%d): %lld\n", n, fibonacci(n));
}

int main()
{
    runFibonacci(10);

    return EXIT_SUCCESS;
}