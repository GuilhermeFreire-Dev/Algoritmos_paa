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

int main()
{
    std::cout << fibonacci(1) << std::endl;
}