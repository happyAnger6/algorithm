#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string replaceSpace(string s) {
        int old_size = s.size();
        int new_size = 0;
        for(auto c : s) {
            if (c == ' ')
                new_size += 2;
            new_size += 1;
        }

        int old_end = old_size - 1;
        s.resize(new_size);
        new_size--;
        while(old_end >= 0)
        {
            if(s[old_end] == ' ')
            {
                s[new_size--] = '0';
                s[new_size--] = '2';
                s[new_size--] = '%';
            }
            else
            {
                s[new_size--] = s[old_end];   
            }

            old_end--;
        }

        return s;
    }
};

int main()
{
    string s = "we are happy.";
    auto so = Solution();
    cout << so.replaceSpace(s) << endl;
}