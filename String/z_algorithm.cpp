#include <bits/stdc++.h>

using namespace std;

vector<int> compute_z(string s) {
    int n = s.length();
    vector<int> z(n+1);
    z[0] = 0;
    int left = 0, right = 0;

    for (int i = 1; i < n; i++) {
        if (i > right) { // If we are outside the z-box
            left = right = i;
            while (right < n && s[right] == s[right - left]) {
                right++;
            }
            z[i] = right - left;
            right--; // Come back to the last matched position
        } else { // We are inside the z-box
            int i1 = i - left; // Position relative to the starting of the z-box i.e. left

            if (z[i1] < right - i + 1) { // Checking if value doesn't go beyond the z-box
                z[i] = z[i1];
            } else { // Value goes beyond z-box, try to do the same pattern matching as if outside the z-box
                left = i;
                while (right < n && s[right] == s[right - left]) {
                    right++;
                }
                z[i] = right - left;
                right--;
            }
        }
    }

    return z;
}

vector<int> search_pattern(string s, string t) {
    string concat = s + "$" + t;
    int n = s.length();
    
    vector<int> z = compute_z(concat);
    vector<int> pos;

    for (int i = 0; i < z.size(); i++) {
        if (z[i] == n) {
            pos.push_back(i - n - 1);
        }
    }

    return pos;
}

int main() {
    string s = "abc", t = "aaabcabcabc";

    vector<int> pos = search_pattern(s, t);

    for (int p : pos) cout << p << endl;
}