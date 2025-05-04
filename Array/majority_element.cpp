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

int majority_element(vector<int> arr) {
    int n = arr.size();
    int candidate = -1, count = 0;

    // Phase 1: Find candidate
    for (int i = 0; i < n; i++) {
        if (count == 0) candidate = arr[i];

        if (arr[i] == candidate) count++;
        else count--;
    }

    // Phase 2: Verify the candidate
    count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == candidate) count++;
    }
    
    if (count > n/2) return candidate;
    else return -1; 
}

vector<int> majority_element_by_third(vector<int> arr) {
    int n = arr.size();
    int cnd1 = -1, cnd2 = -1;
    int count1 = 0, count2 = 0;
    vector<int> candidates;

    // Phase 1: Find candidate
    for (int i = 0; i < n; i++) {
        if (count1 == 0 and arr[i] != cnd2) {
            count1 = 1;
            cnd1 = arr[i];
        } else if (count2 == 0 and arr[i] != cnd1) {
            count2 = 1;
            cnd2 = arr[i];
        } else if (arr[i] == cnd1) {
            count1++;
        } else if (arr[i] == cnd2) {
            count2++;
        } else {
            count1--;
            count2--;
        }
    }

    // Phase 2: Verify the candidate
    count1 = 0;
    count2 = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == cnd1) count1++;
        if (arr[i] == cnd2) count2++;
    }

    if (count1 > n/3) candidates.push_back(cnd1);
    if (count2 > n/3) candidates.push_back(cnd2);

    return candidates;
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
    array_print(arr, n);
    // int ans = majority_element(arr);
    // cout << "Majority element: " << ans << endl;

    vector<int> ans = majority_element_by_third(arr);
    cout << "Majority elements: " << endl;
    for (auto i : ans) cout << i << endl;

    return 0;
}