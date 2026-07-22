#include<bits/stdc++.h>

class Solution {
public:

    int memo[1001][1001];

    int helper(string &s, int i, int j)
    {
        if (i > j)
            return 1;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] != s[j])
            return memo[i][j] = 0;

        return memo[i][j] = helper(s, i + 1, j - 1);
    }

    string longestPalindrome(string s) {

        int n = s.length();

        memset(memo, -1, sizeof(memo));

        int idx = 0;
        int len = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = i; j < n; j++)
            {
                if (helper(s, i, j))
                {
                    if (j - i + 1 > len)
                    {
                        idx = i;
                        len = j - i + 1;
                    }
                }
            }
        }

        return s.substr(idx,len);
    }
};