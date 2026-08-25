class Solution {
public:

    int helper(int idx,int amount,vector<int>& coins,vector<vector<int>>&dp)
    {
        //bc
        if(amount == 0) return 1;
        if(idx == coins.size()) return 0;
        if(dp[idx][amount] != -1) return dp[idx][amount];

        int ans = 0;
        //pick
        if(amount - coins[idx] >= 0) ans += helper(idx,amount - coins[idx],coins,dp);
        //not pick 
        ans += helper(idx+1,amount,coins,dp);

        return dp[idx][amount] = ans;
    }

    int change(int amount, vector<int>& coins) {
        vector<vector<int>> dp(coins.size(),vector<int>(amount+1,-1));
        return helper(0, amount,coins,dp);
    }
};