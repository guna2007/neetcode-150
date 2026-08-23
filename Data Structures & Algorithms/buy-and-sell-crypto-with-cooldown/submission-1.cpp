class Solution {
public:

    int helper(int i,int canbuy,vector<int>& prices,vector<vector<int>>& dp)
    {
        //bc
        if(i >= prices.size()) return 0;
        //memo
        if(dp[i][canbuy] != -1) return dp[i][canbuy];

        int ans;
        if(canbuy)
        {
            ans =  max((helper(i+1,0,prices,dp)-prices[i]),helper(i+1,1,prices,dp));
        }
        else
        {
            ans =  max((helper(i+2,1,prices,dp)+prices[i]),helper(i+1,0,prices,dp));
        }

        return dp[i][canbuy] = ans;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
};