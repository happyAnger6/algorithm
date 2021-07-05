#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int cuttingRope(int n) {
        if (n <= 3)
            return n-1;

        vector<int> dp(n+1, 0);
        dp[0] = 1;
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;

        for(int i = 4; i <= n; i++) {
            for(int j = 1; j <= i/2; j++) {
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
            }
        }
        return dp[n];
    }
};

int main() {
    auto so = Solution();
    cout << so.cuttingRope(2) << endl;
    cout << so.cuttingRope(3) << endl;
    cout << so.cuttingRope(4) << endl;
    cout << so.cuttingRope(6) << endl;
    cout << so.cuttingRope(10) << endl;

    return 0;
}