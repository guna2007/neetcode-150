#include<bits/stdc++.h>
class Solution {
public:

    map<pair<int,int>, int> dp;

    int solve(int i, vector<int>& nums, int target)
    {
        if(i == nums.size())
            return target == 0;

        if(dp.find({i,target}) != dp.end())
            return dp[{i,target}];

        return dp[{i,target}] =
            solve(i+1, nums, target - nums[i]) + solve(i+1, nums, target + nums[i]);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(0, nums, target);
    }
};