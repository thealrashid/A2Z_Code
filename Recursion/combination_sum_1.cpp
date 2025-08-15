#include <bits/stdc++.h>

using namespace std;

void combinations(vector<int> &nums, int index, vector<int> &current, int current_sum, vector<vector<int>> &result, int target) {
    if (index >= nums.size()) return;

    if (current_sum > target) return;
    
    if (current_sum == target) {
        result.push_back(current);
        return;
    }

    combinations(nums, index + 1, current, current_sum, result, target);

    current.push_back(nums[index]);
    combinations(nums, index, current, current_sum + nums[index], result, target);
    current.pop_back();
}

vector<vector<int>> combination_sum(vector<int> &nums, int target) {
    vector<vector<int>> result;
    vector<int> current;
    int current_sum = 0;
    combinations(nums, 0, current, current_sum, result, target);

    return result;
}

int main() {
    vector<int> nums = {2, 3, 6, 7};
    int k = 7;

    vector<vector<int>> result = combination_sum(nums, k);

    for (auto itr : result) {
        for (auto i : itr) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}