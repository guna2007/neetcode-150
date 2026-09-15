class Solution {
public:

    int maxCoins(vector<int>& num) {
        int n = num.size();
        
        vector<int> nums(n+2,1);
        for(int i = 0;i < n;i++)
        {
            nums[i+1] = num[i];
        }

        n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,0));

        for(int l = n-2;l >= 1;l--)
        {
            for(int r = l;r <= n-2;r++)
            {
                int ans = 0;

                for(int i = l;i <= r;i++)
                {
                    int curr = (nums[l-1] * nums[i] * nums[r+1]) + dp[l][i-1] + dp[i+1][r];
                    ans = max(ans,curr);
                }

                dp[l][r] = ans;
            }
        }

        return dp[1][n-2];
    }
};