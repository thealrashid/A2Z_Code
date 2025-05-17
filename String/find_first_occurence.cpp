#include <bits/stdc++.h>

using namespace std;

int find_first_occurence(string haystack, string needle) {
    int n = haystack.length(), m = needle.length();

    int needle_hash = 0;
    for (int i = 0; i < m; i++) {
        needle_hash += (needle[i] - 'a' + 1);
    }

    vector<int> prefix_hash(n + 1, 0);

    for (int i = 0; i < n; i++) {
        prefix_hash[i + 1] = (prefix_hash[i] +  (haystack[i] - 'a' + 1));
    }

    for (int i = 0; i + m <= n; i++) {
        int current_hash = prefix_hash[i + m] - prefix_hash[i];

        if (current_hash == needle_hash) {
            if (haystack.substr(i, m) == needle) {
                return i;
            }
        }
    }

    return -1;
}

int main() {
    string haystack = "asdfasdf", needle = "fas";

    cout << find_first_occurence(haystack, needle) << endl;
}