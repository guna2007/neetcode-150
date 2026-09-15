class Solution {
public:

    int helper(vector<int>& nums,int l,int r,vector<vector<int>>&dp)
    {
        int n = nums.size();
        int ans = 0;

        if(dp[l][r] != -1) return dp[l][r];

        for(int i = l;i <= r;i++)
        {
            int curr = (nums[l-1] * nums[i] * nums[r+1]) + helper(nums,l,i-1,dp) + helper(nums,i+1,r,dp);
            ans = max(ans,curr);
        }

        return dp[l][r] = ans;
    }

    int maxCoins(vector<int>& num) {
        int n = num.size();
        
        
        vector<int> nums(n+2,1);
        for(int i = 0;i < n;i++)
        {
            nums[i+1] = num[i];
        }

        n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(nums,1,n-2,dp);
    }
};