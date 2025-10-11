#include <bits/stdc++.h>

using namespace std;

int characterReplacement(string str, int k) {
    int n = str.size();
    if (n == 0) return 0;
    int count[26] = {0};
    int i = 0;
    int length = 0;
    int max_freq = 0;

    for (int j = 0; j < n; j++) {
        count[str[j] - 'A']++;
        max_freq = max(max_freq, count[str[j] - 'A']);
        
        while (((j - i + 1) - max_freq) > k) {
            count[str[i++] - 'A']--;
        }
        length = max(length, j - i + 1);
    }

    return length;
}

int main() {
    string str = "AABABBA";
    int k = 1;

    int length = characterReplacement(str, k);

    cout << length << endl;

    return 0;
}