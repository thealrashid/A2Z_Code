#include <bits/stdc++.h>

using namespace std;

void generateSubsets(vector<int> &nums, int index, vector<int> &current, vector<vector<int>> &result) {
    if (index == nums.size()) {
        result.push_back(current);
        return;
    }

    //exclude
    generateSubsets(nums, index + 1, current, result);

    //include
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current, result);
    current.pop_back(); //backtrack
}

vector<vector<int>> subsets(vector<int> &nums) {
    vector<int> current;
    vector<vector<int>> result;
    generateSubsets(nums, 0, current, result);

    return result;
}

int main() {
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> v = subsets(nums);

    for (auto itr : v) {
        for (auto i : itr) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}