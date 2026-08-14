class Solution {
public:
    int helper(int r, int c, int n, int m,vector<vector<int>>&dp) {
        if(r == n-1 && c == m-1)
            return 1;

        if(r >= n || c >= m)
            return 0;

        if(dp[r][c] != -1)
            return dp[r][c];

        return dp[r][c] = helper(r+1, c, n, m,dp) + helper(r, c+1, n, m,dp);
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return helper(0, 0, m, n,dp);
    }
};