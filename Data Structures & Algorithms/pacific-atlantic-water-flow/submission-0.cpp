class Solution {
public:
    vector<pair<int,int>> dirs = {{-1,0},{1,0},{0,-1},{0,1}};

    void dfs(int row,int col,vector<vector<int>>& heights,
             vector<vector<bool>>& vis)
    {
        int m = heights.size();
        int n = heights[0].size();

        vis[row][col] = true;

        for(auto [dr,dc] : dirs)
        {
            int nr = row + dr;
            int nc = col + dc;

            if(nr >= 0 && nr < m &&
               nc >= 0 && nc < n &&
               !vis[nr][nc] &&
               heights[nr][nc] >= heights[row][col])
            {
                dfs(nr,nc,heights,vis);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        int m = heights.size();
        int n = heights[0].size();

        vector<vector<bool>> pacific(m,vector<bool>(n,false));
        vector<vector<bool>> atlantic(m,vector<bool>(n,false));

        // Pacific: top row
        for(int j=0;j<n;j++)
        {
            dfs(0,j,heights,pacific);
        }

        // Pacific: left col
        for(int i=0;i<m;i++)
        {
            dfs(i,0,heights,pacific);
        }

        // Atlantic: bottom row
        for(int j=0;j<n;j++)
        {
            dfs(m-1,j,heights,atlantic);
        }

        // Atlantic: right col
        for(int i=0;i<m;i++)
        {
            dfs(i,n-1,heights,atlantic);
        }

        vector<vector<int>> ans;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(pacific[i][j] && atlantic[i][j])
                {
                    ans.push_back({i,j});
                }
            }
        }

        return ans;
    }
};