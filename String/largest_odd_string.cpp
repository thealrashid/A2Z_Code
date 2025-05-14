#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string largest_odd_string(string s) {
    int n = s.length();
    int i, j;
    string s1 = "";

    for (i = n-1; i >= 0; i--) {
        if (s[i] % 2 != 0) break;
    }

    for (j = 0; j < i; j++) {
        if (s[j] != '0') break;
    }

    s1 = s.substr(j, i-j+1);

    return s1;
}

int main() {
    string s = "4026";

    cout << largest_odd_string(s) << endl;

    return 0;
}