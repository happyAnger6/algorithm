#include <climits>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int cur_min_profit = INT_MAX;
        int max_profit = 0;

        for (auto p : prices) {
            if (p < cur_min_profit)
                cur_min_profit = p;
            else if (p - cur_min_profit > max_profit)
                max_profit = p - cur_min_profit;
        }
        return max_profit;
    }
};

int main() {
    auto s = Solution();
    vector<int> v = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(v) << endl;
    
    v = {7, 6, 4, 3, 1};
    cout << s.maxProfit(v) << endl;

    return 0;
}