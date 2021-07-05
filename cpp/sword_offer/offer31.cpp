#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> data;
        int i = 0, j = 0;
        int s = pushed.size();
        while (true) {
            if (!data.empty() && data.top() == popped[j]) {
                data.pop();
                j++;
                if (j == s)
                    return true;
            } else {
                if (i > s)
                    return false;
                data.push(pushed[i]);
                i++;
            }
        }
    }
};