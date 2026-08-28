
#include<bits/stdc++.h>
class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > sum) return 0;
        if((target + sum) % 2 != 0) return 0;

        int s = (target + sum) / 2;

        vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));

        // With no elements, only sum 0 is possible
        dp[n][0] = 1;

        for(int i = n-1; i >= 0; i--)
        {
            for(int j = 0; j <= s; j++)
            {
                // Don't take nums[i]
                dp[i][j] = dp[i+1][j];


                // Take nums[i]
                if(nums[i] <= j)
                {
                    dp[i][j] += dp[i+1][j-nums[i]];
                }
            }
        }

        return dp[0][s];
    }
};