#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int my_atoi(string s) {
    if (s.empty()) return 0;
    bool  neg = 0;
    int i = 0;
    while (i < s.length() && s[i] == ' ') i++;
    if (i < s.length() && s[i] == '-') {
        neg = 1;
        i++;
    } else if (i < s.length() && s[i] == '+') {
        neg = 0;
        i++;
    }
    int num = 0;

    while (i < s.length() && isdigit(s[i])) {
        int digit = s[i] - '0';

        if (num > (INT_MAX - digit) / 10) {
            return neg ? INT_MIN : INT_MAX;
        }

        num = num * 10 + digit;
        i++;
    }

    return neg ? -num : num;
}

int main() {
    string s = "   -042";

    cout << my_atoi(s) << endl;
}