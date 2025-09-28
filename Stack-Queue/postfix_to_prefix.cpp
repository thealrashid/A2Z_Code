#include <bits/stdc++.h>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string postfixToPrefix(string &postfix) {
    string prefix;
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
            expr = postfix[i] + left + right;
        } else {
            expr = string(1, postfix[i]);
        }

        st.push(expr);
    }

    prefix = st.top();
    st.pop();

    return prefix;
}

int main() {
    string postfix = "abcd^e-fgh*+^*+i-";

    cout << postfixToPrefix(postfix) << endl;
    
    return 0;
}