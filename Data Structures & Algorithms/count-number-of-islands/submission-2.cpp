class Solution {
public:

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(int i,int j,vector<vector<char>>& grid)
    {
        //bc
        if(i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] != '1') return;

        grid[i][j] = '0';
        
        for(int a = 0;a < 4;a++)
        {
            int nr = i + dirs[a][0];
            int nc = j + dirs[a][1];

            dfs(nr,nc,grid);

        }
    }

    int numIslands(vector<vector<char>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;

         for(int i = 0;i < n;i++)
         {
            for(int j = 0;j < m;j++)
            {
                if(grid[i][j] == '1')
                {
                    ans++;
                    dfs(i,j,grid);
                }
            }
         }

         return ans;

    }
};
