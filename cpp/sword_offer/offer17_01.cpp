#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int max_int(int n) {
        int max_int = 9;
        while (n > 1) {
            max_int = max_int * 10 + 9;
            n -= 1;
        }
        return max_int;
    }

    vector<int> printNumbers(int n) {
        vector<int> results;
        int imax = max_int(n);
        for (int i = 1; i <= imax; i++)
            results.push_back(i);
        return results;
    }
};

int main()
{
    auto s = Solution();
    for (auto v: s.printNumbers(2))
        cout << v << " ";

    return 0;
}