class Solution {
public:

    void helper(vector<int>& nums,
                vector<int>& temp,
                vector<int>& vis,
                vector<vector<int>>& res)
    {
        // bc
        if(temp.size() == nums.size())
        {
            res.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++)
        {
            // already
            if(vis[i]) continue;

            vis[i] = 1;
            temp.push_back(nums[i]);

            helper(nums, temp, vis, res);

            // backtrack
            temp.pop_back();
            vis[i] = 0;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>> res;

        vector<int> temp;

        vector<int> vis(nums.size(), 0);

        helper(nums, temp, vis, res);

        return res;
    }
};