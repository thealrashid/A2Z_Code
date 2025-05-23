#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool is_anagram(string s, string t) {
    if (s.length() != t.length()) return false;

        int count[26] = {0};

        for (int i = 0; i < s.length(); i++) {
            count[s[i] - 'a']++;
            count[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) return false;
        }

        return true;
}

int main() {
    string s = "abcde", t = "cdeab";

    cout << is_anagram(s, t) << endl;

    return 0;
}