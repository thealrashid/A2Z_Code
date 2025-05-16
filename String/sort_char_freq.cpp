#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string sort_char_freq(string s) {
    unordered_map<char, int> m;

    for (int i = 0; i < s.length(); i++) {
        m[s[i]]++;
    }

    vector<pair<char, int>> v(m.begin(), m.end());

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) { return a.second > b.second; });

    string s1;

    for (const auto& p : v) {
        s1.append(p.second, p.first);
    }

    return s1;
}

int main() {
    string s = "tree";

    cout << sort_char_freq(s) << endl;
}