#include <bits/stdc++.h>

using namespace std;

void backtrack(int n, string current, vector<string> &v) {
    if ((int)current.size() == n) {
        v.push_back(current);
        return;
    }

    backtrack(n, current + '0', v);

    if (current.empty() || current.back() != '1') {
        backtrack(n, current + '1', v);
    }
}

vector<string> generate_binary_strings(int n) {
    vector<string> v;

    backtrack(n, "", v);
    sort(v.begin(), v.end());

    return v;
}

int main () {
    int n;
    vector<string> v;

    cout << "Enter the length of strings: ";
    cin >> n;

    v = generate_binary_strings(n);
    
    for (auto itr : v) {
        cout << itr << endl;
    }
}