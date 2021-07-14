#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    vector<string> printNumbers(int n) {
        vector<string> results;
        string s;
        gen_nth(0, n, results, s);
        return results;
    }

    void gen_nth(int k, int n, vector<string> &results, string &s, int first_no_zero=-1) {
        if (n == 0) {
            if (first_no_zero != -1)
                results.push_back(s.substr(first_no_zero));
            return;
        }

        for (int i = 0; i < 10; i++) {
            s.push_back((char)('0' + i));
            if (i != 0 && first_no_zero == -1)
                gen_nth(k + 1, n-1, results, s, k);
            else
                gen_nth(k + 1, n-1, results, s, first_no_zero);
            s.pop_back();
        }
    }
};

int main()
{
    auto s = Solution();
    for (auto v: s.printNumbers(2))
        cout << v << " ";

    return 0;
}