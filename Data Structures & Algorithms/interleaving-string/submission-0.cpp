#include<bits/stdc++.h>
class Solution {
public:

    int dp[201][201];

    bool helper(int i, int j, string& s1, string& s2, string& s3)
    {
        if(i + j == s3.length())
        {
            return (i == s1.length() && j == s2.length());
        }

        if(dp[i][j] != -1)
            return dp[i][j];

        bool ans = false;

        if(i < s1.length() && s1[i] == s3[i+j])
            ans |= helper(i+1, j, s1, s2, s3);

        if(j < s2.length() && s2[j] == s3[i+j])
            ans |= helper(i, j+1, s1, s2, s3);

        return dp[i][j] = ans;
    }

    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s1.length() + s2.length() != s3.length())
            return false;

        memset(dp, -1, sizeof(dp));

        return helper(0, 0, s1, s2, s3);
    }
};