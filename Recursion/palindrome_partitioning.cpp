#include <bits/stdc++.h>

using namespace std;

bool is_palindrome(string s, int start, int end) {
    while (start <= end) {
        if(s[start++] != s[end--]) {
            return 0;
        }
    }

    return 1;
}

void palindrome_partition(string s, int index, vector<vector<string>> &result, vector<string> &current) {
    if (index == s.size()) {
        result.push_back(current);
        return;
    }

    for (int i = index; i < s.size(); i++) {
        if (is_palindrome(s, index, i)) {
            current.push_back(s.substr(index, i - index + 1));
            palindrome_partition(s, i + 1, result, current);
            current.pop_back();
        }
    }
}

vector<vector<string>> partition(string s) {
    vector<vector<string>> result;
    vector<string> current;

    palindrome_partition(s, 0, result, current);

    return result;
}

int main() {
    string s = "aab";

    vector<vector<string>> result = partition(s);

    for (auto itr : result) {
        for (auto str : itr) {
            cout << str << " ";
        }
        cout << endl;
    }
    return 0;
}