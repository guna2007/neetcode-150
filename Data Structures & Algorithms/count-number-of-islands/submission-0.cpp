class Solution {
   public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void helper(int row, int col, vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != '1') {
            return;
        }

        grid[row][col] = '#';

        for (auto& dir : dirs) {
            int nrow = row + dir.first;
            int ncol = col + dir.second;

            helper(nrow, ncol, grid);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        // helper func (row,col,grid)dfs based approach
        // which makes this to '#' and move to neigh by for loop of dirs array
        // in this func 2d loop for checking if 1s and cnt++, call helper which makes them '#'
        // and then return cnt at end

        int m = grid.size();
        int n = grid[0].size();

        int cnt = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') {
                    cnt++;
                    helper(i, j, grid);
                }
            }
        }

        return cnt;
    }
};