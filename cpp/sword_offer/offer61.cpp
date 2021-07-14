#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isStraight(vector<int>& nums) {
        int min_num = 14, max_num = -1;
        for (auto num : nums) {
            min_num = min(min_num, num);
            max_num = max(max_num, num);
        }

        return max_num - min_num < 5;
    }
};

int main() {
    auto s = Solution();
    vector<int> a = {1, 2, 3, 4, 5};
    cout << s.isStraight(a) << endl;
    a = {0, 0, 1, 2, 5};
    cout << s.isStraight(a) << endl;
    a = {0, 0, 1, 3, 5};
    cout << s.isStraight(a) << endl;
    a = {0, 0, 1, 2, 6};
    cout << s.isStraight(a) << endl;
    a = {0, 0, 1, 2, 7};
    cout << s.isStraight(a) << endl;

    return 0;
}