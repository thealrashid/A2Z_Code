#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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

void quick_sort(vector<int>& arr, int left, int right)
{
    if(left < right)
    {
        int pos = partition(arr, left, right);

        quick_sort(arr, left, pos - 1);
        quick_sort(arr, pos + 1, right);
    }
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    vector<int> arr(n);
    cout << "Enter the elements: ";
    for(int i = 0; i < n; i++) cin >> arr[i];
    quick_sort(arr, 0, n-1);
    cout << "Sorted array is" << endl;
    for(int i = 0; i < n; i++) cout << arr[i] << " ";

    return 0;
}