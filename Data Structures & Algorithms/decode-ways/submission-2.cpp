class Solution {
public:

    vector<int> dp;

    int helper(string &s, int i)
    {
        int n = s.length();

        // base case
        if(i == n)
            return 1;

        if(s[i] == '0')
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int ways = 0;

        // single digit
        ways += helper(s, i + 1);

        // double digit
        if(i + 1 < n)
        {
            int num = (s[i]-'0')*10 + (s[i+1]-'0');

            if(num >= 10 && num <= 26)
                ways += helper(s, i + 2);
        }

        return dp[i] = ways;
    }

    int numDecodings(string s) {

        dp.assign(s.length(), -1);

        return helper(s, 0);
    }
};