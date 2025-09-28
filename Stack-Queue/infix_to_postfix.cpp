#include <bits/stdc++.h>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return -1;
}

string infix_to_postfix(string &infix) {
    stack<char> st;
    string postfix;

    for (char itr : infix) {
        if (itr == '(') {
            st.push(itr);
        } else if (isOperator(itr)) {
            if (st.empty() || st.top() == '(' || precedence(itr) > precedence(st.top())) {
                st.push(itr);
            } else {
                while (!st.empty() && precedence(st.top()) >= precedence(itr)) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(itr);
            }
        } else if (itr == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            postfix += itr;
        }
    }

    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }

    return postfix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";

    cout << infix_to_postfix(infix) << endl;

    return 0;
}