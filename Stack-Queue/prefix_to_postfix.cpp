#include <bits/stdc++.h>

using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string prefixToPostfix(string &prefix) {
    string postfix;
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
            expr = left + right + prefix[i];
        } else {
            expr = string(1, prefix[i]);
        }

        st.push(expr);
    }

    postfix = st.top();
    st.pop();

    return postfix;
}

int main() {
    string prefix = "-+a*b^-^cde+f*ghi";

    cout << prefixToPostfix(prefix) << endl;
    
    return 0;
}