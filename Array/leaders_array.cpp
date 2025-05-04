#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void array_input(vector<int>& arr, int n) {
    for( int i = 0; i < n; i++) cin >> arr[i];
}

void array_print(vector<int> arr, int n) {
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;
}

vector<int> print_leaders(vector<int> arr, int n) {
    vector<int> ans;

    int last_leader = n-1;
    ans.push_back(arr[last_leader]);

    for (int i = n-2; i >= 0; i--) {
        if (arr[i] > arr[last_leader]) {
            last_leader = i;
            ans.push_back(arr[last_leader]);
        }
    }

    reverse(ans.begin(), ans.end());

    return ans;
}

int main() {
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    if (n <= 0) {
        cout << "Enter valid size." << endl;
        return -1;
    }
    vector<int> arr(n);
    array_input(arr, n);
    vector<int> ans = print_leaders(arr, n);
    array_print(ans, ans.size());

    return 0;
}