#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string longest_common_prefix(vector<string> strs) {
    if (strs.empty()) return "";

        sort(strs.begin(), strs.end());

        string first = strs[0];
        string last = strs.back();

        int i = 0;

        while (i < first.size() && i < last.size() && first[i] == last[i]) {
            i++;
        }

        return first.substr(0, i);
}

int main() {
    vector<string> s = {"flower", "flow", "flight"};

    cout << longest_common_prefix(s) << endl;

    return 0;
}