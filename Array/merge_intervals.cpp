#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void input_interval(vector<pair<int, int>>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cin >> arr[i].first >> arr[i].second;
    }
}

void print_interval(vector<pair<int, int>> arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << "[" << arr[i].first << ", " << arr[i].second << "]" << endl;
    }
}

vector<pair<int, int>> merge_intervals(vector<pair<int, int>> arr) {
    vector<pair<int, int>> merged;

        sort(arr.begin(), arr.end());

        for (int i = 0; i < arr.size(); i++) {
            if (merged.empty() || arr[i].first > merged.back().second) {
                merged.push_back(arr[i]);
            } else {
                merged.back().second = max(merged.back().second, arr[i].second);
            }
        }

        return merged;

    return merged;
}

int main() {
    int n;
    cout << "Enter the number of intervals: ";
    cin >> n;
    vector<pair<int, int>> arr(n);
    cout << "Enter the intervals:" << endl;
    input_interval(arr);
    cout << "The intervals are:" << endl;
    print_interval(arr);

    vector<pair<int, int>> merged = merge_intervals(arr);
    cout << "Merged intervals:" << endl;
    print_interval(merged);

    return 0;
}