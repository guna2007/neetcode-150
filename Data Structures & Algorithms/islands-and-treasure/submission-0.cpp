class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    void bfs(int row, int col, vector<vector<int>>& grid)
    {
        int m = grid.size();
        int n = grid[0].size();

        queue<pair<pair<int,int>,int>> q;

        // push all neighs of 0 with distance 1
        for(auto [dr,dc] : dirs)
        {
            int nr = row + dr;
            int nc = col + dc;

            if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
               grid[nr][nc] > 1)
            {
                q.push({{nr,nc},1});
            }
        }

        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();

            int r = curr.first.first;
            int c = curr.first.second;
            int dist = curr.second;

            // use min of curr dist and curr val
            grid[r][c] = min(grid[r][c], dist);

            for(auto [dr,dc] : dirs)
            {
                int nr = r + dr;
                int nc = c + dc;

                if(nr >= 0 && nr < m && nc >= 0 && nc < n &&
                   dist + 1 < grid[nr][nc])
                {
                    q.push({{nr,nc},dist + 1});
                }
            }
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        //logic is in this func 2d loop and check for 0s
        //once 0 found we will call bfs like level order traversal tracking distance
        // my logic is to push all neighs of 0 with inf into queue and push into grid with tracked
        //distance, then for other layers etc../
        //repeat for other 0s but when assigning val in grid use min of curr dist and curr val

        int m = grid.size();
        int n = grid[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j] == 0)
                {
                    bfs(i,j,grid);
                }
            }
        }
    }
};