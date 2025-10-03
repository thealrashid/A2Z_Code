#include <bits/stdc++.h>

using namespace std;

vector<int> asteroidCollision(vector<int>& asteroids) {
    stack<int> st;

    for (int a : asteroids) {
        bool destroyed = false;
        
        if (a > 0) {
            st.push(a);
        } else {
            while (!st.empty() && st.top() > 0) {
                if (st.top() < -a) {
                    st.pop();
                    continue;
                } else if (st.top() == -a) {
                    st.pop();
                }
                destroyed = true;
                break;
            }
            if (!destroyed) st.push(a);
        }
    }

    vector<int> res(st.size());

    for (int i = st.size() - 1; i >= 0; i--) {
        res[i] = st.top();
        st.pop();
    }

    return res;
}

int main() {
    vector<int> asteroids = {5,10,-5};

    vector<int> res = asteroidCollision(asteroids);

    for (auto &itr : res) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}