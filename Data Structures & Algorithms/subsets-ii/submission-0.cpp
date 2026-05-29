class Solution {
public:

    void helper(int idx,vector<int>& nums,vector<int>& temp,vector<vector<int>> &res,int n)
    {
        res.push_back(temp);

        for(int i = idx;i < n;i++)
        {
            if(i > idx && nums[i] == nums[i-1]) continue;
            temp.push_back(nums[i]);
            helper(i+1,nums,temp,res,n);
            temp.pop_back();
        }


    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        vector<int> temp;
        int n = nums.size();
        helper(0,nums,temp,res,n);
        return res;
    }
};
