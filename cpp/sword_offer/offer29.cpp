#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return {};

        vector<int> result;

        int rows = matrix.size();
        int cols = matrix[0].size();

        int start_row = 0;
        int start_col = 0;
        int end_rows = rows-1;
        int end_cols = cols-1;
        while (start_row <= end_rows) {
            int j = start_col;
            while (j <= end_cols) {
                result.push_back(matrix[start_row][j]);
                j += 1;
            }

            if (start_row + 1 > end_rows)
                break;

            int i = start_row + 1;
            while (i <= end_rows) {
                result.push_back(matrix[i][end_cols]);
                i+=1;
            }

            if (end_cols-1 < start_col)
                break;

            int j = end_cols - 1;
            while(j >= start_col) {
                result.push_back(matrix[end_rows][j]);
                j -= 1;
            }

            if (end_rows-1 <= start_row)
                break;

            int i = end_rows - 1;
            while(i > start_row) {
                result.push_back(matrix[i][start_col]);
                i -= 1;
            }

            start_row+=1;
            start_col+=1;
            end_rows-=1;
            end_cols-=1;
        }

        return result;
    }
};