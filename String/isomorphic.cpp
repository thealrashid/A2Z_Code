#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool is_isomorphic(string s, string t) {
    unordered_map<char, char> m1, m2;

    int n = s.length();
    int p = t.length();

    if (n != p) return 0;

    for (int i = 0; i < n; i++) {
        if (m1.find(s[i]) == m1.end()) {
            m1[s[i]] = t[i];
        } else {
            if (m1[s[i]] != t[i]) return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        if (m2.find(t[i]) == m2.end()) {
            m2[t[i]] = s[i];
        } else {
            if (m2[t[i]] != s[i]) return 0;
        }
    }

    return 1;
}

int main() {
    string s = "egg", t = "add";

    cout << is_isomorphic(s, t) << endl;

    return 0;
}