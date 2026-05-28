class Solution {
public:

    void helper(int idx,vector<int>& nums,vector<int>& temp,vector<vector<int>>&res)
    {
        int n = nums.size();
        //bc

        if(idx == n)
        {
            res.push_back(temp);
        }


        for(int i = idx;i < n;i++)
        {
            swap(temp[i],temp[idx]);
            helper(idx+1,nums,temp,res);
            swap(temp[i],temp[idx]);
        }
    }


    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> temp(nums.begin(),nums.end());
        helper(0,nums,temp,res);
        return res;
    }
};
