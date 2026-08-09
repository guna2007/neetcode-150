class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {

        int n = s.length();

        vector<bool> dp(n + 1, false);

        dp[n] = true;

        for (int i = n - 1; i >= 0; i--) {

            for (string word : wordDict) {

                // enough characters?
                if (word.length() <= n-i) 
                {

                    // does word match s starting at i?
                    if (s.substr(i,word.length()) == word) 
                    {

                        // does the remaining suffix work?
                        if (dp[i+word.length()]) 
                        {
                            dp[i] = true;
                            break;
                        }
                    }
                }
            }
        }

        return dp[0];
    }
};