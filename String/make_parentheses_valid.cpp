#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int make_parentheses_valid(string s) {
    if (s.empty()) return 0;

    int n = s.length();
    int left = 0, right = 0;

    for (int i = 0; i < n; i++) {
        if (s[i] == ')') {
            if (left != 0) {
                left--;
            } else {
                right++;
            }
        } else {
            left++;
        }
    }

    return right + left;
}

int main() {
    string s = ")))(((";

    cout << make_parentheses_valid(s) << endl;
}