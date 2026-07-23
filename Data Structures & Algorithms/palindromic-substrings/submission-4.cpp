#include <bits/stdc++.h>

class Solution {
   public:
    int countSubstrings(string s) {
        // tabulation dp
        int n = s.length();
        int dp[1001][1001];

        int cnt = 0;

        memset(dp, 0, sizeof(dp));

        for (int l = n - 1; l >= 0; l--) 
        {
            for (int r = l; r < n; r++) 
            {
                if (s[l] == s[r]) 
                {
                    if (r - l <= 1)
                        dp[l][r] = 1;
                    else
                        dp[l][r] = dp[l + 1][r - 1];
                }
                if (dp[l][r]) cnt++;
            }
        }

        return cnt;
    }
};
