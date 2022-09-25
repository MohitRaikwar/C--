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
    // weighted adjacency matrix
    int adj[V][V] = {
        {INT_MAX, 3, 6, 3, INT_MAX},
        {3, INT_MAX, INT_MAX, 1, 4},
        {6, INT_MAX, INT_MAX, 2, INT_MAX},
        {INT_MAX, 1, 2, INT_MAX, 2},
        {INT_MAX, 4, INT_MAX, 2, INT_MAX}};
    print_MST(adj, V);
    return 0;
}

void print_MST(int adj[V][V], int V)
{
    vector<iPair> priorityQueue;

    // set key value to infinte
    vector<int> key(V, INT_MAX);

    // set parent value to -1
    vector<int> parent(V, -1);

    // to keep track of traversed vertices
    vector<bool> inMST(V, false);

    // fill up priority queue vector <key, index to the vertex in orginal >
    for (int i = 0; i < V; i++)
        priorityQueue.push_back(make_pair(INT_MAX, i));

    // set root key value to 0
    int src{0};
    priorityQueue[src].first = 0;

    // make min heap
    make_heap(priorityQueue.begin(), priorityQueue.end(), comparator);
    key[src] = 0;

    // loop for while Q not equal to 0
    while (!priorityQueue.empty()) // O(V)
    {
        // EXTRACT_MIN
        int u = heap_extract_min(priorityQueue);
        if (inMST[u])
            continue;
        else
        {
            inMST[u] = true;
            // loop over adjacent elements
            for (int i = 0; i < V; i++) // O(V)
            {
                if (adj[u][i] != INT_MAX)
                {
                    int weight = adj[u][i];

                    // to get index in priorityQueue(for comaprison in key value with weighted adjaceny matrix weight)
                    int j;
                    for (j = 0; j < V; j++) // O(V)
                        if (priorityQueue[j].second == i)
                            break;
                    if (!inMST[i] && weight < priorityQueue[j].first)
                    {
                        // set its key
                        key[i] = weight;

                        // then set parent of i to u
                        parent[i] = u;

                        heap_decrease_key(priorityQueue, j, weight); // O(lgV)
                    }
                }
            }
        }
    }
    for (int i = 1; i < V; i++)
        cout << "Edge " << parent[i] << " - " << i << " Weight : " << key[i] << "\n";
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
        hT[i].swap(hT[min]);
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