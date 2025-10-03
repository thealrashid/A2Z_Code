#include <bits/stdc++.h>

using namespace std;

string removeKdigits(string num, int k) {
    stack<char> st;
    int n = num.size();

    for (char dig : num) {
        while (!st.empty() && k > 0 && dig < st.top()) {
            st.pop();
            k--;
        }
        st.push(dig);
    }

    while (k > 0 && !st.empty()) {
        st.pop();
        k--;
    }

    string res;
    while (!st.empty()) {
        res.push_back(st.top());
        st.pop();
    }
    reverse(res.begin(), res.end());

    size_t first_digit_pos = res.find_first_not_of('0');
    if (first_digit_pos == string::npos) return "0";
    res.erase(0, first_digit_pos);

    return res;
}

int main() {
    string num = "112";
    int k = 1;

    string res = removeKdigits(num, k);

    cout << res << endl;

    return 0;
}