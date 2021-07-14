#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> results;

        int low = 0, high = nums.size() - 1;
        while (low < high) {
            if (nums[low] + nums[high] == target) {
                results.push_back(nums[low]);
                results.push_back(nums[high]);
                break;
            }
            else if (nums[low] + nums[high] > target) {
                high--;
            } else {
                low++;
            }
        }

        return results;
    }
};

int main()
{
    vector<int> nums = {2, 7, 11, 15};
    auto s = Solution();
    auto r = s.twoSum(nums, 9);
    for (auto v : r)
        cout << v << endl;
    
    nums = {10, 26, 30, 31, 47, 60};
    r = s.twoSum(nums, 40);
    for (auto v : r)
        cout << v << endl;

    return 0;
}