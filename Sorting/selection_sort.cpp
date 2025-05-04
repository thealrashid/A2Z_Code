#include <iostream>

using namespace std;

void selection_sort_recur(int arr[], int l, int r)
{
    if(l == r) return;

    int min_pos = l;
    for(int i=l+1;i<=r;i++)
    {
        if(arr[i] < arr[l]) min_pos = i;
    }
    swap(arr[min_pos], arr[l]);
    selection_sort_recur(arr, l+1, r);
}

void selection_sort(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        int min_pos = i;
        for(int j=i;j<n;j++)
        {
            if(arr[j] < arr[i]) min_pos = j;
        }
        swap(arr[i], arr[min_pos]);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter the elements of the array:" << endl;
    for(int i=0;i<n;i++) cin >> arr[i];

    //selection_sort_recur(arr, 0, n-1);
    selection_sort(arr, n);

    cout << "Sorted array:" << endl;
    for(int i=0;i<n;i++) cout << arr[i] << " ";

    return 0;
}