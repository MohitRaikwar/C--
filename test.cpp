#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;
int diagonalDifference(vector<vector<int>> arr)
{
    int sumPrimaryDiagonal{0};
    int sumSecondaryDiagonal{0};
    int diagonalDifference{0};
    int arr_size = arr.size();
    for (int i = 0; i < arr_size; i++)
    {
        sumPrimaryDiagonal += arr[i][i];
        cout<<"Second Diagonal :"<<arr[i][arr_size - i - 1];
        sumSecondaryDiagonal += arr[i][arr_size - i - 1];
    }
    cout<<"Psum:"<<sumPrimaryDiagonal<<" SecoSum :"<<sumSecondaryDiagonal;
    diagonalDifference = sumPrimaryDiagonal - sumSecondaryDiagonal;
    return diagonalDifference;
}

int main()
{
    vector<vector<int>> n{
        {11, 2, 4},
        {4, 5, 6},
        {10, 8, -12}};
   diagonalDifference(n);
    return 0;
}
