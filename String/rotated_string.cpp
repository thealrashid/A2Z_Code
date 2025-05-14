#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool rotated_string(string s, string t) {
    int n = s.length();
    int m = t.length();

    if (n != m) return 0;

    for (int i = 0, j = m-1; i < n && j >= 0; i++, j--) {
        string s1 = s.substr(0, i+1);
        string t1 = t.substr(j, m-j);

        if (s1 == t1) {
            string s2 = s.substr(i+1, n-1-i);
            string t2 = t.substr(0, j);

            if (s2 == t2) return 1;
        }
    }

    return 0;
}

int main() {
    string s = "abcde", t = "cdeab";

    cout << rotated_string(s, t) << endl;

    return 0;
}