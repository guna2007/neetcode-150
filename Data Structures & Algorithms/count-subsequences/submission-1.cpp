class Solution {
public:

    int helper(int i,int j,string& s, string& t,vector<vector<int>>& dp)
    {
        int n = s.length();
        int m = t.length();

        //bc
        if(j == m) return 1;
        if(i == n) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        //take
        if(s[i] == t[j]) ans += helper(i+1,j+1,s,t,dp);

        ans += helper(i+1,j,s,t,dp);

        return dp[i][j] = ans;
    }

    int numDistinct(string s, string t) {
        //i thought in suffix dp
        int n = s.length();
        int m = t.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(0,0,s,t,dp);
    }
};
