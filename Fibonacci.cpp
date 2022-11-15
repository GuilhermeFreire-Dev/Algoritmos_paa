/*
    Algoritmo para gerar a sequência de fibonacci
*/

#include <iostream>

long long fibonacci(int n)
{
    if (n < 2)
    {
        return n;
    }
    else
    {
        long long a = 0;
        long long b = 1;
        long long sum = 1;
        for (int i = 2; i <= n; i++)
        {
            sum = a + b;
            a = b;
            b = sum;
        }
        return sum;
    }
}


int main()
{
    //Max 92
    std::cout << fibonacci(1) << std::endl;
}