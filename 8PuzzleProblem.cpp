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
};

// function prototypes

void printMatrix(int mat[N][N]);
int isSafe(int x, int y);
Node *newNode(int mat[N][N], int x, int y, int newX, int newY, Node *parent);
bool compareMatrix(int initial[N][N], int final[N][N]);
void printPath(Node *root);
bool checkIfParentExist(Node *node);
void bfs(int initial[N][N], int x, int y, int final[N][N]);
void dfs(Node *parent, int final[N][N]);

// Main function
int main()
{
    // Initial configuration
    // Value 0 is used for empty space
    int initial[N][N] =
        {
            {1, 2, 3},
            {5, 6, 0},
            {7, 8, 4}};

    // Solvable Final configuration
    // Value 0 is used for empty space
    int final[N][N] =
        {
            {1, 2, 3},
            {5, 8, 6},
            {0, 7, 4}};

    // Blank tile coordinates in initial
    // configuration
    int x = 1, y = 2;
    if (compareMatrix(initial, final))
    {
        cout << "Initial matrix is the final matrix";
        return 0;
    }

    int choice;
    cout << "Solve 8-Puzzle Problem by \n";
    cout << "1.Using BFS\n";
    cout << "2.Using DFS\n";
    cout << "Enter your choice :";
    cin >> choice;
    if (choice == 1)
        bfs(initial, x, y, final);
    else if (choice == 2)
    {
        Node *root = newNode(initial, x, y, x, y, NULL);
        dfs(root, final);
    }
    else
        cout << "\nWrong choice\n";

    return 0;
}

// stores parent matrices
vector<Node *> v;

// function to print the matrix
void printMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << mat[i][j] << " ";
        cout << "\n";
    }
}

// function to allocate new node
Node *newNode(int mat[N][N], int x, int y, int newX, int newY, Node *parent)
{
    Node *node = new Node;
    node->parent = parent;

    // copy matrix
    memcpy(node->mat, mat, sizeof node->mat);

    // move tile by one position
    swap(node->mat[x][y], node->mat[newX][newY]);
    node->x = newX;
    node->y = newY;
    return node;
}

// left,bottom,top,left
int row[] = {0, 1, -1, 0};
int col[] = {-1, 0, 0, 1};

// Function to check whether (x,y) is a valid matrix coordinate
int isSafe(int x, int y)
{
    return (x >= 0 && x < N && y >= 0 && y < N);
}

// Function to check if two matrices are equivalent
bool compareMatrix(int initial[N][N], int final[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            if (initial[i][j] != final[i][j])
                return false;
    }
    return true;
}

// Function to print path from goal state to parent state
void printPath(Node *root)
{
    if (root->parent == NULL)
    {
        printMatrix(root->mat);
        cout << endl;
        return;
    }
    printPath(root->parent);
    printMatrix(root->mat);
    cout << endl;
}

bool checkIfParentExist(Node *node)
{
    for (int i = 0; i < v.size(); i++)
    {
        if (compareMatrix(node->mat, v[i]->mat))
            return true;
    }
    return false;
}

// DFS solution to 8-Puzzle Problem
void dfs(Node *parent, int final[N][N])
{
    for (int i = 0; i < 4; i++)
    {
        if (isSafe(parent->x + row[i], parent->y + col[i]))
        {
            Node *child = newNode(parent->mat, parent->x, parent->y, parent->x + row[i], parent->y + col[i], parent);
            if (compareMatrix(child->mat, final))
            {
                cout << "Path found";
                printPath(child);
                return;
            }
            else if (!checkIfParentExist(child))
            {
                if (i == 0)
                    cout << "Left Movement\n";
                else if (i == 1)
                    cout << "Bottom Movement\n";
                else if (i == 2)
                    cout << "Top Movement\n";
                else
                    cout << "Right Movement\n";
                v.push_back(child);
                dfs(child, final);
            }
        }
    }
}

// BFS solution to the 8-Puzzle Problem
void bfs(int initial[N][N], int x, int y, int final[N][N])
{
    // queue to store child nodes
    queue<Node *> q;
    Node *root = newNode(initial, x, y, x, y, NULL);

    // pushing the initial board configuration
    q.push(root);
    while (!q.empty())
    {
        // getting the front element of the queue
        Node *node = q.front();

        // popping out the first element
        q.pop();

        // this loop generates child nodes and pushes them back into queue
        for (int i = 0; i < 4; i++)
        {
            if (isSafe(node->x + row[i], node->y + col[i]))
            {
                Node *child = newNode(node->mat, node->x, node->y, node->x + row[i], node->y + col[i], node);
                if (compareMatrix(child->mat, final))
                {
                    cout << "Path found\n";
                    printPath(child);
                    return;
                }
                q.push(child);
            }
        }
    }
    cout << "Can't reach goal state \n";
    return;
}
