class Solution {
public:

    void helper(int idx,
                vector<int>& nums,
                vector<int>& temp,
                vector<vector<int>>& res,
                int target)
    {
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }

        for(int i = idx; i < nums.size(); i++)
        {
            // skip duplicates
            if(i > idx && nums[i] == nums[i-1])
                continue;

            // pruning
            if(nums[i] > target)
                break;

            temp.push_back(nums[i]);

            helper(i + 1, nums,
                   temp, res,
                   target - nums[i]);

            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& nums,
                                        int target) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> res;
        vector<int> temp;

        helper(0, nums, temp, res, target);

        return res;
    }
};