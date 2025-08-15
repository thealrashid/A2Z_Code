#include <bits/stdc++.h>

using namespace std;

void combinations(vector<int> &nums, int index, vector<int> &current, int current_sum, vector<vector<int>> &result, int target) {    
    if (current_sum == target) {
        result.push_back(current);
        return;
    }

    if (current_sum > target) return;

    for (int i = index; i < nums.size(); i++) {
        if (i > index && nums[i] == nums[i - 1]) continue;

        if (nums[i] > target) break;

        current.push_back(nums[i]);
        combinations(nums, i + 1, current, current_sum + nums[i], result, target);
        current.pop_back();
    }
    
}

vector<vector<int>> combination_sum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    vector<int> current;
    int current_sum = 0;
    sort(nums.begin(), nums.end());
    combinations(nums, 0, current, current_sum, result, target);

    return result;
}

int main() {
    vector<int> nums = {10, 1, 2, 7, 6, 1, 5};
    int k = 8;

    vector<vector<int>> result = combination_sum(nums, k);

    for (auto itr : result) {
        for (auto i : itr) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}