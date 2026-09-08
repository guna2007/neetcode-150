class Solution {
public:

    int numDistinct(string s, string t) {
        //tabulation
        int n = s.length();
        int m = t.length();

        vector<vector<int>> dp(n+1,vector<int>(m+1,0));

        //bc
        for(int i = 0;i <= n;i++)
            dp[i][m] = 1;

        for(int i = n-1;i >= 0;i--)
        {
            for(int j = m-1;j >= 0;j--)
            {
                //take
                if(s[i] == t[j])
                    dp[i][j] += dp[i+1][j+1];

                //skip
                dp[i][j] += dp[i+1][j];
            }
        }

        return dp[0][0];
    }
};