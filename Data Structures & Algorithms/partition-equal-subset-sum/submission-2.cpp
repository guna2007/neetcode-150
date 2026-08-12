#include<bits/stdc++.h>
class Solution {
public:

    int dp[201][201];

    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = accumulate(nums.begin(),nums.end(),0);
        if(sum %2 != 0) return false;
        int target = sum/2;

        memset(dp, 0, sizeof(dp));

        //for t = 0
        for(int i = 0;i <= n;i++)
        {
            dp[i][0] = 1;
        }

        for(int i = n-1;i >= 0;i--)
        {
            for(int j = 1;j <= target;j++)
            {
                bool res = 0;
                if(nums[i] <= j)
                {
                    res = res | dp[i+1][j-nums[i]];
                }
                res = res | dp[i+1][j];

                dp[i][j] = res;
            }
        }

        return dp[0][target];

      
    }
};
