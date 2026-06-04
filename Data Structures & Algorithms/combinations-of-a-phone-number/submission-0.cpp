class Solution {
public:

    void helper(int digi, vector<vector<char>>& grid, string& temp, vector<string>& res)
    {
        // bc
        if(digi == grid.size())
        {
            res.push_back(temp);
            return;
        }

        for(int idx = 0; idx < grid[digi].size(); idx++)
        {
            temp.push_back(grid[digi][idx]);

            helper(digi + 1, grid, temp, res);

            temp.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        //my logic is to firrst store in mp of int->vec chars
        //then another 2d vec named grid whihc stores vec of chars of present in digits

        //now helper func digi(for which dig index),idx(for among 3 vec chars),temp,res
        //bc if digi == len then push
        //backtrack in loop of 3

        if(digits.size() == 0)
        {
            return {};
        }

        unordered_map<int, vector<char>> mp;

        mp[2] = {'a','b','c'};
        mp[3] = {'d','e','f'};
        mp[4] = {'g','h','i'};
        mp[5] = {'j','k','l'};
        mp[6] = {'m','n','o'};
        mp[7] = {'p','q','r','s'};
        mp[8] = {'t','u','v'};
        mp[9] = {'w','x','y','z'};

        vector<vector<char>> grid;

        for(char ch : digits)
        {
            grid.push_back(mp[ch - '0']);
        }

        string temp;
        vector<string> res;

        helper(0, grid, temp, res);

        return res;
    }
};