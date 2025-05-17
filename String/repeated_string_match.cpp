#include <bits/stdc++.h>

using namespace std;

int repeated_string_match(string a, string b) {
        string repeated = a;
        int count = 1;

        while (repeated.length() < b.length()) {
            repeated += a;
            count++;
        }

        if (repeated.find(b) != string::npos) {
            return count;
        }

        repeated += a;
        count++;

        if (repeated.find(b) != string::npos) {
            return count;
        }

        return -1;
}

int main() {
    string a = "abcd", b = "cdabcdab";

    cout << repeated_string_match(a, b) << endl;
}