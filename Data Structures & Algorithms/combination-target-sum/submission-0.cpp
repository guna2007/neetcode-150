class Solution {
public:

    void helper(int idx,
                vector<int>& candidates,
                int target,
                vector<int>& temp,
                vector<vector<int>>& res)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }

        if(target < 0)
            return;

        for(int i = idx; i < candidates.size(); i++)
        {
            temp.push_back(candidates[i]);

            // i not i+1 because reuse allowed
            helper(i, candidates,
                   target - candidates[i],
                   temp, res);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates,
                                       int target) {

        vector<vector<int>> res;
        vector<int> temp;

        helper(0, candidates, target, temp, res);

        return res;
    }
};