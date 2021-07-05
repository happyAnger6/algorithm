#include <string>
#include <vector>
#include <set>
#include <deque>
#include <utility>

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int s_size = word.size();
        if (s_size == 0)
            return true;

        if(board[0][0] != word[0])
            return false;

        for(int row = 0; row < rows; row++)
            for(int col = 0; col < cols; col++) {
                if (board[row][col] == word[0]) {
                    bool ret = bfs(board, row, col, word);
                    if(ret)
                        return true;
                }
            }

        return false;
    }

    bool bfs(vector<vecotr<char>> &board, int x, int y, string word)
    {
        int i = 1;
        int rows = board.size();
        int cols = board[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        deque<pair<int, int>> q;
        set<pair<int, int>> seen;
        seen.insert({x, y});
        q.push_back({x, y});

        while (!q.empty()) {
            int n = q.size();
            if (i == word.size())
                return true;

            char c = word[i];
            while (n > 0) {
                n -= 1;
                auto pos = q.front();
                int x = pos.first;
                int y = pos.second;
                q.pop_front();
                for(auto dir_ : dirs) {
                    int dir_x = dir_.first;
                    int dir_y = dir_.second;
                    int next_x = x + dir_x;
                    int next_y = y + dir_y;
                    if (next_x < 0 || next_x >= rows)
                        continue;
                    
                    if (next_y < 0 || next_y >= cols)
                        continue;

                    if(seen.find({next_x, next_y}) != seen.end())
                        continue;

                    if(board[next_x][next_y] != c)
                        continue;

                    seen.insert({next_x, next_y});
                    q.push_back({next_x, next_y});
                }
            }
        }
    }
};