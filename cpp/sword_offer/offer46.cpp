#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> results;
        permute_next(0, nums, results);
        return results;
    }

    void permute_next(int i, vector<int>& nums, vector<vector<int>> &results) {
        if (i == nums.size()) {
            results.push_back(nums);
            return;
        }

        int j = i;
        while (j < nums.size()) {
            int tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = nums[i];
            permute_next(i+1, nums, results);
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = nums[i];
            j++;
        }
    }
};

int main()
{
    auto s = Solution();
    vector<int> nums = {1, 2, 3};
    auto r = s.permute(nums);
    for (auto ret: r) {
        for (auto num : ret)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}