#include <bits/stdc++.h>

using namespace std;

int numberOfSubstrings(string s) {
    vector<int> mp(3, 0);
    int count = 0;
    int n = s.size();
    int left = 0, right = 0;

    while (left <= right && right < n) {
        mp[s[right++] - 'a']++;
        
        while (mp[0] > 0 && mp[1] > 0 && mp[2] > 0) { //valid window
            if (mp[s[left] - 'a'] == 1) { //minimum valid window
                count += left + 1;
                break;
            } else {
                mp[s[left++] - 'a']--;
            }
        }
    }

    return count;
}

int main() {
    string s = "aaacb";

    cout << numberOfSubstrings(s) << endl;

    return 0;
}