class Solution {
public:

    vector<vector<int>> dirs = {{1,0},{-1,0},{0,1},{0,-1}};

    int helper(int r,int c,vector<vector<int>>& matrix,vector<vector<int>>& dp,int preval)
    {
        int n = matrix.size();
        int m = matrix[0].size();

        if(r >= n || c >= m || r < 0 || c < 0 || matrix[r][c] <= preval) return 0;
        if(dp[r][c] != -1) return dp[r][c];

        int ans = 0;

        for(auto &v : dirs)
        {
            ans = max(ans,1 + helper(r+v[0],c+v[1],matrix,dp,matrix[r][c]));
        }
        return dp[r][c] = ans;
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        //memo
        int n = matrix.size();
        int m = matrix[0].size();

        vector<vector<int>> dp(n,vector<int>(m,-1));

        int ans = 0;

        for(int i = 0;i < n;i++)
        {
            for(int j = 0;j < m;j++)
            {
                ans = max(ans,helper(i,j,matrix,dp,-1));
            }
        }

        return ans;

    }
};