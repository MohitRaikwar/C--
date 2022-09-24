#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> iPair;
const int V = 5;
void heapify(vector<iPair> &hT, int i);
void print_heap(vector<iPair> &ht);

int heap_extract_min(vector<iPair> &hT);
bool heap_decrease_key(vector<iPair> &hT, int i, int key);

bool comparator(iPair &a, iPair &b);

void print_MST(int adj[V][V], int V);

int main()
{
    int adj[V][V] = {
        {INT_MAX, 3, 6, 3, INT_MAX},
        {3, INT_MAX, INT_MAX, 1, 4},
        {6, INT_MAX, INT_MAX, 2, INT_MAX},
        {INT_MAX, 1, 2, INT_MAX, 2},
        {INT_MAX, 4, INT_MAX, 2, INT_MAX}};
    // get adjacency matrix
    // set key value to infinte and parent null for each vertices
    print_MST(adj, V);
    return 0;
}

void print_MST(int adj[V][V], int V)
{
    vector<iPair> priorityQueue;
    vector<int> key(V, INT_MAX);
    vector<int> parent(V, -1);
    vector<bool> inMST(V, false);

    for (int i = 0; i < V; i++)
        priorityQueue.push_back(make_pair(INT_MAX, i));

    // set root key value to 0
    int src{0};
    priorityQueue[src].first = 0;
    make_heap(priorityQueue.begin(), priorityQueue.end(), comparator);
    key[src] = 0;

    // loop for while Q not equal to 0
    while (!priorityQueue.empty())
    {
        // EXTRACT_MIN
        int u = heap_extract_min(priorityQueue);
        if (inMST[u])
            continue;
        else
        {
            // loop over adjacent elements and check if weight b/w them is less than
            // then set parent of v to i
            // set its key
            inMST[u] = true;
            for (int i = 0; i < V; i++)
            {
                cout<<"\nFor vertex "<<u<<" , "<<i<<"\n";

                if (adj[u][i] != INT_MAX)
                {
                    int weight = adj[u][i];
                    int j;
                    for (j = 0; j < V; j++)
                        if (priorityQueue[j].second == i)
                            break;
                    if (!inMST[i] && weight < priorityQueue[j].first)
                    {
                        cout << "\nBefore heap decrease :\n";
                        print_heap(priorityQueue);
                        key[i] = weight;
                        parent[i] = u;

                        heap_decrease_key(priorityQueue, j, weight);
                        cout << "\nAfter heap decrease :\n";
                        print_heap(priorityQueue);
                    }
                }
            }
        }
    }
    for (int i = 0; i < V; i++)
        cout << parent[i] << " - " << i << "\n";
}

// Min Heap Implementation

void print_heap(vector<iPair> &ht)
{
    for (auto i : ht)
    {
        cout << "\nKey :" << i.first;
        cout << "\nIndex :" << i.second;
    }
    cout << '\n';
}

void heapify(vector<iPair> &hT, int i)
{
    int heapSize = hT.size();
    int leftChild = 2 * i + 1;
    int rightChild = 2 * i + 2;
    int min = i;
    if (leftChild < heapSize && hT[leftChild].first < hT[min].first)
        min = leftChild;
    if (rightChild < heapSize && hT[rightChild].first < hT[min].first)
        min = rightChild;
    if (min != i)
    {
        // swap(&hT[i], &hT[min]);
        heapify(hT, min);
    }
}

// priority queue min heap

int heap_extract_min(vector<iPair> &hT)
{
    int heapSize = hT.size();
    iPair min = hT[0];
    hT[0].swap(hT[heapSize - 1]);
    hT.pop_back();
    heapify(hT, 0);
    return min.second;
}

bool heap_decrease_key(vector<iPair> &hT, int i, int key)
{
    if (hT[i].first < key)
        return false;
    else
    {
        hT[i].first = key;
        while (i > 0 && hT[i / 2].first > hT[i].first)
            hT[i / 2].swap(hT[i]);
        return true;
    }
}

bool comparator(iPair &a, iPair &b)
{
    return a.first > b.first;
}