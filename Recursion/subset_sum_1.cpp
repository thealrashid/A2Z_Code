#include <bits/stdc++.h>

using namespace std;

void subsets(vector<int> &nums, int index, int sum, vector<int> &result) {
    if (index == nums.size()) {
        result.push_back(sum);
        return;
    }

    subsets(nums, index + 1, sum + nums[index], result);

    subsets(nums, index + 1, sum, result);
}

vector<int> subset_sum(vector<int> &nums) {
    vector<int> result;

    subsets(nums, 0, 0, result);
    sort(result.begin(), result.end());

    return result;
}

int main() {
    vector<int> nums = {5, 2, 1};

    vector<int> result = subset_sum(nums);

    for (auto itr : result) {
        cout << itr << " ";
    }
    cout << endl;

    return 0;
}