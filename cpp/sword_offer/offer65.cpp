#include <iostream>

using namespace std;

class Solution {
public:
    int add(int a, int b) {
        while (b != 0) {
            int tmp = ((unsigned int)a&b) << 1;
            a = a ^ b;
            b = tmp;
        }

        return a;
    }
};

int main() {
    auto s = Solution();

    cout << s.add(1, 1) << endl;
    cout << s.add(2, -1) << endl;
    cout << s.add(12, 23) << endl;
    cout << s.add(12, -23) << endl;

    return 0;
}