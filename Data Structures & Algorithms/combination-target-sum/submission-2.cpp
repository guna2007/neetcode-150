class Solution {
public:

    void helper(int idx,vector<int>& nums,vector<int>&temp,vector<vector<int>> &res,int target)
    {
        int n = nums.size();
        //bc
        if(target == 0)
        {
            res.push_back(temp);
            return;
        }

        if(target < 0 || idx == n) return;

        for(int i = idx;i < n;i++)
        {
            if(target - nums[i] < 0) return;
            //pick
            temp.push_back(nums[i]);
            helper(i,nums,temp,res,target-nums[i]);
            //backtract
            temp.pop_back();
        }
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        sort(nums.begin(),nums.end());
        helper(0,nums,temp,res,target);
        return res;
    }
};
