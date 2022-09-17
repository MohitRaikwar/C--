#include<iostream>
#include <chrono>
#include <stdlib.h>
using namespace std;

// functions prototype
void print_array(int arr[], int n);
void generate_array(int arr[], int n);
void swap(int *a, int *b);
void quickSort(int arr[], int low, int high); 
int partition(int arr[], int low, int high);

int main()
{
    int size{0};
    cout << "Enter size of array :";
    cin >> size;
    int arr[size];
    cout << "\nBefore sorting : ";
    print_array(arr, size);
    auto start = std::chrono::high_resolution_clock::now();
    quickSort(arr, 0, size - 1);
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration =std::chrono::duration_cast<std::chrono::milliseconds>(stop - start);
    cout << "\nAfter sorting :";
    print_array(arr, size);
    cout << "Time taken by Quick Sort function: " << duration.count() << " milliseconds\n";   
    return 0;
}

void print_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << "arr[" << i << "] : " << arr[i] << "\n";
    cout << "\n";
}

void generate_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = rand();
}

void swap(int *x, int *y) {
  int t = *x;
  *x = *y;
  *y = t;
}
void quickSort(int arr[], int low, int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int partition(int arr[], int low, int high)
{
    //select rightmost element as pivot
    int pivot=arr[high];
    int i=low-1;
    for(int j=low;j<high;j++)
    {
        if(arr[j]<=pivot)
        {
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[high]);

    //return the partitioning point
    return (i+1);
}