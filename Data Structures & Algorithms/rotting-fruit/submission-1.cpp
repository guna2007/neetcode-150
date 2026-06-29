class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int ans = 0;

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 1)
                {
                    fresh++;
                }
                if(grid[i][j] == 2)
                {
                    q.push({i,j});
                }
            }
        }

        if(fresh == 0) return 0;

        while(!q.empty())
        {
            //level order
            int size = q.size();
            while(size--)
            {
                auto [i,j] = q.front();
                q.pop();

                for(auto &v : dirs)
                {
                    int nr = i + v[0];
                    int nc = j + v[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m) continue;

                    if(grid[nr][nc] == 1)
                    {
                        q.push({nr,nc});
                        grid[nr][nc] = 2;
                        fresh--;
                    }
                }
            }

            ans++;
            if(fresh == 0) return ans;
        }

        return -1;
    }
};