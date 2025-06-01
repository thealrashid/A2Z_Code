#include <bits/stdc++.h>

using namespace std;

void sorted_insert(stack<int> &s, int x) {
    if (s.empty() || x > s.top()) {
        s.push(x);
        return;
    }

    int temp = s.top();
    s.pop();
    sorted_insert(s, x);
    s.push(temp);
}

void sort(stack<int> &s) {
    if (!s.empty()) {
        int x = s.top();
        s.pop();
        sort(s);
        sorted_insert(s, x);
    }
}

int main() {
    stack<int> s;
    s.push(5);
    s.push(3);
    s.push(4);
    s.push(1);
    s.push(2);

    sort(s);

    while (!s.empty()) {
        cout << s.top() << endl;
        s.pop();
    }

    return 0;
}