/*
    Algoritmo para gerar a sequência de fibonacci usando o projeto de algoritmo dinâmico
*/

#include <iostream>
#include <vector>
#include <time.h>

using namespace std;

class Fibonacci
{
private:
    vector<long long> valEncontrados;

public:

    Fibonacci()
    {
        valEncontrados.push_back(0);
        valEncontrados.push_back(1);
    }

    void preencher(int n)
    {
        long long novoValor;
        long long index = valEncontrados.size();

        // Preenche a lista com os termos da sequencia de Fibonacci até o termo solicitado
        while (valEncontrados.size() <= n)
        {
            novoValor = valEncontrados.at(index - 2) + valEncontrados.at(index - 1);
            valEncontrados.push_back(novoValor);
            index++;
        }
    }

    long long getFibonacci(int n)
    {
        // Verifica se o termo requisitado já está na lista
        if (n < valEncontrados.size())
        {
            return valEncontrados.at(n);
        }
        else
        {
            // Preenche a lista com todos os valores até o termo requisitado
            preencher(n);
            return valEncontrados.at(n);
        } 
    }
};

double tempoDecorrido(time_t tempo)
{
    return (double)(tempo/(CLOCKS_PER_SEC/1000));
}

void runFibonacci(int n)
{
    Fibonacci fibonacci;
    time_t tempo;
    double tempoTotal = 0;
    long long fib;
    int count = 0;

    do
    {
        tempo = clock();
        fib = fibonacci.getFibonacci(n);
        tempo = clock() - tempo;
        count++;
        tempoTotal += tempoDecorrido(tempo) / count;

    } while (tempoTotal <= 0);

    printf("Fibonacci(%d): %lld\n", n, fib);
    printf("Tempo decorrido: %fms.", tempoTotal);
}

int main() 
{
    runFibonacci(92);

    return EXIT_SUCCESS;
}