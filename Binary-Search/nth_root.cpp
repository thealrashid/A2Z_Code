#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int nth_root(int m, int n) {
    if (m == 1) return 1;
    if (m < 1) return 0;

    int left = 1, right;
    int mid = -1, sq;

    right = m / ((int)pow(2, n-1));

    while (left <= right) {
        mid = (left + right) / 2;
        sq = (int)pow(mid, n);

        if (sq == m) return mid;
        else if (sq > m) right = mid - 1;
        else left = mid + 1;
    }

    return -1;
}

int main() {
    int n, m;

    cout << "Enter the number and n for nth root: ";
    cin >> m >> n;
    int s = nth_root(m, n);
    cout << n << "th root: " << s << endl; 
}