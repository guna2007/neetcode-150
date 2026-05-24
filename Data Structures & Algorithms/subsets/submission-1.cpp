class Solution {
public:

    void helper(int idx,vector<int>& nums,vector<int>& temp,vector<vector<int>> &res,int n)
    {
        res.push_back(temp);

        for(int i = idx;i < n;i++)
        {
            temp.push_back(nums[i]);
            helper(i+1,nums,temp,res,n);
            temp.pop_back();
        }


    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        helper(0,nums,temp,res,n);
        return res;
    }
};
