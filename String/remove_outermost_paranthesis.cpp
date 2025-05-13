#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string remove_outermost_paranthesis(string s) {
    if (s.empty()) return s;
    bool outermost = 0;
    int x = 0;
    string s1;

    for (char c : s) {
        if (c == '(') {
            if (outermost == 0) {
                outermost = 1;
            } else {
                s1 += c;
            }
            x++;
        } else {
            x--;
            if (x == 0) {
                outermost = 0;
            }

            if (outermost != 0) {
                s1 += c;
            }
        }
    }

    return s1;
}

int main() {
    string s = "(()())(())";

    cout << remove_outermost_paranthesis(s) << endl;

    return 0;
}