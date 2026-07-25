class Solution {
public:

    vector<int> dp;

    int helper(vector<int>& num, int k)
    {
        if(k == 0)
            return 0;

        if(dp[k] != -1)
            return dp[k];

        int ans = 1e9;

        for(auto i : num)
        {
            if(k - i < 0)
                continue;

            ans = min(ans, 1 + helper(num, k - i));
        }

        return dp[k] = ans;
    }

    int coinChange(vector<int>& num, int k)
    {
        dp.assign(k + 1, -1);

        int res = helper(num, k);

        return (res == 1e9) ? -1 : res;
    }
};