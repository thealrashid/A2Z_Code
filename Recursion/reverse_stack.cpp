#include <bits/stdc++.h>

using namespace std;

void insert_at_bottom(stack<int> &s, int x) {
    if (s.empty()) {
        s.push(x);
    } else {
        int temp = s.top();
        s.pop();
        insert_at_bottom(s, x);
        s.push(temp);
    }
}

void reverse(stack<int> &s) {
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        reverse(s);
        insert_at_bottom(s, x);
    }
}

int main() {
    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(2);

    reverse(s);

    while (!s.empty()) {
        cout << s.top() << " ";
        s.pop();
    }

    cout << endl;

    return 0;
}