#include <bits/stdc++.h>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string postfixToInfix(string &postfix) {
    string infix;
    stack<string> st;
    string expr;

    for (int i = 0; i < postfix.size(); i++) {
        if (isOperator(postfix[i])) {
            if (st.size() < 2) {
                cout << "Invalid prefix string" << endl;
                return "";
            }

            string right = st.top();
            st.pop();
            string left = st.top();
            st.pop();
            expr = '(' + left + postfix[i] + right + ')';
        } else {
            expr = string(1, postfix[i]);
        }

        st.push(expr);
    }

    infix = st.top();
    st.pop();

    return infix;
}

int main() {
    string postfix = "abcd^e-fgh*+^*+i-";

    cout << postfixToInfix(postfix) << endl;
    
    return 0;
}