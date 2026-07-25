class Solution {
public:


    int coinChange(vector<int>& num, int k)
    {
        int n = num.size();
        vector<int> dp(k+1,1e9);
        dp[0] = 0;

        for(int t = 1;t <= k;t++)
        {
            for(auto i : num)
            {
                if(t - i < 0)
                    continue;

                dp[t] = min(dp[t], 1 + dp[t-i]);
            }
        }

        int res = dp[k];
        return (res == 1e9) ? -1 : res;
    }
};