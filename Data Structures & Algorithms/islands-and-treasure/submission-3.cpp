class Solution {
public:

    int INF = 2147483647;
    queue<pair<int,int>> que;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void islandsAndTreasure(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        // Push every gate
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] == 0)
                    que.push({i,j});
            }
        }

        while(!que.empty())
        {
            auto [i,j] = que.front();
            que.pop();

            for(auto &d : dirs)
            {
                int nr = i + d[0];
                int nc = j + d[1];

                if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                    continue;

                // Only visit unprocessed rooms
                if(grid[nr][nc] != INF)
                    continue;

                grid[nr][nc] = grid[i][j] + 1;
                que.push({nr,nc});
            }
        }
    }
};