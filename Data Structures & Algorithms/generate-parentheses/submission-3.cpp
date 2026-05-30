class Solution {
public:

    vector<string> generateParenthesis(int n) {

        vector<vector<string>> dp(n + 1);

        //bc
        dp[0] = {""};

        for(int k = 1; k <= n; k++)
        {
            //left part size
            for(int i = 0; i < k; i++)
            {
                //all left strings
                for(string left : dp[i])
                {
                    //all right strings
                    for(string right : dp[k - i - 1])
                    {
                        dp[k].push_back("(" + left + ")" + right);
                    }
                }
            }
        }

        return dp[n];
    }
};