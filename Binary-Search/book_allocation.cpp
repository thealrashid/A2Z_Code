#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int can_allocate(vector<int> arr, int pages, int std) {
    int allocated = 1;
    int current_pages = 0;

    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] <= pages - current_pages) {
            current_pages += arr[i];
        } else {
            current_pages = arr[i];
            allocated++;    
        }
    }

    cout << "allocated students: " << allocated << " " << "max pages: " << pages << endl;

    return allocated;
}

int book_allcation(vector<int> arr, int std) {
    int n = arr.size();

    if (n == 0) return 0;

    int left = 0,  right = 0;
    int mid, ans = -1;

    for (int i = 0; i < n; i++) {
        left = max(left, arr[i]);
        right += arr[i];
    }

    while (left <= right) {
        mid = (left + right) / 2;
        
        int allocated = can_allocate(arr, mid, std);
        if (allocated <= std) {
            ans = mid;
            right  = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return ans;
}

int main() {
    vector<int> arr = {2,3,1,1,1,1,1};
    int std = 5;
    
    int pages = book_allcation(arr, std);
    cout << "Maximum pages: " << pages << endl;

    return 0;
}