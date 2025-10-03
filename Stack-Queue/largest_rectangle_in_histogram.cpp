#include <bits/stdc++.h>

using namespace std;

int largestRectangleArea(vector<int>& heights) {
    int n = heights.size();
    vector<int> left(n), right(n);
    stack<int> st;
    int area = 0;

    for (int i = 0; i < n; i++) {
        while (!st.empty() && heights[i] < heights[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            left[i] = i + 1;
        } else {
            left[i] = i - st.top();
        }
        st.push(i);
    }
    while (!st.empty()) st.pop();

    for (int i = n - 1; i >= 0; i--) {
        while (!st.empty() && heights[i] <= heights[st.top()]) {
            st.pop();
        }
        if (st.empty()) {
            right[i] = n - i;
        } else {
            right[i] = st.top() - i;
        }
        st.push(i);
    }

    for (int i = 0; i < n; i++) {
        area = max(area, heights[i] * (right[i] + left[i] - 1));
    }

    return area;
}

int main() {
    vector<int> heights = {2,1,5,6,2,3};

    int area = largestRectangleArea(heights);

    cout << area << endl;

    return 0;
}