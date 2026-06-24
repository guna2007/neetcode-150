class Solution {
public:

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        //bc
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != 1) return 0;

        grid[i][j] = 0;
        int area = 1;
        
        for(int a = 0;a < 4;a++)
        {
            int nr = i + dirs[a][0];
            int nc = j + dirs[a][1];

            area += dfs(nr,nc,grid);

        }
        return area;
        
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

         for(int i = 0;i < n;i++)
         {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == 1)
                {
                    ans = max(ans,dfs(i,j,grid));
                }
            }
         }

         return ans;

    }
};
