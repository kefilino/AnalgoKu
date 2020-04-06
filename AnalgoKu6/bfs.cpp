/*
 * Nama     : Kefilino Khalifa Filardi
 * NPM      : 140810180028
 * Kelas    : B
 * Program  : Program Breadth First Search
 * Tanggal  : 6 April 2020
 * Desc     : Program ini mengimplemen Breadth First Search menggunakan algoritma yang diberikan.
 */

#include <iostream>
#include <list>
using namespace std;

struct Graph {
    int vertex;
    list<int>* edge;
};

void makeGraph(Graph& G, int vertex)
{
    G.vertex = vertex;
    G.edge = new list<int>[vertex];
}

void addEdge(Graph& G, int i, int j)
{
    G.edge[i].push_back(j);
}

void traversal(Graph G)
{
    for (int i = 0; i < G.vertex; ++i)
    {
        cout << "\n vertex "<<i<<"\n head";
        for (auto x : G.edge[i])
            cout << " -> " << x;
        cout << endl;
    }
}

void BFS(Graph G, int s)
{
    bool *visited = new bool[G.vertex];
    for (int i=0; i<G.vertex; i++)
        visited[i] = false;
    
    list<int> queue;
    visited[s] = true;
    queue.push_back(s);

    while (!queue.empty()) {
        s = queue.front();
        cout<<s<<" ";
        queue.pop_front();

        for (list<int>::iterator i=G.edge[s].begin(); i != G.edge[s].end(); ++i) {
            if (!visited[*i]) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
    }
}

int main()
{
    Graph G;
    int n, m, val, edge;

    cout << "Banyak simpul dalam graph : ";
    cin >> n;
    makeGraph(G, n);
    
    for (int i = 0; i < n; i++) {
        cout << endl << "Nilai simpul ke-" << i+1 << " : ";
        cin >> val;
        cout << "Banyak edge dari simpul " << val << " : ";
        cin >> m;

        for (int j = 0; j < m; j++) {
            cout << "Simpul edge ke-" << j+1 << " : ";
            cin >> edge;
            addEdge(G, val, edge);
        }
        
    }

    cout << "\nBFS dimulai dari simpul "
         << *G.edge[0].begin() - 1 << endl;
    BFS(G, *G.edge[0].begin() - 1);
}