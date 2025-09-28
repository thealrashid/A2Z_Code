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

string infix_to_pretfix(string &infix) {
    reverse(infix.begin(), infix.end());
    for(int i=0; i<infix.size(); i++){
        if(infix[i]=='(') infix[i]=')';
        else if(infix[i]==')') infix[i]='(';
    }

    stack<char> st;
    string prefix;

    for (char itr : infix) {
        if (itr == '(') {
            st.push(itr);
        } else if (isOperator(itr)) {
            if (st.empty() || st.top() == '(' || precedence(itr) > precedence(st.top())) {
                st.push(itr);
            } else {
                while (!st.empty() && precedence(st.top()) >= precedence(itr)) {
                    prefix += st.top();
                    st.pop();
                }
                st.push(itr);
            }
        } else if (itr == ')') {
            while (!st.empty() && st.top() != '(') {
                prefix += st.top();
                st.pop();
            }
            st.pop();
        } else {
            prefix += itr;
        }
    }

    while (!st.empty()) {
        prefix += st.top();
        st.pop();
    }

    reverse(prefix.begin(), prefix.end());

    return prefix;
}

int main() {
    string infix = "a+b*(c^d-e)^(f+g*h)-i";

    cout << infix_to_pretfix(infix) << endl;

    return 0;
}