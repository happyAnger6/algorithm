#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int get_num(vector<int>& nums) {
        int num = 0;
        for (auto v: nums) {
            num ^= v;
        }
        return num;
    }

    vector<int> singleNumbers(vector<int>& nums) {
        int diff = 0;
        for (auto v : nums) {
            diff ^= v;
        }

        int partition = diff & ~(diff - 1);
        vector<int> nums1;
        vector<int> nums2;

        for (auto v : nums) {
            if (partition & v) {
                nums1.push_back(v);
            } else {
                nums2.push_back(v);
            }
        }

        vector<int> result;
        result.push_back(get_num(nums1));
        result.push_back(get_num(nums2));
        return result;
    }
};

int main()
{
    auto s = Solution();
    vector<int> nums = {4, 1, 4, 6};
    auto r = s.singleNumbers(nums);
    for (auto v : r)
        cout << v << endl;
    
    nums = {1, 2, 10, 4, 1, 4, 3, 3};
    r = s.singleNumbers(nums);
    for (auto v : r)
        cout << v << endl;

    return 0;
}