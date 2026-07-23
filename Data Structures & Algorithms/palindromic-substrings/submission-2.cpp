#include<bits/stdc++.h>

class Solution {
public:

    //memo
    int memo[1001][1001];

    int helper(string&s, int l,int r)
    {
        if(l >= r) return 1;

        if(memo[l][r] != -1) return memo[l][r];

        if(s[l] == s[r]) return memo[l][r] = helper(s,l+1,r-1);

        return memo[l][r] = 0;
    }

    int countSubstrings(string s) {

        int n = s.length();
        int cnt = 0;

        memset(memo,-1,sizeof(memo));

        for(int l = 0;l < n;l++)
        {
            for(int r = l;r < n;r++)
            {
                if(helper(s,l,r))
                {
                    cnt++;
                    
                }
            }
        }

        return cnt;
        
    }
};
