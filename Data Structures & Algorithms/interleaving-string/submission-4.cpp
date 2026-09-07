class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length();
        int m = s2.length();

        if(s3.length() != n+m) return false;

        vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));

        //bc
        dp[n][m] = true;

        for(int i = n;i >= 0;i--)
        {
            for(int j = m;j >= 0;j--)
            {
                int k = i+j;
                if(i < n && s1[i] == s3[k] && dp[i+1][j]) dp[i][j] = true;
                if(j < m && s2[j] == s3[k] && dp[i][j+1]) dp[i][j] = true;
            }
        }

        return dp[0][0];
    }
};