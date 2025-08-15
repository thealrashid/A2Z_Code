#include <bits/stdc++.h>

using namespace std;

void combinations(vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &result, int k, int n) {
    if (current.size() > k) return;

    if (k == current.size() && n == 0) {
        result.push_back(current);
        return;
    }

    if (index == nums.size()) return;

    if (nums[index] > n) return;

    current.push_back(nums[index]);
    combinations(nums, index + 1, current, result, k, n - nums[index]);
    current.pop_back();

    combinations(nums, index + 1, current, result, k, n);
}

vector<vector<int>> conbinationSum3(int k, int n) {
    vector<vector<int>> result;
    vector<int> current;
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    combinations(nums, 0, current, result, k, n);

    return result;
}

int main() {
    int k = 9;
    int n = 45;

    vector<vector<int>> result = conbinationSum3(k, n);

    for (auto itr : result) {
        for (auto i : itr) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}