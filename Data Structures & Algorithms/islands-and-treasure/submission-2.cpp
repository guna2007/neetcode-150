class Solution {
public:

    int INF =2147483647;
    queue<pair<int,int>> que;
    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};


    void helper(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        int currdist = 0;

         while(!que.empty())
        {
            int sz = que.size();

            while(sz--)
            {
                auto [i,j] = que.front();
                que.pop();

                for(auto &d : dirs)
                {
                    int nr = i + d[0];
                    int nc = j + d[1];

                    if(nr < 0 || nr >= n || nc < 0 || nc >= m)
                        continue;

                    if(grid[nr][nc] == -1 || grid[nr][nc] == 0)
                        continue;

                    if(currdist + 1 >= grid[nr][nc])
                        continue;

                    grid[nr][nc] = currdist + 1;
                    que.push({nr,nc});
                }
            }

            currdist++;
        }
    }

    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 0)
                {
                    while(!que.empty()) que.pop();
                    que.push({i,j});
                    helper(grid);
                }
            }
        }

    }
};
