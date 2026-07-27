class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curmin = 1, curmax = 1;

        for(auto &i : nums)
        {
            int curr = curmax * i;
            curmax = max({curr, curmin*i,i});
            curmin = min({curr,curmin*i,i});

            res = max(curmax,res);
        }
        return res;
    }
};
