#include <bits/stdc++.h>

using namespace std;

void backtrack(int n, string current, vector<string> &v, int open, int close) {
    if ((int)current.size() == 2 * n) {
        v.push_back(current);
        return;
    }

    if (open < n) {
        backtrack(n, current + '(', v, open + 1, close);
    }

    if (close < open) {
        backtrack(n, current + ')', v, open, close + 1);
    }
}

vector<string> generate_parenthesis(int n) {
    vector<string> v;

    backtrack(n, "", v, 0, 0);
    sort(v.begin(), v.end());

    return v;
}

int main () {
    int n;
    vector<string> v;

    cout << "Enter n: ";
    cin >> n;

    v = generate_parenthesis(n);
    
    for (auto itr : v) {
        cout << itr << endl;
    }
}