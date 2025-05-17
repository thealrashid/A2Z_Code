#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string count_and_say(int n) {
    if (n <= 0) return "";

    string s = "1";

    for (int i = 2; i <= n; i++) {
        string t = "";
        int count = 1;
        for (int j = 1; j < s.length(); j++) {
            if (s[j] == s[j - 1]) {
                count++;
            } else {
                t += count + '0';
                t += s[j - 1];
                count = 1;
            }
        }

        t += count + '0';
        t += s.back();
        s = t;
    }

    return s;
}

int main() {
    int n = 4;

    cout << count_and_say(n) << endl;
}