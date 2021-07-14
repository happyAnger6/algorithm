#include <cstdint>
#include <iostream>

using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
       int cnts = 0;
       while (n > 0) {
           cnts += 1;
           n &= (n-1);
       }

       return cnts;
    }
};

int main()
{
    auto s = Solution();
    cout << s.hammingWeight(11) << endl;
    cout << s.hammingWeight(128) << endl;
    cout << s.hammingWeight(4294967293) << endl;
    
    cout << s.hammingWeight(01011) << endl;
}