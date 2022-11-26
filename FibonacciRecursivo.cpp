/*
    Algoritmo para gerar a sequência de fibonacci de forma recursiva
*/

#include <iostream>
#include <time.h>

double tempoDecorrido(time_t tempo)
{
    return (double)(tempo/(CLOCKS_PER_SEC/1000));
}

long long fibonacci(int n)
{
    if (n < 2)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

void runFibonacci(int n)
{
    time_t tempo;
    double tempoTotal = 0;
    long long fib;
    int count = 0;

    do
    {
        tempo = clock();
        fib = fibonacci(n);
        tempo = clock() - tempo;
        count++;
        tempoTotal += tempoDecorrido(tempo) / count;

    } while (tempoTotal <= 0);

    printf("Fibonacci(%d): %lld\n", n, fib);
    printf("Tempo decorrido: %fms.", tempoTotal);
}

int main()
{
    runFibonacci(100);

    return EXIT_SUCCESS;
}