#include <iostream>
#include <limits.h>
#include<map>

using namespace std;

int MatrixChainOrder(int p[], int n);
void showOptimalSol(int n);
int sol[10][10];

int main()
{
    int n, i;
    cout << "Enter number of matrices\n";
    cin >> n;

    n++;

    int arr[n];

    cout << "Enter dimensions \n";

    for (i = 0; i < n; i++)
    {
        cout << "Enter d" << i << " :: ";
        cin >> arr[i];
    }

    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Minimum number of multiplications is " << MatrixChainOrder(arr, size) << endl;
    // for (i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //         cout << "s[" << i << "]"
    //              << "[" << j<<"] :: "<<sol[i][j]<<"\n";
    // }

    return 0;
}

int MatrixChainOrder(int p[], int n)
{
    int m[n][n];
    int i, j, k, L, q;
    for (i = 0; i < n; i++)
        m[i][i] = 0;        // no. of mulitiplications are zero when there is only on matrix
    for (L = 2; L < n; L++) // L is chain lnegth
    {
        for (i = 1; i < n - L + 1; i++)
        {
            j = i + L - 1;
            m[i][j] = INT_MAX;
            for (k = i; k <= j - 1; k++)
            {
                q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    sol[i][j] = k;
                }
            }
        }
    }
    return m[1][n - 1];
}

// void showOptimalSol(int n)
// {
//     map<int,int> marix;
//     for (int i = 0; i < n; i++)
//     {
//         for (int j = 0; j < n; j++)
//         (so)
//     }
// }