class Solution {
public:

    void helper(int i,string& s,
                vector<string>& temp,
                vector<vector<string>>& res,
                vector<vector<bool>>& dp)
    {
        if(i == s.length())
        {
            res.push_back(temp);
            return;
        }

        for(int j = i; j < s.length(); j++)
        {
            if(dp[i][j])
            {
                temp.push_back(s.substr(i,j-i+1));

                helper(j+1,s,temp,res,dp);

                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {

        int n = s.length();

        vector<vector<bool>> dp(n,vector<bool>(n,false));

        //fill dp
        for(int i = n-1; i >= 0; i--)
        {
            for(int j = i; j < n; j++)
            {
                if(s[i] == s[j])
                {
                    if(j-i <= 2 || dp[i+1][j-1])
                    {
                        dp[i][j] = true;
                    }
                }
            }
        }

        vector<vector<string>> res;
        vector<string> temp;

        helper(0,s,temp,res,dp);

        return res;
    }
};