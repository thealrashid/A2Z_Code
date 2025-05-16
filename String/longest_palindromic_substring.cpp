#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void expand_from_center(string s, int left, int right, int& start, int& maxlen) {
    while (left >= 0 && right < s.length() && s[left] == s[right]) {
        left--;
        right++;
    }

    int len = right - left - 1;
    if (len > maxlen) {
        maxlen = len;
        start = left + 1;
    }
}

string longest_palindromic_substring(string s) {
    if (s.empty()) return "";

    int n = s.length();

    int start = 0, maxlen = 0;

    for (int i = 0; i < n; i++) {
        expand_from_center(s, i, i, start, maxlen);
        expand_from_center(s, i, i+1, start, maxlen);
    }

    return s.substr(start, maxlen);
}

string manachers_algo(string s) {
    if (s.empty()) return "";

    string t = "^";
    for (char c : s) {
        t += "#";
        t += c;
    }
    t += "#$";

    int n = t.length();
    vector<int> p(n, 0);
    int center = 0, right = 0;

    for (int i = 1; i < n - 1; i++) {
        int mirror = 2 * center - i;
        if (i < right) {
            p[i] = min(right - i, p[mirror]);
        }

        while (t[i + p[i] + 1] == t[i - p[i] - 1]) {
            p[i]++;

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }
        }
    }

    int maxlen = 0, center_index = 0;
    for (int i = 1; i < n - 1; i++) {
        if (p[i] > maxlen) {
            maxlen = p[i];
            center_index = i;
        }
    }

    int start = (center_index - maxlen) / 2;
    return s.substr(start, maxlen);
}

int main() {
    string s = "cbbd";

    // cout << longest_palindromic_substring(s) << endl;
    cout << manachers_algo(s) << endl;
}