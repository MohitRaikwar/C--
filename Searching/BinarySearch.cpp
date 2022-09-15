#include <iostream>
using namespace std;

// functions prototype
void input_array(int arr[], int n);
int binary_search_itr(int arr[], int l, int h, int num);
int binary_search_recr(int arr[], int l, int h, int num);

int main()
{
    int size{0};
    int choice{0};
    int num{0};
    int index{0};
    cout << "Enter size of array :";
    cin >> size;
    int arr[size];
    input_array(arr,size);
    while (true)
    {
        cout << "\nEnter number to search :";
        cin >> num;
        cout << "\nSelect from the following options :\n";
        cout << "\n1.Binary Search Iterative\n";
        cout << "2.Binary Search Recurrsive\n";
        cout << "3.Exit\n";
        cout<<"\nEnter your choice :";
        cin >> choice;
        switch (choice)
        {
        case 1:
            index=binary_search_itr(arr, 0, size-1, num);
            if(index==-1)
                cout<<num<<" not found\n";
            else
                cout<<num<<" found at index "<<index<<"\n";
            break;
        case 2:
            index=binary_search_recr(arr, 0, size-1, num);
            if(index==-1)
                cout<<num<<" not found\n";
            else
                cout<<num<<" found at index "<<index<<"\n"; 
            break;
        case 3:exit(0);
            break;
        default:
            cout << "Invalid selection";
            break;
        }
    }

    return 0;
}

void input_array(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << " element :";
        cin >> arr[i];
    }
}

int binary_search_itr(int arr[], int l, int h, int num)
{
    int mid;
    while (l <= h)
    {
        mid = l + (h - l) / 2;
        if (arr[mid] == num)
            return mid;
        if(arr[mid]<num)
            l=mid+1;
        else
            h=mid-1;
    }
    return -1;
}

int binary_search_recr(int arr[],int l,int h,int num)
{
    if(l<=h)
    {
        int mid=l+(h-l)/2;
        if(arr[mid]==num)
            return mid;
        else if(arr[mid]>num)
            return binary_search_recr(arr,l,mid-1,num);
        else
            return binary_search_recr(arr,mid+1,h,num);
    }

    return -1;
}
