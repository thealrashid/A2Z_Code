#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int partition(vector<int>& arr, int left, int right)
{
    srand(time(0));
    int index = left + rand()%(right - left + 1);
    swap(arr[index], arr[right]);
    int pivot = arr[right];
    int i = left - 1;

    for(int j = left; j < right; j++)
    {
        if(arr[j] < pivot) swap(arr[++i], arr[j]);
    }
    swap(arr[++i], arr[right]);
    return i;
}

int kth_largest(vector<int>& arr, int left, int right, int k)
{
    if (left < right)
    {
        int pos = partition(arr, left, right);
        int exp_pos = right - k + 1;
        if (pos == exp_pos) return pos;
        if (pos < exp_pos) return kth_largest(arr, pos + 1, right, k);
        else return kth_largest(arr, left, pos - 1, pos - exp_pos);
    }
    return -1;
}

int main()
{
    int n, k, kl = -1;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) cin >> arr[i];
    cout << "Enter k for kth largest: ";
    cin >> k;
    if(k < 1 || k > n)
    {
        cout << "Invalid k";
        return -1;
    }
    kl = kth_largest(arr, 0, n-1, k);
    cout << "The " << k << "th largest element is: " << arr[kl];

    return 0;
}