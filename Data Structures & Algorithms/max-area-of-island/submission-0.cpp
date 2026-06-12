class Solution {
   public:
    vector<pair<int, int>> dirs = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int helper(int row, int col, vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        if (row < 0 || row >= m || col < 0 || col >= n || grid[row][col] != 1) {
            return 0;
        }

        int area = 1;
        grid[row][col] = 0;

        for (auto& dir : dirs) {
            int nrow = row + dir.first;
            int ncol = col + dir.second;

            area += helper(nrow, ncol, grid);
        }
        return area;
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {


        int m = grid.size();
        int n = grid[0].size();

        int ans = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    ans = max(ans,helper(i, j, grid));
                }
            }
        }

        return ans;
    }
};