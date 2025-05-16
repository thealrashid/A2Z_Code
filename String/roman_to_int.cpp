#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int roman_to_int(string s) {
    unordered_map<char, int> roman = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000}
    };

    int n = s.length();
    int ans = 0;

    for (int i = 0; i < n; ++i) {
        int curr = roman[s[i]];
        
        if (i < n - 1 && roman[s[i]] < roman[s[i+1]]) ans -= curr;
        else ans += curr;
    }

    return ans;
}

int main() {
    string s = "XVIII";

    cout << roman_to_int(s) << endl;
}