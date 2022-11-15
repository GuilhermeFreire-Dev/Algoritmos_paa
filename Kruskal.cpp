/*
    Algoritmo de Kruskal para obter o caminho mínimo em um grafo conexo
*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;
 
// Estrutura de dados para armazenar uma aresta do grafo
struct Edge {
    int src, dest, weight;
};
 
// Objeto de comparação a ser usado para ordenar as arestas
struct compare
{
    bool operator() (Edge const &a, Edge const &b) const {
        return a.weight > b.weight;
    }
};
 
// Classe para representar um conjunto disjunto
class DisjointSet
{
    unordered_map<int, int> parent;
 
public:

    void makeSet(int n)
    {
        // Cria n conjuntos disjuntos (um para cada vértice)
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }
 
    // Encontra a raiz do conjunto ao qual pertence o elemento k
    int Find(int k)
    {
        // Se k for root
        if (parent[k] == k) {
            return k;
        }
 
        //Recorre para o pai até encontrarmos a raiz
        return Find(parent[k]);
    }
 
    // Realiza união de dois subconjuntos
    void Union(int a, int b)
    {
        // Encontra a raiz dos conjuntos em que os elementos
        // x e y pertencem
        int x = Find(a);
        int y = Find(b);
 
        parent[x] = y;
    }
};
 
// Função para construir MST usando o algoritmo de Kruskal
vector<Edge> runKruskalAlgorithm(vector<Edge> edges, int n)
{
    // Armazena as arestas presentes no MST
    vector<Edge> MST;

    DisjointSet ds;
 
    // Cria um conjunto singleton para cada elemento do universo
    ds.makeSet(n);
 
    // classifica as arestas aumentando o peso
    sort(edges.begin(), edges.end(), compare());
 
    // MST contém exatamente arestas V-1
    while (MST.size() != n - 1)
    {
        // Considera a próxima aresta com peso mínimo do gráfico
        Edge next_edge = edges.back();
        edges.pop_back();
 
        int x = ds.Find(next_edge.src);
        int y = ds.Find(next_edge.dest);
 
        if (x != y)
        {
            MST.push_back(next_edge);
            ds.Union(x, y);
        }
    }
    return MST;
}
 
int main()
{
    vector<Edge> edges =
    {
        // (u, v, w), (u, v) aresta, (w) peso
        {0, 1, 5558}, {0, 2, 3469}, {0, 3, 214}, {0, 4, 5074}, {0, 5, 5959}, {1, 0, 5588},
        {1, 2, 2090}, {1, 3, 5725}, {1, 4, 7753}, {1, 5, 7035}, {2, 3, 3636}, {2, 4, 6844}, 
        {2, 5, 6757}, {3, 4, 5120}, {3, 5, 6053}, {4, 5, 1307}
    };
 
    // número total de nós no grafo
    int n = 6;
 
    // constrói o grafo
    vector<Edge> e = runKruskalAlgorithm(edges, n);
 
    for (Edge &edge: e)
    {
        cout << "(" << edge.src << ", " << edge.dest << ", "
             << edge.weight << ")" << endl;
    }
    return 0;
}