class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();

        unordered_set<string> dict(wordDict.begin(), wordDict.end());

        int maxlen = 0;

        for (string word : wordDict)
            maxlen = max(maxlen, (int) word.length());

        vector<bool> dp(n + 1, false);
        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) 
        {

            for (int len = 1; len <= maxlen && i + len <= n; len++) 
            {

                if (dp[i + len] && dict.count(s.substr(i, len))) 
                {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[0];
    }
};