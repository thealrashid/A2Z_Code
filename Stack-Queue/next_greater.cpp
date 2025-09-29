#include <bits/stdc++.h>

using namespace std;

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    vector<int> res;
    unordered_map<int, int> nextGreater;
    stack<int> st;
    int n1 = nums1.size();
    int n2 = nums2.size();

    for (int i = 0; i < n2; i++) {
        while (!st.empty() && nums2[i] > st.top()) {
            nextGreater[st.top()] = nums2[i];
            st.pop();
        }
        st.push(nums2[i]);
    }

    while (!st.empty()) {
        nextGreater[st.top()] = -1;
        st.pop();
    }

    for (int i = 0; i < n1; i++) {
        res.push_back(nextGreater[nums1[i]]);
    }

    return res;
}

int main() {
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    vector<int> res = nextGreaterElement(nums1, nums2);

    for (int itr : res) {
        cout << itr << " ";
    }
    cout << endl;
    
    return 0;
}