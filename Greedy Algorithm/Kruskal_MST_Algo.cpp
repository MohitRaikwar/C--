#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef pair<int, int> edge;

class Graph
{
private:
    // Graph
    vector<pair<int, edge>> G;
    // MST
    vector<pair<int, edge>> MST;
    // No. of vertices in graph
    int V;
    int *parent;

public:
    Graph(int V);
    ~Graph();
    void add_weighted_edge(int u, int v, int w);
    int find_set(int i);
    void union_set(int u, int v);
    void kruskal();
    void print();
    void print_normal();
};

Graph::Graph(int V)
{
    this->V = V;
    this->parent = new int[V];

    // set parent of vertices to self
    for (int i = 0; i < V; i++)
    {
        parent[i] = i;
    }
}
void Graph::add_weighted_edge(int u, int v, int w)
{
    G.push_back(make_pair(w, edge(u, v)));
}

int Graph::find_set(int i)
{
    if (i == parent[i])
        return i;
    return find_set(parent[i]);
}

void Graph::union_set(int u, int v)
{
    parent[u] = parent[v];
}

void Graph::kruskal()
{
    int i, u, v;
    sort(G.begin(), G.end());
    for (i = 0; i < G.size(); i++)
    {
        u = find_set(G[i].second.first);
        v = find_set(G[i].second.second);
        if (u != v)
        {
            union_set(u, v);
            MST.push_back(G[i]);
        }
    }
}

void Graph::print()
{
    for (int i = 0; i < MST.size(); i++)
    {
        cout << "Edge : " << MST[i].second.first << "-" << MST[i].second.second << "\n";
        cout << "Weight : " << MST[i].first << "\n\n";
    }
}


Graph::~Graph()
{
}

int main()
{
    Graph G(5);
    G.add_weighted_edge(0, 1, 3);
    G.add_weighted_edge(0, 2, 6);
    G.add_weighted_edge(0, 3, 3);

    G.add_weighted_edge(1, 0, 3);
    G.add_weighted_edge(1, 3, 1);
    G.add_weighted_edge(1, 4, 4);

    G.add_weighted_edge(2, 0, 6);
    G.add_weighted_edge(2, 3, 2);

    G.add_weighted_edge(3, 0, 3);
    G.add_weighted_edge(3, 4, 2);
    G.add_weighted_edge(3, 2, 4);
    G.add_weighted_edge(3, 1, 1);

    G.add_weighted_edge(4, 1, 4);
    G.add_weighted_edge(4, 3, 2);
    G.kruskal();
    G.print();
    //G.print_normal();
    return 0;
}
