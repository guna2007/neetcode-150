class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0];
        int curmin = 1, curmax = 1;

        for (auto& i : nums) {
            int curr = curmin * i;

            curmin = min({curr, curmax * i, i});
            curmax = max({curr, curmax * i, i});

            res = max(curmax, res);
        }
        return res;
    }
};
