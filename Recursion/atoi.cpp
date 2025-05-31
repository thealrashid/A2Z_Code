#include <bits/stdc++.h>

using namespace std;

int recursive_atoi(string s, int index, int sign, int result, bool started) {
    if (index == s.length()) return result * sign;

    char c = s[index];

    if (isspace(c)) {
        return recursive_atoi(s, index + 1, sign, result, false);
    } else if (!started && c == '-') {
        return recursive_atoi(s, index + 1, -1, result, true);
    } else if (!started && c == '+') {
        return recursive_atoi(s, index + 1, 1, result, true);
    } else if (isdigit(c)) {
        int digit = c - '0';
        return recursive_atoi(s, index + 1, sign, result * 10 + digit, true);
    } else {
        return result * sign;
    }
}

int my_atoi(string s) {
    return recursive_atoi(s, 0, 1, 0, false);
}

int main() {
    int num = my_atoi("    5-+42");
    cout << num << endl;

    return 0;
}