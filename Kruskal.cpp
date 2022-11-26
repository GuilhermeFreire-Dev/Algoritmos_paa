#include <iostream>
#include <algorithm>
#include <ctime>

using namespace std;

struct t_aresta{
    int dis;
    int x, y;
};

bool comp(t_aresta a, t_aresta b){ return a.dis < b.dis; }

//--------------------
#define MAXN 50500
#define MAXM 200200

int n, m; // número de vértices e arestas
t_aresta aresta[MAXM];

// para o union find
int pai[MAXN];
int peso[MAXN];

// a árvore
t_aresta mst[MAXM];
//--------------------

// funções do union find
int find(int x){
    if(pai[x] == x) return x;
    return pai[x] = find(pai[x]);
}

void join(int a, int b){
    
    a = find(a);
    b = find(b);
    
    if(peso[a] < peso[b]) pai[a] = b;
    else if(peso[b] < peso[a]) pai[b] = a;
    else{
        pai[a] = b;
        peso[b]++;
    }
    
}

int main(){
    
    time_t instante;
    double tempoTotal = 0;
    int count = 0;

    // ler a entrada
    cin >> n >> m;
    
    for(int i = 1;i <= m;i++)
        cin >> aresta[i].x >> aresta[i].y >> aresta[i].dis;
    
    do
    {
        instante = clock();
        // inicializar os pais para o union-find
        for(int i = 1;i <= n;i++) pai[i] = i;
        
        // ordenar as arestas
        sort(aresta+1, aresta+m+1, comp);
        
        int size = 0;
        for(int i = 1;i <= m;i++){
            
            if( find(aresta[i].x) != find(aresta[i].y) ){ // se estiverem em componentes distintas
                join(aresta[i].x, aresta[i].y);
                
                mst[++size] = aresta[i];
            }
            
        }
        instante = clock() - instante;
        count++;
        tempoTotal += (double)(instante / (CLOCKS_PER_SEC/1000));
        tempoTotal /= count;

    } while (tempoTotal <= 0);
    
    // imprimir a MST
    cout << endl;
    
    for(int i = 1;i < n;i++) cout << mst[i].x << " " << mst[i].y << " " << mst[i].dis << "\n";

    printf("Algoritmo de Kruskal.\nTempo decorrido: %fms.\n", tempoTotal);
    
    return 0;
}

/*
Grafo de exemplo
6 15
0 1 3469
0 2 5558
0 3 5959
0 4 214
0 5 5074
1 2 2090
1 3 6757
1 4 3636
1 5 6844
2 3 7035
2 4 5725
2 5 7753
3 4 6053
3 5 1307
4 5 5120
*/