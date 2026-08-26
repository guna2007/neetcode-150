class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > sum) return 0;

        int off = sum;

        vector<vector<int>> dp(n + 1, vector<int>(2 * sum + 1, 0));

        dp[n][off] = 1;

        for(int i = n - 1; i >= 0; i--)
        {
            for(int t = -sum; t <= sum; t++)
            {
                if(t - nums[i] >= -sum)
                    dp[i][t + off] += dp[i + 1][t - nums[i] + off];

                if(t + nums[i] <= sum)
                    dp[i][t + off] += dp[i + 1][t + nums[i] + off];
            }
        }

        return dp[0][target + off];
    }
};