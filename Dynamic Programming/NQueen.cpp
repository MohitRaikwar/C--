#include <iostream>
using namespace std;

bool isSafe(int **arr, int row, int col, int n);
bool nQueen(int **arr, int row, int n);
void printArr(int **arr,int n);

int main()
{
    int n;
    do
    {
        cout << "Enter no. of queens :: ";
        cin >> n;
    } while (n < 0);

    int **arr = new int *[n];
    for(int i=0;i<n;i++)
    {
        arr[i]=new int[n];
        for(int j=0;j<n;j++)
            arr[i][j]=0;
    }
    if(nQueen(arr,0,n))
        printArr(arr,n);
    else
        cout<<"Queens can't be placed\n";
    delete[] arr;
    return 0;
}

bool isSafe(int **arr, int row, int col, int n)
{
    int i, j;
    // check columns
    for (i = 0; i < row; i++)
        if (arr[i][col])
            return false;

    // check upper left digonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (arr[i][j])
            return false;

    // check upper right diagonal
    for (i = row, j = col; i >= 0 && j < n; i--, j++)
        if (arr[i][j])
            return false;

    return true;
}

bool nQueen(int **arr, int x, int n)
{
    if (x >= n)
        return true;
    else
    {
        for (int col = 0; col < n; col++)
        {
            if (isSafe(arr, x, col, n))
            {
                arr[x][col] = 1;
                if (nQueen(arr, x + 1, n))
                    return true;
                arr[x][col] = 0; // backtrack
            }
        }
        return false;
    }
}

void printArr(int **arr,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
            cout<<arr[i][j]<<" ";
        cout<<"\n";
    }
        
}