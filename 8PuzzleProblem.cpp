#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
#define N 3

struct Node
{
    // stores the parent node of current node
    Node *parent;

    // stores matrix
    int mat[N][N];

    // stores blank tile coordinates
    int x, y;

    // checks if node is visited
    bool visited = false;
};

// function to print the matrix
int printMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[N][N] << " ";
        cout << "\n";
    }
}

// function to allocate new node
Node *newNode(int mat[N][N], int x, int y, int newX, int newY, Node *parent)
{
    Node *node = new Node;
    node->parent = parent;

    // copy data from parent node to current node
    memcpy(node->mat, mat, sizeof node->mat);

    // move tile by one position
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->x = newX;
    node->y = newY;
    return node;
}
// right,bottom,top,left
int row[] = {0, 1, -1, 0};
int col[] = {1, 0, 0, -1};

// Function to check whether (x,y) is a valid matrix coordinate
int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

queue<Node *> matrixQueue;

bool compareMatrix(int initial[N][N], int final[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (initial[i][j] != final[i][j])
                return false;
        return true;
    }
}

void printPath(Node *root)
{
    if (root->parent == NULL)
        return;
    printPath(root->parent);
    printMatrix(root->mat);
}

void solve(int initial[N][N], int x, int y, int final[N][N])
{
    Node *root = newNode(initial, x, y, x, y, NULL);
    matrixQueue.push(root);
    if (root->visited)
        printPath(root);
    else
        dfs(root, final);
}

void dfs(Node *parent, int final[N][N])
{
    parent->visited = true;
    for (int i = 0; i < 4; i++)
    {
        if (isSafe(parent->x + row[i], parent->y + col[i]))
        {
            Node *child = newNode(parent->mat, parent->x, parent->y, parent->x + row[i], parent->y + col[i], parent);
            matrixQueue.push(child);
            if (compareMatrix(child->mat, final))
                printPath(child);
            else
                dfs(child, final);
        }
    }
}

int main()
{
    return 0;
}