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

int maximalRectangle(vector<vector<char>>& matrix) {
    int row = matrix.size();
    int col = matrix[0].size();
    int area = 0;
    vector<vector<int>> heights(row, vector<int>(col));

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i == 0) {
                heights[i][j] = matrix[i][j] - '0';
            } else {
                if (matrix[i][j] == '1') {
                    heights[i][j] = heights[i - 1][j] + matrix[i][j] - '0';
                } else {
                    heights[i][j] = 0;
                }
            }
        }
    }

    for (int i = 0; i < row; i++) {
        area = max(area, largestRectangleArea(heights[i]));
    }

    return area;
}

int main() {
    vector<vector<char>> matrix = {
        {'1','0','1','0','0'},
        {'1','0','1','1','1'},
        {'1','1','1','1','1'},
        {'1','0','0','1','0'}
    };

    int area = maximalRectangle(matrix);

    cout << area << endl;

    return 0;
}