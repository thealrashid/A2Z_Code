#include <bits/stdc++.h>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string prefixToInfix(string &prefix) {
    string infix;
    stack<string> st;
    string expr;

    for (int i = prefix.size() - 1; i >= 0; i--) {
        if (isOperator(prefix[i])) {
            if (st.size() < 2) {
                cout << "Invalid prefix string" << endl;
                return "";
            }

            string left = st.top();
            st.pop();
            string right = st.top();
            st.pop();
            expr = '(' + left + prefix[i] + right + ')';
        } else {
            expr = string(1, prefix[i]);
        }

        st.push(expr);
    }

    infix = st.top();
    st.pop();

    return infix;
}

int main() {
    string prefix = "*+AB-CD";

    cout << prefixToInfix(prefix) << endl;
    
    return 0;
}