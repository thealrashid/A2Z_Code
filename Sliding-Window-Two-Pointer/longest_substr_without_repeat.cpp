#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string str) {
    int n = str.size();

    if (n == 0) return 0;

    int i = 0;
    unordered_map<char, int> mp;
    int size = 0;

    for (int j = 0; j < n; j++) {
        mp[str[j]]++;
        while (mp[str[j]] > 1) {
            mp[str[i++]]--;
        }
        size = max(size, j - i + 1);
    }

    return size;
}

int main() {
    string str = "abcabcbb";

    int size = lengthOfLongestSubstring(str);

    cout << size << endl;

    return 0;
}