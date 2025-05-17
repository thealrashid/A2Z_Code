#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int sum_of_beauty(string s) {
    int n = s.length();
    int total = 0;

    for (int i = 0; i < n; i++) {
        vector<int> freq(26, 0);
        
        for (int j = i; j < n; j++) {
            freq[s[j] - 'a']++;

            int max_freq = 0, min_freq = INT_MAX;

            for (int k = 0; k < 26; k++) {
                if (freq[k] == 0) continue;
                max_freq = max(max_freq, freq[k]);
                min_freq = min(min_freq, freq[k]);
            }

            total += max_freq - min_freq;
        }
    }

    return total;
}

int main() {
    string s = "aabcb";

    cout << sum_of_beauty(s) << endl;
}