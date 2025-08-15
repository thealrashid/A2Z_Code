#include <bits/stdc++.h>

using namespace std;

void subsets(vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &result) {
    result.push_back(current);

    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1]) continue;

        current.push_back(nums[i]);
        subsets(nums, i + 1, current, result);
        current.pop_back();
    }
}

vector<vector<int>> unique_subsets(vector<int> &nums) {
    vector<vector<int>> result;
    vector<int> current;

    sort(nums.begin(), nums.end());
    subsets(nums, 0, current, result);

    return result;
}

int main() {
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> result = unique_subsets(nums);

    for (auto itr : result) {
        for (auto i : itr) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}