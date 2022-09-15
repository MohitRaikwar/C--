#include <iostream>
using namespace std;

// functions prototype
void print_array(int arr[],int n);
void input_array(int arr[], int n);
void merge(int arr[], int left, int mid, int right);
void mergeSort(int arr[],int left,int right);

int main()
{
    int size{0};
    cout << "Enter size of array :";
    cin >> size;
    int arr[size];
    input_array(arr, size);
    cout<<"\nBefore sorting : ";
    print_array(arr,size);
    mergeSort(arr,0,size-1);
    cout<<"\nAfter sorting :";
    print_array(arr,size);
    return 0;
}

void print_array(int arr[],int n)
{
    for(int i=0;i<n;i++)
        cout<<arr[i]<<" ";
    cout<<"\n";
}

void input_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " element :";
        cin >> arr[i];
    }
}

void merge(int arr[], int left, int mid, int right)
{
    // size of subarrays
    int size_subarray_one = mid - left + 1;
    int size_subarray_two = right - mid;

    // subarrays to store elements
    int leftArray[size_subarray_one];
    int rightArray[size_subarray_two];

    // copy array items to subarrays
    for (int i = 0; i < size_subarray_one; i++)
        leftArray[i] = arr[left + i];
    for (int j = 0; j < size_subarray_two; j++)
        rightArray[j] = arr[mid + 1 + j];

    // to keep track of original indexes
    int indexOfSubarrayOne{0};
    int indexOfSubarrayTwo{0};
    int indexOfMergedArray{left};

    //comparing elements of both subarray
    while (indexOfSubarrayOne < size_subarray_one && indexOfSubarrayTwo < size_subarray_two)
    {
        if(leftArray[indexOfSubarrayOne]<=rightArray[indexOfSubarrayTwo])
        {
            arr[indexOfMergedArray] = leftArray[indexOfSubarrayOne];
            indexOfSubarrayOne++;
        }
        else
        {
            arr[indexOfMergedArray]=rightArray[indexOfSubarrayTwo];
            indexOfSubarrayTwo++;
        }
        indexOfMergedArray++;

    }

    //copy remaining items of subarrayone
    while(indexOfSubarrayOne<size_subarray_one)
    {
        arr[indexOfMergedArray]=leftArray[indexOfSubarrayOne];
        indexOfMergedArray++;
        indexOfSubarrayOne++;

    }

    //copy remaining items of subarraytwo
    while(indexOfSubarrayTwo<size_subarray_two)
    {
        arr[indexOfMergedArray]=rightArray[indexOfSubarrayTwo];
        indexOfMergedArray++;
        indexOfSubarrayTwo++;

    }
}

void mergeSort(int arr[],int left,int right)
{
    if(left>=right)
        return;
    else
    {   
        int mid=left+(right-left)/2;
        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);
        merge(arr,left,mid,right);

    }
}