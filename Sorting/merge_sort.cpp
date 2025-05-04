#include <iostream>

using namespace std;

void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1], arr2[n2];

    for(int i = 0; i < n1; i++) arr1[i] = arr[left + i];
    for(int i = 0; i < n2; i++) arr2[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2)
    {
        if(arr1[i] <= arr2[j]) arr[k++] = arr1[i++];
        else arr[k++] = arr2[j++];
    }
    while(i < n1) arr[k++] = arr1[i++];
    while(j < n2) arr[k++] = arr2[j++];
}

void merge_sort(int arr[], int left, int right)
{
    if(left < right)
    {
        int mid = (left + right) / 2;
        
        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    merge_sort(arr, 0, n-1);
    cout << "Sorted array is" << endl;
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}