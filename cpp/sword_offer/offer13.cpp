#include <iostream>
#include <vector>
#include <deque>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    int posSum(int m) {
        int sum = 0;
        while (m > 0) {
            sum += (m%10);
            m /= 10;
        }
        return sum;
    }

    int isOk(int m, int n, int k) {
        return posSum(m) + posSum(n) <= k;
    }

    int movingCount(int m, int n, int k) {
        deque<pair<int, int>> q;
        vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
        set<pair<int, int>> seen;

        q.push_back({0, 0});
        seen.insert({0, 0});
        int num = 0;

        while (!q.empty()) {
            int l = q.size();
            num += l;
            while (l > 0) {
                l -= 1;
                auto pos = q.front();
                q.pop_front();

                for (auto dir : dirs) {
                    int next_x = pos.first + dir.first;
                    int next_y = pos.second + dir.second;

                    if (next_x < 0 || next_x >= m || next_y < 0 || next_y >= n)
                        continue;
                    
                    if (seen.find({next_x, next_y}) != seen.end())
                        continue;

                    if (!isOk(next_x, next_y, k))
                        continue;

                    q.push_back({next_x, next_y});
                    seen.insert({next_x, next_y});
                }
            }
        }
        return num;
    }
};

int main()
{
    auto s = Solution();
    cout << s.movingCount(2, 3, 1) << endl;
    cout << s.movingCount(3, 1, 0) << endl;
    cout << s.movingCount(1, 2, 1) << endl;
    cout << s.movingCount(12, 8, 4) << endl;
}