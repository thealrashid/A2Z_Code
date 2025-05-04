#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int appear_once(vector<int> arr, int n) {
    if(n == 1) return arr[0];

    int result = 0xffffffff;
    for(int i = 0; i < n; i++) result ^= arr[i];
    result = -(result+1);
    return result;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Enter a valid size" << endl;
        return -1;
    }
    vector<int> arr(n);
    cout << "Enter the elements" << endl;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int once = appear_once(arr, n);
    cout << once << " appears once." << endl;

    return 0;
}