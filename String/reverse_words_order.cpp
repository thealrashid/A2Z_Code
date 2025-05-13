#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void reverse_string(string& s, int start, int end) {
    while (start < end) {
        swap(s[start++], s[end--]);
    }
}

string reverse_words_order(string s) {
    string s1;

    int n = s.length();
    int i = 0;

    while (i < n) {
        while (i < n && s[i] == ' ') i++;

        int start = i;

        while (i < n & s[i] != ' ') i++;

        if (start < i) {
            reverse_string(s, start, i-1);
            s1 += s.substr(start, i - start);
            s1 += ' ';
        }
    }

    if (s1.back() == ' ') s1.pop_back();

    reverse_string(s1, 0, s1.length()-1);

    return s1;
}

int main() {
    string s;

    getline(cin, s);

    cout << reverse_words_order(s) << endl;

    return 0;
}