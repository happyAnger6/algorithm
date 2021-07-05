#include <vector>

using namespace std;

class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;

        int rows, cols = matrix.size(), matrix[0].size();
        int row = 0, col = cols - 1;
        while(row < rows && col >= 0) {
            if (matrix[row][col] == target)
                return true;
            else if (matrix[row][col] > target)
                col -= 1;
            else
                row += 1;
        }

        return false;
    }
};