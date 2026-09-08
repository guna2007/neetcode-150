class Solution {
public:

    int helper(int i,int j,string& word1, string& word2,vector<vector<int>>& dp)
    {
        int n = word1.length();
        int m = word2.length();
        //bc
        if(i == n) return m - j;
        if(j == m) return n - i;
        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;

        if(word1[i] == word2[j]) ans = helper(i+1,j+1,word1,word2,dp);
        else 
        {
            ans =1 + min({helper(i+1,j,word1,word2,dp),helper(i,j+1,word1,word2,dp),helper(i+1,j+1,word1,word2,dp)});
        }

        return dp[i][j] = ans;

    }


    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return helper(0,0,word1,word2,dp);
    }
};