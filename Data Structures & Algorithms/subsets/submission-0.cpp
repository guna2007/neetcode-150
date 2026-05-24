class Solution {
public:

    void helper(int i,vector<int>& nums,vector<int>& temp,vector<vector<int>> &res,int n)
    {
        if(i == n)
        {
            res.push_back(temp);
            return;
        }

        //pick
        temp.push_back(nums[i]);
        helper(i+1,nums,temp,res,n);
        //not pick
        temp.pop_back();
        helper(i+1,nums,temp,res,n);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp;
        int n = nums.size();
        helper(0,nums,temp,res,n);
        return res;
    }
};
