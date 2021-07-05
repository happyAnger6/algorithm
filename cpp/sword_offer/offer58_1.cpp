#include <string>

using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string new_s;
        int end = s.size() - 1;
        char sep = '';
        while (end >= 0) {
            int right = -1;
            while (end >= 0) {
                if (s[end] != ' ') {
                    right = end;
                    end--;
                    break;
                }
                end--;
            }

            if (right == -1)
                break;

            int left = end;
            end--;
            while (end >= 0) {
                if (s[end] == ' ') {
                    break;
                }
                left--;
                end--;
            }

            new_s.append(s.substr(left, right-left+1));
            new_s.push_back(sep);
            sep = ' ';
        }
        return new_s;
    }
};