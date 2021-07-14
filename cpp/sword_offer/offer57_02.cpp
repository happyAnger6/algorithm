#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> findContinuousSequence(int target) {
        vector<vector<int>> results;
        int ptr1 = 1, ptr2 = 1;
        int sum = ptr1;
        while (ptr1 <= target) {
            if (sum < target) {
                ptr2++;
                sum+=ptr2;
            }
            else if (sum > target) {
                sum-=ptr1;
                ptr1++;
            } else {
                if (ptr2 != ptr1) {
                    vector<int> v;
                    for (int i = ptr1; i <= ptr2; i++) {
                        v.push_back(i);
                    }
                    results.push_back(v);
                }
                ptr2++;
                sum+= ptr2;
            }
        }
        return results;
    }
};

int main()
{
    auto s = Solution();
    auto r = s.findContinuousSequence(15);
    for (auto vs : r) {
        for (auto v : vs)
            cout << v << " ";
        cout << endl;
    }
}